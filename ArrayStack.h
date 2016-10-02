// Code based on:
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
#pragma once

#include <stdexcept>

using namespace std;

template <typename E>
class ArrayStack {
	enum { DEF_CAPACITY = 100 };		// default stack capacity
public:
	ArrayStack(int cap = DEF_CAPACITY);		// constructor from capacity
	int size() const;				// number of items in the stack
	bool empty() const;				// is the stack empty?
	const E& top() const;	// get the top element
	void push(const E& e);	// push element onto stack
	void pop();				// pop the stack
	void printAll();					// print all elements on stack to cout
private:                                	// member data
	E* S;					// array of stack elements
	int capacity;				// stack capacity
	int t;					// index of the top of the stack
};

template <typename E> ArrayStack<E>::ArrayStack(int cap)
	: S(new E[cap]), capacity(cap), t(-1) { }	// constructor from capacity

template <typename E> int ArrayStack<E>::size() const
{
	return (t + 1);
}				// number of items in the stack

template <typename E> bool ArrayStack<E>::empty() const
{
	return (t < 0);
}				// is the stack empty?

template <typename E>				// return top of stack
const E& ArrayStack<E>::top() const {
	if (empty()) throw length_error("Top of empty stack");
	return S[t];
}

template <typename E>				// push element onto the stack
void ArrayStack<E>::push(const E& e) {
	if (size() == capacity) throw length_error("Push to full stack");
	S[++t] = e;
}

template <typename E>				// pop the stack
void ArrayStack<E>::pop() {
	if (empty()) throw length_error("Pop from empty stack");
	--t;
}

// print all elements on stack
template <typename E>
void ArrayStack<E>::printAll() {
	if (empty()) throw length_error("Empty stack");
	cout << "Elements in stack: ";
	for (int i = t; i >= 0; i--)
		cout << "{" << S[i] << "} ";
	cout << endl;
}