#include <iostream>
#include <fstream>

using namespace std;

void commandForLanguage(ifstream &translate, int command) {
	if (command == 1) {
		translate.open("hy-en.txt");
	} else if (command == 2) {
		translate.open("en-hy.txt");
	}
}

void transletor(ifstream &translate, string word) {
	string readFile;
	while (getline(translate, readFile)) {
		string fileWord = "";
		for (int i = 0; i < readFile.length(); i++) {
			if (readFile[i] != '-' && readFile[i] == word[i]) {
				fileWord = word;
			}
		}
		if (fileWord == word) {
			for (int i = 0; i < readFile.length(); i++) {
				if (readFile[i] != '-' && readFile[i] != word[i]) {
					cout << readFile[i];
				}
			}
			break;
		} else {
//			cout << " " << word << " ";
//			cout << endl;
		}
	}
}
int main() {
	setlocale(LC_ALL, "");
	int command;
	cout << "for hy-en 1, for en-hy 2 " << endl;
	cin >> command;
	ifstream translate;
	cin.ignore();

	string inputText;
	cout << "Input text: ";	
	getline(cin, inputText);
	string word = "";
	for (int i = 0; i <= inputText.length(); i++) {
		if (inputText[i] == ' ' || i == inputText.length() && word != "") {
			commandForLanguage(translate, command);
			transletor(translate, word);
			translate.close();
			word = "";
			continue;
		}
		word += inputText[i];
	}
	cout << endl;
	return 0;
}
