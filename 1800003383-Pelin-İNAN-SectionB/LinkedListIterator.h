#pragma once
#include"LinkedList.h"
#include<iostream>

struct n {
	int x;
	n* next;
};
template<class T>
struct nodeType {
	T data;
	nodeType* next;
};

template <class T>
class LinkedListIterator {

public:
	linkedListIterator();
	linkedListIterator(nodeType<T>* ptr);
	Type operator*();
	LinkedListIterator<T> operator++();
	bool operator!=(const LinkedListIterator<Type>& right) const;

private:
	nodeType<T>* current;
};

//Default Constructor and postcondition: current=NULL;
template <class T>
LinkedListIterator<T>::linkedListIterator() {

	current = NULL;
}

 //Postcondition: current=ptr;
 //Constructor With a parameter
template <class T>
LinkedListIterator<T>::linkedListIterator(nodeType<T>* ptr) {

	current = ptr;
}
//returns the info contained in the node.
template <class T>
T LinkedListIterator<T>::operator*() {

	return cureent->info;

}
//the iterator is advanced to the next node
template <class T>
LinkedListIterator<T> LinkedListIterator<T> ::operator++() {

	current = current->next;

	return *this;

}
//returns true if this iterator is equal to right iterator address
template <class T>
bool LinkedListIterator<T>::operator == (const LinkedListIterator<T>& right) const {


	return (current == right.current);

}
//returns true if this iterator is not equal to right iterator address
template <class T>
bool LinkedListIterator<T>::operator != (const LinkedListIterator<T>& right) const {


	return (current != right.current);

}
