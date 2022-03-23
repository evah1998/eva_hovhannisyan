#include <iostream>
#include <fstream>

using namespace std;

void writeFile(string text, string fileName) {
	ofstream dictionary(fileName);
	dictionary << text << endl;
	dictionary.close();
}

bool isSimilarWord(string first, string second) {
	int count = 0;
	if (first.size() != second.size()) {
		return false;
	} 
	for (int i = 0; i < first.size(); i++) {
		if (first[i] == second[i]) {
			count++;
		}
	}
	return count >= first.size() - 1;
}

string * textToArray(string input) {
	string *arr = new string[50];
	int size = 0;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == ' ') {
             size++;
             continue;
        }
        arr[size] += input[i];
    }
	return arr;
}

string correctMistakes(string input, string dictionary) {
	string corrected = "";
	string *arrFile = textToArray(dictionary);
	string *arr = textToArray(input);
	for (int i = 0; arr[i] != "\0"; i++) {
    	for (int j = 0; arrFile[j] != "\0"; j++) {
        	if (isSimilarWord(arr[i], arrFile[j])) {
        	    arr[i] = arrFile[j];
            }
        }
		corrected += arr[i];
		if (arr[i + 1] != "\0") {
			corrected += ' ';
		}
    }
	return corrected;
}


int main() {
	writeFile("hello student programming language all same basic logical structure rules syntax between programmer computer writes instructions converts run program example below line code output words require precision single missing entire visual scratch developed Lifelong Learning Lab MIT most popular drag drop small components blocks", "dictionary.txt");
	ofstream corrected("corrected.txt");
	string input;
	cout << "Input: ";
	getline(cin, input);
	string dictionary;
	ifstream dict("dictionary.txt");
	if (dict.is_open()) {
		while (getline(dict, dictionary)) {
			string result = correctMistakes(input, dictionary); 
			corrected << result << endl;
		}
	}
	dict.close();

	return 0;
}
