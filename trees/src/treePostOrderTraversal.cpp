#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Node {
public:
  Node *right;
  Node *left;
  int data;

  Node(int node_data) {
    this->data = node_data;
    this->left = NULL;
    this->right = NULL;
  }
};

class Solution {
public:
  Node *insert(Node *root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node *cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }
    }
    return root;
  }
  void postOrder(Node *root) {
    if (root) {
      postOrder(root->left);
      postOrder(root->right);
      cout << root->data << " ";
    }
  }
};

int main() {

  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.postOrder(root);

  return 0;
}
