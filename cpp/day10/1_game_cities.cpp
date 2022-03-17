#include <iostream>
using namespace std;
const char* cityArr[] = {
	"Yerevan", 	
 	"Gyumri",
 	"Vanadzor", 
 	"Vagharshapat", 
 	"Abovyan",
 	"Kapan",
 	"Hrazdan",
 	"Armavir", 
 	"Artashat",
 	"Ijevan",
 	"Gavar",
 	"Goris", 
 	"Charentcavan",
 	"Ararat", 
 	"Masis",
 	"Artik",
 	"Sevan",
 	"Ashtarak", 
 	"Dilijan",
 	"Sisian",
 	"Alaverdi",
 	"Stepanavan",
 	"Martuni",
 	"Spitak", 
 	"Vardenis",
 	"Yeghvard",
 	"Vedi",
 	"Byureghavan",
 	"Metsamor",
 	"Berd", 
 	"Exegnadzor",
 	"Tashir",
 	"Kajaran", 
 	"Aparan", 
 	"Vayk",
 	"Chambarak",
 	"Maralik",
 	"Noyemberyan",
 	"Talin",
 	"Jermuk",
 	"Meghri", 
 	"Ayrum",
 	"Akhtala",
 	"Tumanyan",
 	"Tsaghkadzor"};

void gameCity(string);
int main () {
	string city;
	
	cout << "Input city: ";
	cin >> city;
	gameCity(city);
	return 0;
}

void gameCity(string city) {
	char a, A;
	bool isFound = true;
	const int count = 'a' - 'A';
	int sizeWord = 0;
	const int size = sizeof(cityArr) / sizeof(char*);
	int realSize = size;
	bool isWinner = true;
	for (int i = 0; i < size; i++) {
		if (city == cityArr[i]) {
			cityArr[i] = "";
			realSize --;
			for (int j = 0; j < size; j++) {
				A = cityArr[j][0];
				a = A + count;
				if (city[city.size() - 1] == a) {
					cout << cityArr[j] << endl;
					cityArr[j] = ""; 
					realSize --;
					for (int k = 0; cityArr[j][k] != '\0'; k++) {
						sizeWord ++;
					}
					cin >> city;
					if (cityArr[j][sizeWord - 1] == city[0] + count) {
						gameCity(city);
					} else {
						cout << "Game Over\n";
						isFound = false;
						isWinner = false;
						break;
					}
					sizeWord = 0;
				}
				if (isFound == false) {
					break;
				}			
			}
			if (isWinner == true) {
				cout << "You WON!\n";
			}
			break;			
		} else if (i == size - 1) {
			cout << "Game Over\n";
		}
	}
}

