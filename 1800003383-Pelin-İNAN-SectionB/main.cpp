#include "LinkedList.h"
#include<iostream>
#include"LinkedListIterator.h"

using namespace std;

int main() {

	char item;
	LinkedList<char> list1, list2;

	cout << "Please enter the first list of characters"
		<< "\nPress Ctrl+Z to stop entering." << endl;
	cin >> item;

	while (!cin.eof()) {
		list1.insertFirst(item);
		cin >> item;
	}
	cin.clear();

	cout << "Please enter the second list of characters"
		<< "\nPress Ctrl+Z to stop entering" << endl;
	cin >> item;

	while (!cin.eof()) {
		list2.insertFirst(item);
		cin >> item;
	}

	list1.print();
	list2.print();

	bool result1 = list1.simplecompare(list2);

	if (result1 == true) {
		cout << "The lists are same!\n";
	}
	else {
		cout << "The lists are not same!\n";
	}

	int result2 = list1.compare(list2);

	if (result2 == 0) {
		cout << "The lists are same!\n";
	}
	else if (result2 == -1) {
		cout << "First list < second list\n" << endl;

	}
	else {
		cout << "First > second list\n" << endl;
	}







	return 0;
}

