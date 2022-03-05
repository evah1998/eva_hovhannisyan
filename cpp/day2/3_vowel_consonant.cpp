#include <iostream>
using namespace std;

int main() {
	char alpha;
	do 
	{
		cout << "Input alphabet: ";
		cin >> alpha;
	}
	while (alpha < 'A' || alpha > 'z' || (alpha < 'a' && alpha > 'Z'));	

	switch (alpha) 
	{
		case 'a': case 'A':
		case 'e': case 'E':
		case 'i': case 'I':
		case 'o': case 'O':
		case 'u': case 'U':
			cout << alpha << " is vowel\n";
			break;
		default :
			cout << alpha << " is consonant\n";
	}
	return 0;

}
