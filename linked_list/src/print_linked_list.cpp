#include <bits/stdc++.h>
using namespace std;

class SingleLinkedListNode {
public:
  int data;
  SingleLinkedListNode *next;
  SingleLinkedListNode(int a) {
    this->data = a;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
public:
  SingleLinkedListNode *head;
  SingleLinkedListNode *tail;

  SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    SingleLinkedListNode *node = new SingleLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
    }

    this->tail = node;
  }
};

void free_singly_linked_list(SingleLinkedListNode *node) {
  while (node) {
    SingleLinkedListNode *temp = node;
    node = node->next;

    free(temp);
  }
}

void printLinkedList(SingleLinkedListNode *head) {
  SingleLinkedListNode *node = head;
  while (node) {
    cout << node->data << "\n";
    node = node->next;
  }
}

int main() {
  SinglyLinkedList *llist = new SinglyLinkedList();
  int llist_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int i = 0; i < llist_count; i++) {
    int llist_item;
    cin >> llist_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    llist->insert_node(llist_item);
  }
  printLinkedList(llist->head);
  return 0;
}
