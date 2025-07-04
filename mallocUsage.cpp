#include <iostream>

using namespace std;

void foo();

void main() {

	foo();
}

void foo() {

	int numElements;

	cout << "How many elements would you like in your own array :";
	cin >> numElements;

	float* myArray = new float[numElements];

	for (int i = 0; i < numElements; i++) {
		cin >> myArray[i];
	}

	for (int i = 0; i < numElements - 1; i++) {
		cout << myArray[i] << " , ";
	}

	cout << myArray[numElements - 1];

	delete[] myArray;
}
