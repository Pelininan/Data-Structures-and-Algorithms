#pragma once
#include "LinkedListIterator.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList {
public:
	nodeType<T>* head;
	nodeType<T>*tail;
	int count;
	LinkedList();
	void insertFirst(T item);
	void insertLast(T item);
	void insertAt(T item, int pos);
	void print();
	bool simplecompare(LinkedList<T>& rL);
	int compare(LinkedList<T>& rL);
	~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class T>
void LinkedList<T>::insertFirst(T item)
{
	nodeType<T>* newNode = new nodeType<T>;
	newNode->data = item;
	newNode->next = head;
	head = newNode;
	if (tail == NULL)
		tail = newNode;
	count++;
}

template <class T>
void LinkedList<T>::insertLast(T item)
{
	nodeType<T>*newNode = new nodeType<T>;
	newNode->data = item;
	newNode->next = NULL;
	if (head == NULL)
		head = newNode;
	else
		tail->next = newNode;//!
	tail = newNode;
	count++;
}

template <class T>
void LinkedList<T>::insertAt(T item, int pos)
{
	if (pos == 0)
		insertFirst(item);
	else if (pos >= count - 1)
		insertLast(item);
	else {
		nodeType<T>* newNode = new nodeType<T>;
		newNode->data = item;
		nodeType<T>* cur = head;
		for (int i = 0; i < pos - 1; i++, cur = cur++);     //Instead of typing cur =cur->next, I wrote cur++
		newNode->next = cur++;
		cur++ = newNode;
	}
	count++;
}

template <class T>
void LinkedList<T>::print()
{
	nodeType<T>* newNode = new nodeType<T>;
	newNode->data = item;
	nodeType<T>* cur = head;
	LinkedListIterator<T> cur, end;
	for (; cur != end; ++cur)                      //Instead of typing cur =cur->next, I wrote cur++
		cout << *cur << " ";                       //ı want to reach the item, So ı write
		                                          //indirection operator as in ∗cur, instead of writing cur− >data
	cout << *cur << endl;
}

template <class T>
bool LinkedList<T>::simplecompare(LinkedList<T>& rL)
{
	if (count != rL.count)
		return false;

	nodeType* cur, * rCur;
	for (cur = head, rCur = rL.head; cur != NULL; cur = cur++, rCur = rCur++)       //Instead of typing cur =cur->next, I wrote cur++ an rcur++
		if (*cur !=* rCur) {
			return false;
		}

	return true;
}

template <class T>
int LinkedList<T>::compare(LinkedList<T>& rL)
{
	nodeType<T>* cur = head, * rCur = rL.head;
	 
	for (; cur && rCur && (*cur== *rCur);           //ı want to reach the item, So ı write
		                                          //indirection operator as in ∗cur and *rcur, instead of writing cur− >data
		cur = cur++, rCur = rCur++);

	if (cur == NULL) {
		if (rCur == NULL)
			return 0;
		else return -1;
	}
	else if (rCur == NULL)
		return 1;
	else
		return (*cur > *rCur) ? 1 : -1;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	nodeType<T>* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
	count = 0;
}

