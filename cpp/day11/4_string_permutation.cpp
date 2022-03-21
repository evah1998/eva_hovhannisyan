#include <iostream>
using namespace std;

void swap(char*, char*); 
void permutation(string, int, int);

int main() {
	string word;
	cout << "Input string: ";
	cin >> word;

	int size = word.size();
	int factorial = size;
	for (int i = size; i > 1; i--) {
		factorial *= i - 1;
	}

	cout << "Total permutations of " << word << " is " << factorial <<endl; 
	permutation(word, 0, size - 1);

	return 0;
}

void swap(char* x, char* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void permutation(string word, int i, int size) {
	if (i == size) {
		cout << word << endl;
	} else {
		for (int j = i; j <= size; j++) {
			swap(&word[i], &word[j]);
			permutation(word, i + 1, size);
			swap(&word[i], &word[j]);
		}
	}
}
