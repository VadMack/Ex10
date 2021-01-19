// Copyright 2021 VadMack

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 private:
  T *storage;
  int size;
  int top;

 public:
  explicit MyStack(int size) {
    storage = new T[size];
    top = 0;
    this->size = size;
  }

  MyStack(const MyStack &stack) {
    this->storage = new T[stack.size];
    for (int i = 0; i < stack.size; ++i) {
      this->storage[i] = stack.storage[i];
    }
    this->size = stack.size;
    this->top = stack.top;
  }

  void push(T elem) {
    if (!isFull()) {
      storage[top] = elem;
      top++;
    } else {
      throw "Error: Stack is full!";
    }
  }

  T get() const {
    return storage[top - 1];
  }

  T pop() {
    if (!isEmpty()) {
      return storage[--top];
    } else {
      throw "Error: Stack is empty!";
    }
  }

  bool isFull() const {
    return top >= size;
  }

  bool isEmpty() const {
    return top == 0;
  }

  ~MyStack() {
    delete[] storage;
  }
};

#endif  // INCLUDE_MYSTACK_H_
