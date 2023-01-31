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

class Stack {
 public:
  Node* top;

  Stack() {
    top = nullptr;
  }

  void push(int data) {
    Node* newNode = new Node(data);
    newNode->next = top;
    top = newNode;
  }

  int pop() {
    if (top == nullptr) {
      std::cout << "Stack is empty" << std::endl;
      return -1;
    }
    int data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
  }

  bool isEmpty() {
    return top == nullptr;
  }
};

int main() {
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  while (!stack.isEmpty()) {
    std::cout << stack.pop() << std::endl;
 
  }}