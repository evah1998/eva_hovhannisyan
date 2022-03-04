#include <iostream>
using namespace std;

int main() {
	int monthNum;
	do
	{
		cout << "Input month number: ";
		cin >> monthNum;	
	}
	while (monthNum < 1 || monthNum > 12);
	
	switch (monthNum)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			cout << "31\n";
			break;
		case 2:
                        cout << "28\n";
                        break;
		case 4: case 6: case 9: case 11:
                     	cout << "30\n";
                        break;
			
	}
}
