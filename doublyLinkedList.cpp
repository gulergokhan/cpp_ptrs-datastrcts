#include <iostream>

using namespace std;

class Node {
public:

	int val;
	Node* next;
	Node* prev;


	Node(int _val) {

		this->val = _val;
		this->next = NULL;
		this->prev = NULL;
	}
};

class DoublyLinkedList {
private:

	Node* head;
	Node* tail;
	int count;

public:

	DoublyLinkedList(int _val) {

		Node* node = new Node(_val);

		head = node;
		tail = node;
		count = 1;
	}

	~DoublyLinkedList() {

		Node* walk = head;

		while (head != NULL) {
			
			head = head->next;
			delete walk;
			walk = head;
		}
	}

	void addLastNode(int _val) {

		Node* newNode = new Node(_val);

		if (count == 0) {

			head = newNode;
			tail = newNode;

			count++;

		}

		else if (count >= 1) {

			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;

			count++;

		}

	
	}

	void printAll()const {

		Node* walk = head;

		while (walk->next !=NULL) {

			cout << walk->val << "->";
			walk = walk->next;
		}

		cout << walk->val << endl << endl;

		

	}

	void deleteLastNode() {


		if (count == 0)
			return;

		if (count == 1) {

			head = NULL;
			tail = NULL;

			count--;

		}

		if (count > 1) {

			Node* walk = tail;
		
			tail = tail->prev;
			tail->next = NULL;

			delete walk;

			count--;

		}
		
	}

	void addFirstNode(int _val) {
		
		Node* newNode = new Node(_val);

		if (count == 0) {
			
			head = newNode;
			tail = newNode;

			count++;
		}

		if (count >= 1) {

			newNode->next = head;
			head->prev = newNode;
			head = newNode;

			count++;
		}
	}

	void deleteFirst() {

		if (count == 0)
			return;

		if (count == 1) {
			
			head = NULL;
			tail = NULL;

			count--;
		}

		else if (count > 1) {

			Node* temp = head;

			head = head->next;
			head->prev = NULL;
			delete temp;

			count--;

		}
		
		
	}

	Node* getNode(int idx) {

		if (idx < 0 || idx > count)
			return NULL;

		Node* temp = head;

		for (int i = 0; i < idx; i++) {

			temp = temp->next;

		}

		return temp;
			
	}

	bool changeNodeValue(int idx, int _val){

		if (idx < 0 || idx >count)
			return false;

		Node* temp = getNode(idx);

		if (temp != NULL) {
			temp->val = _val;

			return true;

		}
		
	}

	bool insertNodeValue(int idx, int _val) {


		if (idx < 0 || idx > count)
			return false;



		if (count == 0) {

			addFirstNode(_val);
			return true;
		}

		else if (count == idx) {

			addLastNode(_val);
			return true;
		}

		else {

			Node* newNode = new Node(_val);
			Node* targetNode = getNode(idx);

			newNode->prev = targetNode->prev;
			newNode->next = targetNode;
			targetNode->prev->next = newNode;
			targetNode->prev = newNode;
			
			
			count++;

		}
			

		
	}

	bool deleteNode(int idx) {

		if (idx < 0 || idx >= count)
			return false;

		if (count == 0)
			return false;

		else if (count == 1) {

			deleteFirst();

			return true;

		}

		else if (idx == count - 1) {

			deleteLastNode();
			return true;
		}


		Node* del = getNode(idx);


		del->next->prev = del->prev;
		del->prev->next = del->next;

		delete del;

		count--;

		return true;
	}


};

int main() {

	DoublyLinkedList* DLlist = new DoublyLinkedList(12);

	DLlist->addLastNode(8);
	DLlist->printAll();
	DLlist->deleteLastNode();
	DLlist->printAll();
	DLlist->addFirstNode(11);
	DLlist->printAll();
	DLlist->deleteFirst();
	DLlist->printAll();
	DLlist->addFirstNode(45);
	DLlist->printAll();
	DLlist->addLastNode(22);
	DLlist->printAll();
	DLlist->insertNodeValue(1, 9);
	DLlist->printAll();
	DLlist->deleteNode(1);
	DLlist->printAll();
	


	return 0;

}
