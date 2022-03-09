#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	int arr[10];
	int Max = 0;
	for(int i=0; i < 10; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << ", ";
		Max = max(Max,arr[i]);
	}
	cout << endl;
	cout << "Max = " << Max << endl;
	return 0;
}
