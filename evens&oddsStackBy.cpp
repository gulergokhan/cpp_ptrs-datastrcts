#include <iostream>
#include <stack>
#include <vector>

using namespace std;


void rearrange(stack<int>& s) {

	vector<int> temp;

	while (!s.empty()) {

		temp.push_back(s.top());

		s.pop();
	}

	vector<int> evens, odds;

	for (int i = 0; i < temp.size() ; i++) {

		if (temp[i] % 2 == 0)
			evens.push_back(temp[i]);

		else
			odds.push_back(temp[i]);

	}

	for (int i = 0; i < evens.size(); i++)
		s.push(evens[i]);

	for (int i = 0; i < odds.size() ; i++)
		s.push(odds[i]);
}
int main() {

	stack<int> s;

	s.push(7);
	s.push(4);
	s.push(2);
	s.push(5);
	s.push(8);
	s.push(3);

	rearrange(s);

	while (!s.empty()) {

		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
