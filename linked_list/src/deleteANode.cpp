#include <bits/stdc++.h>
#include <fstream>
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
  SinglyLinkedListNode *tail;

  SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insertNode(int data) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
    }
    this->tail = node;
  }
};

void printSinglyLinkedList(SinglyLinkedListNode *head, string sep,
                           ofstream &fout) {
  SinglyLinkedListNode *node = head;
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

/*
 * Complete the 'deleteNode' function below.
 *
 * the function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * the function accepts the following parameters:
 * 1.integerSinglyLinkedList llist
 * 2.integer position
 */
/*
 * For your reference:
 *
 * SinglyLinkedListNode{
 * int data;
 * SinglyLInkedListNode* next;
 * };
 */

SinglyLinkedListNode *deleteNode(SinglyLinkedListNode *llist, int position) {
  int count = 0;
  SinglyLinkedListNode *node = llist;
  SinglyLinkedListNode *previous;
  while (node) {
    if (position == 0) {
      SinglyLinkedListNode *newHead = node->next;
      free(node);
      return newHead;
    }
    if (count == (position)) {
      previous->next = node->next;

      free(node);
      break;
    }
    previous = node;
    node = node->next;
    count += 1;
  }
  return llist;
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

    llist->insertNode(llist_item);
  }

  int position;
  cin >> position;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  SinglyLinkedListNode *llist1 = deleteNode(llist->head, position);

  printSinglyLinkedList(llist1, " ", fout);
  fout << "\n";

  freeSinglyLinkedList(llist1);

  fout.close();

  return 0;
}
