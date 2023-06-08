#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** wardah, Node** nadhira);
	bool listEmpty();
	bool delNode(int rollno);
	void traverse();
};

void CircularLinkedList::addNode() {
	int rollno;
	string nama;
	cout << "\nEnter the roll number of the student: ";
	cin >> rollno;
	cout << "\nEnter the name of the student: ";
	cin >> nama;
	Node* newNode = new Node();
	newNode->rollNumber = nim;
	newNode->name = nama;
	

	if (LAST == NULL || rollno <= LAST->rollNumber){
		if (LAST != NULL && rollno == LAST->rollNumber)
		{
			cout << "\nDuplicate number not allowed" << endl;
			return 0;
		}
	newNode->next = LAST;
		if (LAST != NULL)
			LAST->next = newNode;
		newNode->next = NULL;
		LAST = newNode;
		return;
	}

	Node* nadhira = LAST;
	Node* wardah = NULL;
	while (nadhira->next != NULL && nadhira->next->rollNumber < rollno)
	{
		wardah = nadhira;
		nadhira = nadhira->next;
	}

	if (nadhira->next != NULL && rollno == nadhira->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = nadhira->next;
	newNode->next = nadhira;
	if (nadhira->next != NULL)
		nadhira->next->next = newNode;
	nadhira->next = newNode;
}

bool CircularLinkedList::search(int rollno, Node** wardah, Node** nadhira) {
	*wardah = LAST->next;
	*nadhira = LAST->next;

	while (*nadhira != LAST) {
		if (rollno == (*nadhira)->rollNumber) {
			return true;
		}
		*wardah = *nadhira;
		*nadhira = (*nadhira)->next;
	}

	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode(int rollno) {
	Node* wardah, * nadhira;
	wardah = nadhira = NULL;
	if (search(rollno), &wardah, &nadhira) == false)
		return false;
	if (nadhira->next != NULL)
		nadhira->next = wardah;
	if (wardah != NULL)
		wardah->next = nadhira->next;
	else
		LAST = nadhira->next;

	delete nadhira;
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}