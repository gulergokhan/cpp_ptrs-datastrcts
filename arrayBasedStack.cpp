#include <iostream>
#define MAXSIZE  5

using namespace std;

class ArrayBasedStack {

private:

	int items[MAXSIZE];
	int size;

public:

	ArrayBasedStack() { size = 0; }

	void addElem(int _val) {

		if (size == 0) {

			items[0] = _val;

			size++;
		}

		for (int i = size; i > 0; i--) {

			items[i] = items[i - 1];
		}

		items[0] = _val;

		size++;
	}

	int removeElem() {

		if (size == 0)
			return -1;

		int removedElem = items[0];

		for (int i = 0; i < size; i++) {

			items[i] = items[i+1];

		}

		size--;

		return removedElem;

	}


	void printAll() const {

		for (int i = 0; i < size-1; i++) {

			cout << items[i] << endl;
			cout << "|" << endl;
			cout << "v" << endl;
			
		}

		cout << " ROOT " << endl;

		
	}


};


void main() {

	ArrayBasedStack myS;

	myS.addElem(10);
	myS.addElem(20);
	myS.addElem(30);
	myS.addElem(40);

	myS.printAll();

	cout << endl;

	myS.removeElem();

	cout << endl;

	cout << "After removing first elem : " << endl;

	myS.printAll();

	cout << endl;

	myS.removeElem();

	cout << endl;
	
	cout << "After removing first elem : " << endl;

	myS.printAll();
}
