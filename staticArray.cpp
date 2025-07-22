#include <iostream>
#define MAXSIZE 1000

using namespace std;

class LList {

private:

	int items[MAXSIZE];
	int size;


public:

	LList() {
		this->size = 0;
	}

	void append(int val) {

		if (size < MAXSIZE) {

			this->items[size] = val;
			size++;
		}
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


	LList staticArray;

	staticArray.append(4);
	staticArray.append(7);
	staticArray.append(10);
	staticArray.append(-2);
	staticArray.append(8);
	staticArray.append(16);
	staticArray.append(30);

	staticArray.printAll();

	staticArray.deleteAt(3);
	cout << endl << "After deleting 3.index : " << endl;
	staticArray.printAll();

	staticArray.insertAt(3, -5);
	cout << endl << "After inserting -5 on 3.index : " << endl;
	staticArray.printAll();

	staticArray.deleteVal(-5);
	cout << endl << "After deleting element -5 : " << endl;
	staticArray.printAll();

	cout << endl;


	cout << "Is 8 a member element? : " << staticArray.isMember(8) << endl;

	staticArray.clear();

	return 0;
}
