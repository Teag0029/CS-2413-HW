#include "stack.h"

#include <iostream>

using namespace std;

class MyStack {

private:

	int* stack;

	int itop;

public:

	// This function pushes x into the stack. 
	// Push should always be successful even 
	// if the stack array is currently "full". 
	void push(int x);

	// This function removes the top element 
	// in the stack. It does nothing if the 
	// stack is empty.
	void pop();

	// This function returns the top element 
	// in the stack. It returns -1 if the stack 
	// is empty. 
	int top();

	// This function returns number of elements 
	// in the stack. Note this means it should 
	// return 0 if the stack is empty. 
	int Ssize();

	// This function is given to you. 
	// It initializes a small array. 
	// Do not modify it.  
	MyStack();
};

MyStack::MyStack() {
	stack = new int[2];
	itop = -1;
};

void MyStack::push(int x) {
	int* stacknew = new int[itop + 2];

	// if itop > size
	// stack_new = new int[longer size]
	// 
	// copy stack to stack_new
	// 
	// add x to the top of the stack 
};

void MyStack::pop() {

	// stack_new = new int[smaller size]
	// 
	// iterate stack pointer by one
	// copy stack to stack_new
	// 
	// decrement itop 
}

int MyStack::top() {
	return *stack;
}

int MyStack::Ssize() {
	return (itop + 1);
}

int stack::Main()
{
	MyStack x;

	int temp;

	while (cin >> temp) {

		x.push(temp);
	}
	int tSize = x.Ssize();
	for (int i = 0; i < tSize; i++) {

		cout << x.top() << '\n';

		x.pop();
	}

	return 0;
}

