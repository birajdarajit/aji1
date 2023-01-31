#include <iostream>

class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class Queue {
 public:
  Node* front;
  Node* rear;

  Queue() {
    front = rear = nullptr;
  }

  void enqueue(int data) {
    Node* newNode = new Node(data);
    if (rear == nullptr) {
      front = rear = newNode;
      return;
    }
    rear->next = newNode;
    rear = newNode;
  }

  int dequeue() {
    if (front == nullptr) {
      std::cout << "Queue is empty" << std::endl;
      return -1;
    }
    Node* temp = front;
    int item = temp->data;
    front = front->next;
    if (front == nullptr) {
      rear = nullptr;
    }
    delete temp;
    return item;
  }

  bool isEmpty() {
    return (front == nullptr);
  }
};

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  while (!q.isEmpty()) {
    std::cout << q.dequeue() << " ";
  }
  std::cout << std::endl;
  return 0;
}
