#include "function.h"
#include <iostream>
#include <string>
#define max(a,b) a>b?a:b
#define STACK_SIZE 1005
#define QUEUE_SIZE 1005

using namespace std;
BaseStack < string > Stack;
BaseQueue < char > Queue[105];

template < class T >
void ChangeSize(T **arr, int size, int new_size, int start) {
	T *new_arr = new T[new_size];
	for (int i = 0; i < size; i++) {
		new_arr[i] = (*arr)[start];
		start = (start + 1) % size;
	}
	delete[](*arr);
	*arr = new_arr;
}

//Function Implement

void insert(int L) {
	int l;
	string s;
	cin >> l >> s;
	int s_len = s.size();
	int max_size = 0;
	for (int i = l; i < l + s_len; i++)
		max_size = max(max_size, Queue[i].size());
	for (int i = l; i < l + s_len; i++) {
		int num = max_size - Queue[i].size();
		while (num--)
			Queue[i].push('@');
		Queue[i].push(s[i - l]);
	}
}
string first_row(int L, bool print) {
	string s = "";
	for (int i = 0; i < L; i++) {
		char ch;
		if(!Queue[i].empty()) ch = Queue[i].front();
		else ch = '~';
		s += ch;
	}
	if (print) {
		cout << "BOTTOM_ROW" << '\n';
		cout << s << '\n';
	}
	return s;
}
void query(int L) {
	string s;
	cin >> s;
	int s_len = s.size();
	string row = first_row(L);
	int pos = row.find(s, 0);
	if (pos == string::npos) return;
	for (int i = pos; i < pos + s_len; i++)
		Queue[i].pop();
	Stack.push(s);
}
void flush() {
	cout << "FLUSH" << '\n';
	while (!Stack.empty()) {
		string s = Stack.top();
		cout << s << '\n';
		Stack.pop();
	}
}
void reset(int L) {
	int size = Stack.size();
	while (size--)
		Stack.pop();
	for (int i = 0; i < L; i++) {
		size = Queue[i].size();
		while (size--)
			Queue[i].pop();
	}
}


//BaseStack member function

// Constructor
template < class T >
BaseStack < T >::BaseStack() {
	_top = -1;
	capacity = STACK_SIZE;
	_stack = new T[capacity];
}

// Destructor
template < class T >
BaseStack < T >::~BaseStack() {
	delete[]_stack;
}

// Check if the stack is empty
template < class T >
bool BaseStack < T >::empty() {
	return _top == -1;
}

// Return the size of the stack
template < class T >
int BaseStack < T >::size() {
	return _top + 1;
}

// Return the top element
template < class T >
T& BaseStack < T >::top() {
	if (empty()) {
		/*cout << "The stack is empty.\n";
		exit(0);*/
	}
	return _stack[_top];
}

// Insert a new element at top
template < class T >
void BaseStack < T >::push(const T& item) {
	if (capacity == _top + 1) {
		ChangeSize(&_stack, capacity, 2 * capacity, 0);
		capacity *= 2;
		/*cout << "The stack is full.\n";
		exit(0);*/
	}
	_stack[++_top] = item;
}

// Delete one element from top
template < class T >
void BaseStack < T >::pop() {
	if (empty()) {
		/*cout << "The stack is empty.\n";
		exit(0);*/
	}
	_stack[_top--].~T();
}


//BaseQueue member function

// Constructor
template < class T >
BaseQueue < T >::BaseQueue() {
	capacity = QUEUE_SIZE;
	_front = _rear = capacity - 1;
	_queue = new T[capacity];
}

// Destructor
template < class T >
BaseQueue < T >::~BaseQueue() {
	delete[]_queue;
}

// Check if the stack is empty
template < class T >
bool BaseQueue < T >::empty() {
	return _front == _rear;
}

// Return the size of the queue
template < class T >
int BaseQueue < T >::size() {
	if (_rear >= _front) return _rear - _front;
	else return capacity - _front + _rear;
}

// Return the front element
template < class T >
T& BaseQueue < T >::front() {
	if (empty()) {
		/*cout << "The queue is empty.\n";
		exit(0);*/
	}
	return _queue[(_front + 1) % capacity];
}

// Insert a new element at rear
template < class T >
void BaseQueue < T >::push(const T& item) {
	if ((_rear + 1) % capacity == _front) {
		ChangeSize(&_queue, capacity, 2 * capacity, (_front + 1) % capacity);
		_rear = capacity - 2;
		capacity *= 2;
		_front = capacity - 1;
		/*cout << "The queue will full.\n";
		exit(0);*/
	}
	_rear = (_rear + 1) % capacity;
	_queue[_rear] = item;
}

// Delete one element from front
template < class T >
void BaseQueue < T >::pop() {
	if (empty()) {
		/*cout << "The queue is empty/\n";
		exit(0);*/
	}
	_front = (_front + 1) % capacity;
	_queue[_front].~T();
}
