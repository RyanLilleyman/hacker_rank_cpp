#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int d) {
    this->data = d;
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
      return root;
    }
  }

  void postOrder(Node *root) {
    class toPush {
    public:
      vector<int> toPrint;
      void printVector() {
        int n = this->toPrint.size();
        for (int i = n; i > 0; i--) {
          cout << toPrint[i] << " ";
        }
      }
      void pushData(Node *root) {
        if (root) {
          toPrint.push_back(root->data);
          pushData(root->right);
          pushData(root->left);
        }
      }
    };
    toPush vector;
    vector.pushData(root);
    vector.printVector();
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
