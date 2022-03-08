#include <iostream>
using namespace std;
char inputAlpha(char);
void isAlpha(char);

int main() {
	char alpha = inputAlpha(alpha);
	isAlpha(alpha);
	return 0;
}
char inputAlpha(char alpha) {
	do 
	{
		cout << "Input alphabet: ";
		cin >> alpha;
	}
	while (alpha < 'A' || alpha > 'z' || (alpha < 'a' && alpha > 'Z'));
	return alpha;	
}
void isAlpha(char alpha) {
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
}

