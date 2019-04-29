#include "LinkedList.h"

using namespace std;

// Default constructor
LinkedList::LinkedList() :head(nullptr), tail(nullptr){}


//goes through list and clears data
void LinkedList::clear() {
    Node* temp;
    while(head != nullptr){
        temp = head ->next ;
        delete head;
        head = temp;
    }
    head = nullptr;
    tail = nullptr;
}

// Destructor
LinkedList::~LinkedList() {
	clear();
}

// Copy constructor
LinkedList::LinkedList(const LinkedList& source) {
    //sets a copy of original list if this list is empty
    if(this->head == nullptr){
        Node* original = source.getHead();
        head = new Node;
        head->data = original->data;
        original = original->next;
        Node* curr = head->next;
        while(original != nullptr){
            curr = new Node;
            curr->data = original->data;
            curr->next = original->next;
            curr = curr->next;
            original = original->next;
        }
    }
}

// Assignment constructor
LinkedList& LinkedList::operator=(const LinkedList& source) {
    if(this == &source){
        return *this;
    }
    if(this->head != nullptr){
        clear();
    }
    Node* original = source.getHead();
    head = new Node;
    head->data = original->data;
    original = original->next;
    Node* curr = head->next;
    while(original != nullptr){
        curr = new Node;
        curr->data = original->data;
        curr->next = original->next;
        curr = curr->next;
        original = original->next;
    }
    return *this;
}
 
void LinkedList::insert(int data){
    Node* newNode = new Node(data);
    if (tail == nullptr && head == nullptr) { // adds to empty list
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
 
//returns the beginning of a list
Node* LinkedList::getHead() const{
    return head;
}


ostream& operator<<(ostream& os, const LinkedList& ll) {
    Node* curr = ll.getHead();
    while(curr != nullptr){
        os <<  curr->data;
        curr = curr->next;
    }
    return os;
}
