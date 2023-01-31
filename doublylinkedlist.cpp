#include <iostream>

class Node {
 public:
  int data;
  Node* prev;
  Node* next;

  Node(int data) {
    this->data = data;
    prev = next = nullptr;
  }
};

class DoublyLinkedList {
 public:
  Node* head;

  DoublyLinkedList() {
    head = nullptr;
  }

  void insertAtHead(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != nullptr) {
      head->prev = newNode;
    }
    head = newNode;
  }

  void insertAtTail(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
  }

  void insertAfter(Node* prevNode, int data) {
    if (prevNode == nullptr) {
      std::cout << "Previous node cannot be null" << std::endl;
      return;
    }
    Node* newNode = new Node(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next != nullptr) {
      newNode->next->prev = newNode;
    }
  }

  void deleteNode(int key) {
    Node* current = head;
    while (current != nullptr && current->data != key) {
      current = current->next;
    }
    if (current == nullptr) {
      std::cout << "Key not found in the list" << std::endl;
      return;
    }
    if (current->prev != nullptr) {
      current->prev->next = current->next;
    }
    if (current->next != nullptr) {
      current->next->prev = current->prev;
    }
    if (current == head) {
      head = current->next;
    }
    delete current;
  }

  void printList() {
    Node* current = head;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  DoublyLinkedList dll;
  dll.insertAtHead(1);
  dll.insertAtHead(2);
  dll.insertAtTail(3);
  dll.insertAfter(dll.head, 4);
  dll.deleteNode(2);
  dll.printList();
  return 0;
}
