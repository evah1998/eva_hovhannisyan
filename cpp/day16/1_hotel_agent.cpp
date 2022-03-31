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
	int places_number;
	int price;
};

struct Hotel {
	string name;
	string city;
	int stars;
	string swimmingPool;
	Room room[count];
} hotel;

int main() {
	const int size = 5;
	string str;
	string array[size];
	Check check[100];
	ifstream file("hotels.txt");
	int k = 0;
	while (getline(file, str)) {
		int j = 0;
		array[0] = "";
		array[1] = "";
		for (int i = 0; str[i] != '['; i++) {
			if (str[i] == ',') {
				j++;
				if (str[i + 1] == ' ') {
					i++;
				}
				continue;
			}
			array[j] += str[i];
		}
		check[k].Name = array[0];
		check[k].City = array[1];
		k++;
	}
	int fileSize = k - 1;
	file.close();
	ofstream agent("hotels.txt", ios::app);
	cout << "Input hotel name: ";
	cin >> hotel.name;
	cout << "Input city: ";
	cin >> hotel.city;
	for (int i = 0; i <= fileSize; i++) {
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
		cin >> hotel.swimmingPool;
	} while (hotel.swimmingPool != "yes" && hotel.swimmingPool != "no");

	string placesOfRoom;
	string arr[3] = {};
	int index;
	int roomTypesNumber;
	cout << "How many types of rooms are there? ";
	cin >> roomTypesNumber;
	for (int i = 0; i < roomTypesNumber; i++) {
		cout << "Places number->room price->price: ";
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
		hotel.room[index].places_number = stoi(arr[1]);
		hotel.room[index].price = stoi(arr[2]);
		arr[0] = "";
		arr[1] = "";
		arr[2] = "";
	}
	agent << hotel.name + ", " + hotel.city + ", " + to_string(hotel.stars) + ", " + hotel.swimmingPool + ", [" ; 
	for (int i = 0; i < count - 1; i++) {
		agent << hotel.room[i].places_number << "-" << hotel.room[i].price << ", ";
	}
	agent << hotel.room[count - 2].places_number << "-" << hotel.room[count - 2].price << "]" << endl;
	agent.close();
	return 0;
}
