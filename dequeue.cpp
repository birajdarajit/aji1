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

class Dequeue {
 public:
  Node* front;
  Node* rear;

  Dequeue() {
    front = rear = nullptr;
  }

  void addFront(int data) {
    Node* newNode = new Node(data);
    if (front == nullptr) {
      front = rear = newNode;
      return;
    }
    newNode->next = front;
    front->prev = newNode;
    front = newNode;
  }

  void addRear(int data) {
    Node* newNode = new Node(data);
    if (rear == nullptr) {
      front = rear = newNode;
      return;
    }
    newNode->prev = rear;
    rear->next = newNode;
    rear = newNode;
  }

  int removeFront() {
    if (front == nullptr) {
      std::cout << "Dequeue is empty" << std::endl;
      return -1;
    }
    Node* temp = front;
    int item = temp->data;
    front = front->next;
    if (front == nullptr) {
      rear = nullptr;
    } else {
      front->prev = nullptr;
    }
    delete temp;
    return item;
  }

  int removeRear() {
    if (rear == nullptr) {
      std::cout << "Dequeue is empty" << std::endl;
      return -1;
    }
    Node* temp = rear;
    int item = temp->data;
    rear = rear->prev;
    if (rear == nullptr) {
      front = nullptr;
    } else {
      rear->next = nullptr;
    }
    delete temp;
    return item;
  }

  bool isEmpty() {
    return (front == nullptr);
  }
};

int main() {
  Dequeue dq;
  dq.addFront(1);
  dq.addRear(2);
  dq.addFront(3);
  dq.addRear(4);
  while (!dq.isEmpty()) {
    std::cout << dq.removeRear() << " ";
  }
  std::cout << std::endl;
  return 0;
}
