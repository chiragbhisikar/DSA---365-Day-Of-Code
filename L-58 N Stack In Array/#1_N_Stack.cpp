#include <bits/stdc++.h>
class NStack {
  int *arr;
  int *top;
  int *next;
  int size, noOfStake, freeSpot;

public:
  // Initialize your data structure.
  NStack(int noOfStake, int size) {
    this->size = size;
    this->noOfStake = noOfStake;

    this->arr = new int[size];
    this->next = new int[size];

    this->top = new int[noOfStake];

    //   intializing top
    for (int i = 0; i < noOfStake; i++) {
      this->top[i] = -1;
    }

    //   intializing next
    for (int i = 0; i < size; i++) {
      this->next[i] = i + 1;
    }
    // update last element of next to -1
    this->next[size - 1] = -1;

    // first freeSpot
    this->freeSpot = 0;
  }

  // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the
  // stack, and false otherwise.
  bool push(int x, int m) {
    //   check For Overflow
    if (freeSpot == -1) {
      return false;
    }

    // Find Index
    int index = this->freeSpot;

    // Update Free Spot
    this->freeSpot = next[index];

    // insert element
    this->arr[index] = x;

    // update next
    this->next[index] = top[m - 1];

    // update top
    this->top[m - 1] = index;

    return true;
  }

  // Pops top element from Mth Stack. Returns -1 if the stack is empty,
  // otherwise returns the popped element.
  int pop(int m) {
    //   check for Underflow
    if (this->top[m - 1] == -1) {
      return -1;
    }

    int index = this->top[m - 1];
    top[m - 1] = this->next[index];
    next[index] = freeSpot;
    this->freeSpot = index;

    return arr[index];
  }
};