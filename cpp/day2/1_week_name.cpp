#include <iostream>
using namespace std;

int main() {
	int weekNum;
	do
	{
		cout << "Input week number(1-7): ";
		cin >> weekNum;
	}
	while (weekNum < 1 || weekNum > 7);
	
	switch (weekNum)
	{
		case 1:
			cout << "Monday\n";
			break;
		case 2:
	                cout << "Tuesday\n";
        	        break;
		case 3:
                        cout << "Wednesday\n";
                        break;
                case 4:
                        cout << "Thursday\n";
                        break;
		case 5:
                        cout << "Friday\n";
                        break;
                case 6:
                        cout << "Saturday\n";
                        break;
		case 7:
                        cout << "Sunday\n";
                        break;


	}
	
	return 0;
}
