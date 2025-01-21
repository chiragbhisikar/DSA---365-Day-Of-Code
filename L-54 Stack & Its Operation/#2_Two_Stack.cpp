// https : // www.naukri.com/code360/problems/two-stacks_983634?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int size)
    {
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        arr = new int[size];
    }

    // Push in stack 1.
    void push1(int num)
    {
        int space = this->top2 - this->top1;
        if (space > 1)
        {
            arr[++top1] = num;
        }
        else
        {
            //   cout << "Stack Overflow 1" << endl;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        int space = this->top2 - this->top1;
        if (space > 1)
        {
            arr[--top2] = num;
        }
        else
        {
            //   cout << "Stack Overflow 2" << endl;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 == -1)
        {
            //   cout << "Stack Underflow " << endl;
            return -1;
        }
        else
        {
            int ans = arr[top1--];
            return ans;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 == this->size)
        {
            //   cout << "Stack Underflow " << endl;
            return -1;
        }
        else
        {
            int ans = arr[top2++];
            return ans;
        }
    }
};
