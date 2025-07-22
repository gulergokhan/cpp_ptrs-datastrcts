#include <iostream>

using namespace std;

class DynamicLList {
private:

	int cap;
	int size;
	int* items;

	void expandDynamicArr() {

		int* newItems = new int[cap * 2];

		cap = cap * 2;

		for (int i = 0; i < cap; i++)

			newItems[i] = items[i];

		delete[] items;

		items = newItems;

	}

public:

	DynamicLList() {

		this->size = 0;
		this->cap = 100;
		this->items = new int[100];

	}

	~DynamicLList() {

		delete[] items;
	}

	void append(int val) {

		if (size >= cap) 

			expandDynamicArr();

		items[size] = val;
		size++;

	}

	void printAll()const {

		for (int i = 0; i < size; i++) {

			cout << items[i] << "|";
		}

		cout << endl;
	}

	bool isMember(int elem)const {

		for (int i = 0; i < size; i++) {

			if (elem == items[i])
				return true;
		}
		return false;
	}
	void deleteAt(int idx) {

		if (idx < size && idx >= 0) {

			for (int i = idx; i < size; i++) {

				items[i] = items[i + 1];
			}

			size--;
		}


	}

	void deleteVal(int elem) {

		int idx = -1;

		for (int i = 0; i < size; i++) {

			if (elem == items[i]) {

				idx = i;
				break;
			}
		}

		if (idx >= 0) {

			for (int i = idx; i < size; i++) {

				items[i] = items[i + 1];
			}

			size--;
		}


	}

	void insertAt(int idx, int elem) {

		if (idx < size&& size >= 0) {

			if (size >= cap)

				expandDynamicArr();

			for (int i = size; i > idx; i--) {

				items[i] = items[i - 1];
			}

			items[idx] = elem;
			size++;

		}
	}

	void clear() {

		size = 0;
	}

};

int main() {

	DynamicLList DynamicArray;

	DynamicArray.append(4);
	DynamicArray.append(7);
	DynamicArray.append(10);
	DynamicArray.append(-2);
	DynamicArray.append(8);
	DynamicArray.append(16);
	DynamicArray.append(30);
	

	

	DynamicArray.printAll();

	DynamicArray.deleteAt(3);
	cout << endl << "After deleting 3.index : " << endl;
	DynamicArray.printAll();

	DynamicArray.insertAt(3, -5);
	cout << endl << "After inserting -5 on 3.index : " << endl;
	DynamicArray.printAll();

	DynamicArray.deleteVal(-5);
	cout << endl << "After deleting element -5 : " << endl;
	DynamicArray.printAll();

	cout << endl;


	cout << "Is 8 a member element? : " << DynamicArray.isMember(8);
	

	return 0;
}
