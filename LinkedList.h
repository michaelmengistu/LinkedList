#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <string>

//stores the data
struct Node {
    int data;
    Node* next;
    Node():next(nullptr){};
    Node(int data): data(data), next(nullptr){};
};


class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	// Default constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Copy constructor
	LinkedList(const LinkedList& other);

	// Assignment constructor
	LinkedList& operator=(const LinkedList& other);

	// Inserts data to the linked list
	void insert(int data);

	// Clears the content of a linked list
	void clear();
    
    //gets head of linkedList
    Node* getHead() const;
    
};

 //prints from linked list
std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif
