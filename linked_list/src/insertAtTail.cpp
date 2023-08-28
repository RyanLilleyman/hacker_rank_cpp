#include <bits/stdc++.h>
#include <cinttypes>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
public:
  int data;
  SinglyLinkedListNode *next;

  SinglyLinkedListNode(int nodeData) {
    this->data = nodeData;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
public:
  SinglyLinkedListNode *head;

  SinglyLinkedList() { this->head = nullptr; }
};

void printSinglyLinkedList(SinglyLinkedListNode *node, string sep,
                           ofstream &fout) {
  while (node) {
    fout << node->data;

    node = node->next;

    if (node) {
      fout << sep;
    }
  }
}

void freeSinglyLinkedList(SinglyLinkedListNode *node) {
  while (node) {
    SinglyLinkedListNode *temp = node;
    node = node->next;
    free(temp);
  }
}

// Complete the insertNodeAtTail function belos.

/*
 * For your reference:
 *
 * SinglyLinkedListNode{
 * int data;
 * SinglyLinkedListNode* next;
 * }
 */

SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data) {
  SinglyLinkedListNode *tail = new SinglyLinkedListNode(data);
  if (!head) {
    head = tail;
    return head;
  } else {
    SinglyLinkedListNode *node = head;
    while (node) {
      if (!node->next) {
        node->next = tail;
        return head;
      }
      node = node->next;
    }
    return head;
  }
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));
  SinglyLinkedList *llist = new SinglyLinkedList();

  int llist_count;
  cin >> llist_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < llist_count; i++) {
    int llist_item;
    cin >> llist_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode *llist_head =
        insertNodeAtTail(llist->head, llist_item);
    llist->head = llist_head;
  }

  printSinglyLinkedList(llist->head, "\n", fout);
  fout << "\n";

  freeSinglyLinkedList(llist->head);
  fout.close();

  return 0;
}
