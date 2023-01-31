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
    int data = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
      rear = nullptr;
    }
    delete temp;
    return data;
  }

  bool isEmpty() {
    return front == nullptr;
  }
};

int main() {
  Queue queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  while (!queue.isEmpty()) {
    std::cout << queue.dequeue() << std::endl;
  }
  return 0;
}
