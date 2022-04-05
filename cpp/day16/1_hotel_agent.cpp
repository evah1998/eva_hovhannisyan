#include <iostream>
#include <fstream>

using namespace std;

const int PARAMETERS_COUNT = 4;
const int count = 10; 

struct Check {
	string Name;
	string City;
};

struct Room {
	int number;
	int places_number;
	int price;
};

struct Hotel {
	string name;
	string city;
	int stars;
	bool swimmingPool = false;
	Room room[count];
} hotel;

int main() {
	const int size = 5;
	string fileLines;
	string array[size];
	ifstream file("hotels.txt");
	int numberOfLines = 0;
	while (getline(file, fileLines)) {
		numberOfLines++;
	}
	file.close();
	Check check[numberOfLines];
	
	file.open("hotels.txt");
	int k = 0;
	while (getline(file, fileLines)) {
		int j = 0;
		array[0] = "";
		array[1] = "";
		for (int i = 0; fileLines[i] != '['; i++) {
			if (fileLines[i] == ',') {
				j++;
				if (fileLines[i + 1] == ' ') {
					i++;
				}
				continue;
			}
			array[j] += fileLines[i];
		}
		check[k].Name = array[0];
		check[k].City = array[1];
		k++;
	}
	file.close();
	string tempSwimmingPool = "";
	ofstream agent("hotels.txt", ios::app);
	cout << "Input hotel name: ";
	cin >> hotel.name;
	cout << "Input city: ";
	cin >> hotel.city;
	for (int i = 0; i < numberOfLines; i++) {
		if (check[i].Name == hotel.name && check[i].City == hotel.city) {
			cout << "This hotel is already registered!\n";
			return 0;
		}
	}
	do {
		cout << "Input stars: ";
		cin >> hotel.stars;
	} while (hotel.stars < 1 || hotel.stars > 5);

	do {
		cout << "Swimming Pool (input yes / no): ";
		cin >> tempSwimmingPool;
	} while (tempSwimmingPool != "yes" && tempSwimmingPool != "no");

	if (tempSwimmingPool == "yes") {
		hotel.swimmingPool = true;
	}

	string placesOfRoom;
	string arr[3] = {};
	int index;
	int roomTypesNumber;
	cout << "How many types of rooms are there? ";
	cin >> roomTypesNumber;
	for (int i = 0; i < roomTypesNumber; i++) {
		cout << "Places number->rooms number->price: ";
		cin >> placesOfRoom;
		int j = 0;
		for (int i = 0; i < placesOfRoom.length(); i++) {
			if (placesOfRoom[i] == '-') {
				j++;
				if (placesOfRoom[i + 1] == '>') {
					i++;
				}
				continue;
			}
			arr[j] += placesOfRoom[i];
		}
		index = stoi(arr[0]) - 1;
		hotel.room[index].number = stoi(arr[0]);
		hotel.room[index].places_number = stoi(arr[1]);
		hotel.room[index].price = stoi(arr[2]);
		
		arr[0] = "";
		arr[1] = "";
		arr[2] = "";
	}
	agent << hotel.name + ", " + hotel.city + ", " + to_string(hotel.stars) + ", ";
	if (hotel.swimmingPool) {
		agent << "yes, [" ; 
	} else {
		agent << "no, [" ; 
	}
	
	for (int i = 0; i < count; i++) {
		if (!hotel.room[i].number || !hotel.room[i].places_number || !hotel.room[i].price) {
			continue;
		}

		agent << hotel.room[i].number << "-" << hotel.room[i].places_number << "-" << hotel.room[i].price << ", ";
	}
	agent << "]" << endl;
	agent.close();
	return 0;
}
