#include <iostream>

using namespace std;

class Node {
public:

	int val;
	Node* next;
    
	Node(int _val) {

		this->val = _val;
		this->next = NULL;
	}
};

class LinkedList {
private:

	Node* head;
	Node* tail;
	int count = 1;

public:

	LinkedList(int _val) {

		Node* node = new Node(_val);

		head = node;
		tail = node;
		count = 1;
	}

	~LinkedList() {

		Node* temp = head;

		while (head != NULL) {

			head = head->next;
			delete temp;
			temp = head;
		}
	}

	void addNode(int _val){

		Node* newNode = new Node(_val);

		if (count == 0) {

			head = newNode;
			tail = newNode;

			count++;
		}

		else if (count >= 1) {

			tail->next = newNode;
			tail = newNode;

			count++;
		}
	}

	void printAll()const {

		Node* temp = head;

		while (temp->next!= NULL) {

			cout << temp->val << "->";
			temp = temp->next;
		}

		cout << temp->val;

		cout << endl;
	}

	void deleteLastNode() {

		if (count == 0)
			return;

		if (count == 1) {

			head = NULL;
			tail = NULL;
		}

		else if (count >= 1) {
			Node* temp1 = head;
			Node* temp2 = head;

			while (temp1 != NULL) {

				temp2 = temp1;
				temp2 = temp2->next;
			}
			
			tail = temp2;
			temp2->next = NULL;
			delete temp1;

			count--;
		}


	}


	void addFirst(int _val) {

		Node* newNode = new Node(_val);

		if (count == 0) {

			head = newNode;
			tail = newNode;

			count++;
		}

		else if (count >= 1) {

			newNode->next = head;
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
			temp->next = NULL;

			delete temp;

			count--;
		}
	}


	Node* getNode(int idx) {

	

		Node* temp = head;

		for (int i = 0; i < idx; i++) {

			temp = temp->next;
		}

		return temp;
	}


	bool changeNodeValue(int idx, int _val) {

		Node* temp = getNode(idx);

		if (temp != NULL) {
			temp->val = _val;
			return true;
		}

		return false;
	}

	bool insertNode(int idx, int _val) {


		if (idx < 0 && idx >0)
			return false;


		if (count == 0) {

			addFirst(_val);
			return true;
		}

		else if (idx == count) {

			addNode(_val);
			return true;
		}


		else {

			Node* newNode = new Node(_val);
			Node* temp = getNode(idx - 1);

			newNode->next = temp->next;
			temp->next = newNode;

			count++;

			return true;

		}
		
	}


	void deleteNode(int idx) {

		if (count == 0)
			return;

		if (count == 1) {

			head = NULL;
			tail = NULL;

			count--;
		}

		else if (count > 1) {

			Node* del = getNode(idx);
			Node* temp = getNode(idx - 1);

			temp->next = del->next;
			del->next = NULL;
			delete del;

			count--;
		}
	}
};

int main() {

	LinkedList* llist = new LinkedList(12);

	llist->addNode(7);
	llist->addNode(20);
	llist->addNode(30);
	llist->addNode(25);
	llist->addNode(18);
	llist->printAll();
	llist->addFirst(9);
	cout << "List after addFirst(9)" << endl << endl;
	llist->printAll();
	llist->changeNodeValue(3, 21);
	cout << "List after changeNodeValue(3,21) " << endl << endl;
	llist->printAll();
	llist->deleteFirst();
	cout << "List after deleteFirst()" << endl << endl;
	llist->printAll();
	llist->deleteNode(1);
	cout << "List after deleteNode(1)" << endl << endl;
	llist->printAll();



	return 0;
}

