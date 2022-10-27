#include <iostream>
#include <ctime>
using namespace std;

void displayrun(int values[20], int size);
bool hasRun(int values[20], int size);

int main() {
	srand(time(0));
	int values[20];
	int size = 20;

	int run = 0;
	if (run == 0) {
		for (int i = 0; i < size; i++) {
			values[i] = rand() % 6 + 1;
		}
		displayrun(values, size);
		run++;
	}
	while (hasRun(values, size) == false) {
		for (int i = 0; i < size; i++) {
			values[i] = rand() % 6 + 1;
		}
		displayrun(values, size);
	}
}

bool hasRun(int values[20], int size) {
	bool p = false;
	for (int i = 0; i <= size; i++) {
		if (values[i] == values[i + 1] || values[i] == values[i - 1]) {
			p = true;
		}
	}
	return p;
}
void displayrun(int values[20], int size) {
	hasRun(values, size);
	if (hasRun(values, size) == false) {
		cout << "no run: ";
		for (int i = 0; i < 20; i++) {
			cout << values[i] << " ";
		}
		cout << endl;
	}
	else if (hasRun(values, size) == true) {
		cout << "run: ";
		for (int i = 0; i < 20; i++) {
			if (values[i] == values[i + 1] && values[i] != values[i-1]) {
				cout << "(" << values[i] << " ";
			}
			else if (values[i] == values[i - 1] && values[i] != values [i+1]) {
				cout << values[i] << ")" << " ";
			}
			else cout << values[i] << " ";
		}
	}
}