/* Date: 10/31/2024
* Name: Jace Van Oss
* File: Laboratory_9_P9-3.cpp
* 
* Description: program that generates a sequence of 20 random six sided die tosses, and determines
* wheather a run is present or not
*/

#include <iostream>
#include <cstdlib>

void displayRun(int values[], int size);
bool hasRun(int values[], int size);

using namespace std;

int main() {
	srand(time(0));

	const int arrSize = 20;
	int array[arrSize];
	while (true) {
		for (int i = 0; i < arrSize; i++) {
			array[i] = rand() % 6 + 1;
		}
		if (hasRun(array, arrSize)) {
			cout << "Has run: ";
			displayRun(array, arrSize);
			break;
		}
		else {
			cout << "No run: ";
			displayRun(array, arrSize);
		}

	}
	
	

	return 0;
}

void displayRun(int values[], int size) {
	int i = 0;
	while (i < size) {
		int j = i;
		while (j < size - 1 && values[j] == values[j + 1]) {
			j++;
		}
		if (j > i) {
			cout << "(";
			for (int k = i; k <= j; k++) {
				cout << values[k];
				if (k < j) {
					cout << " ";
				}
			}
			cout << ")";
			i = j + 1;
		}
		else {
			cout << values[i];
			i++;
		}
		if (i < size) {
			cout << " ";
		}
	}
	cout << endl;
}
bool hasRun(int values[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (values[i] == values[i + 1]) {
			return true;
		}
	}
	return false;
}