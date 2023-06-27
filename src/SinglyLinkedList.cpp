/**
 * Author: Gieun Jeong
 * Last Update: June 27, 2023
 */
#include <iostream>
using namespace std;

class Node {
  public:
    /* Fields */
    Node *next;
    int data;

    /* Construtor */
    Node() {
        data = 0;
        next = NULL;
    }

    Node(int num) {
        data = num;
        next = NULL;
    }
};

/**
 * Singly Linked List,
 * which is most simplest way to implement list structure.
 */
class LinkedList {
  public:
    /* Fields */
    Node *head;
    Node *tail;
    int size;

    /* Constructor */
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /* Methods */
    void pushFront(int num) {
        Node *newNode = new Node(num);
        size++;

        /* Check if list is empty. */
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pushBack(int num) {
        Node *newNode = new Node(num);
        size++;

        /* Check if list is empty. */
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void printList() {
        Node *iter = head;
        while (iter != NULL) {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }

    void popFront() {
        /* Check if list is empty. */
        if (head == NULL) {
            cout << "Wrong action. list is empty." << endl;
            return;
        }

        Node *cur = head;
        head = head->next;
        size--;

        if (head == NULL) {
            tail = NULL;
        }

        delete cur;
    }

    void popBack() {
        /* Check if list is empty. */
        if (head == NULL) {
            cout << "Wrong action. list is empty." << endl;
            return;
        }

        if (size == 1) {
            this->popFront();
            return;
        }

        Node *prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }

        Node *cur = tail;
        tail = prev;
        tail->next = NULL;
        size--;

        delete cur;
    }

    void push(int pos, int num) {
        if (pos == 0) {
            pushFront(num);
            return;
        }
        if (pos == size - 1) {
            pushBack(num);
            return;
        }

        /* invalid position. */
        if (pos >= size) {
            cout << "position value should be less than size." << endl;
            return;
        }

        Node *newNode = new Node(num);
        size++;

        Node *prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }

        newNode->next = prev->next;
        prev->next = newNode;
    }

    void pop(int pos) {
        /* Check if list is empty. */
        if (head == NULL) {
            cout << "Wrong action. list is empty." << endl;
            return;
        }

        if (size == 1) {
            popFront();
            return;
        }

        if (pos == 0) {
            popFront();
            return;
        }

        if (pos == size - 1) {
            popBack();
            return;
        }

        Node *prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }

        Node *cur = prev->next;
        prev->next = cur->next;
        size--;

        delete cur;
    }

    int getSize() { return size; }
};

int main() {
    LinkedList list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    list.pushFront(4);
    list.printList();
    list.push(1, 9);
    list.printList();
    list.pop(2);
    list.printList();
    return 0;
}