#include <iostream>

using namespace std;

class Node {
public:

	int val;
	Node* next;


	Node(int _val) { this->val = _val; this->next = NULL; }


};

class Stack {
private:

	Node* top;

public:

	Stack() { this->top = NULL; }

	void addNode(int _val) {

		Node* newNode = new Node(_val);

		newNode->next = top;
		top = newNode;

        
	}

	~Stack() {

		while (top != NULL) { removeNode(); }
	}

	void printAll()const {

		Node* walk = top;

		while (walk->next != NULL) {

			cout << walk->val << endl;
			cout<<"|" << endl;
			cout << "v" << endl;

			walk = walk->next;

		}

		cout << walk->val << endl;
	}

	int removeNode() {


		if (top == NULL)
			return -1;


		Node* walk = top;
		int val = top->val;

		top = top->next;

		delete walk;

		return val;


	}

	bool findNode(int _val) {

		Node* walk = top;

		while (walk != NULL) {

			if (walk->val == _val)
				return true;

			walk = walk->next;
		}

		return false;
	}




};

int main() {

	Stack* myS = new Stack();

	myS->addNode(22);
	myS->addNode(33);
	myS->addNode(44);
	myS->addNode(55);

	myS->printAll();

	cout << endl;

	cout <<"Removed Node : "<<myS->removeNode()<<endl;

	cout << "After the removeNode() :" << endl << endl;
	myS->printAll();

	cout << endl;

	if (myS->findNode(44))
		cout << "44 is in the stack." << endl;

	

	return 0;
}
