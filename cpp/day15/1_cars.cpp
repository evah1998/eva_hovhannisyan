#include <iostream>
#include <fstream>

using namespace std;

struct Filter {
	string make;
	string model;
	int minPrice;
	int maxPrice;
	int minMileage;
	int maxMileage;
	float minEngineSize;
	float maxEngineSize;
	string transmission;
	string color;
	bool noFilter = false;
} filter;

struct Car {
	string make;
	string model;
	int price;
	int mileage;
	float engineSize;
	string transmission;
	string color;
};

const int MAX_SIZE = 10;

void printTab(string temp, int n) {
	if (temp.size() < n) {
		cout << "\t\t | ";
	} else {
		cout << "\t | ";
	}
}

void printCars(int size, Car *cars) {
	cout << "========================================================================================================\n"
	<< " Make\t\t | Model\t | Price\t | Mileage\t | Engine Size\t | Transmission\t | Color \n"
	<< "========================================================================================================\n";
	for (int i = 0; i < size; i++) {
		Car temp = cars[i];
		cout << temp.make;
		printTab(temp.make, 8);
		cout << temp.model;
		printTab(temp.model, 5);
		cout <<  temp.price;
		printTab(to_string(temp.price), 5);
		cout << temp.mileage;
		printTab(to_string(temp.mileage), 2);
		cout << temp.engineSize << '\t';
		printTab(to_string(temp.engineSize), 4);
		cout << temp.transmission;
		printTab(temp.transmission, 6);
		cout << temp.color;
		cout << endl << "--------------------------------------------------------------------------------------------------------\n";
	}
}

Car* applyFilters(Car * cars, int &size) {
	if (filter.noFilter) {
		return cars;
	}
	Car* result  = new Car [size];
	int index = 0;
	
	for(int i = 0; i < MAX_SIZE; i++) {
		if(!(filter.make != "" 				&& cars[i].make != filter.make
			|| filter.model != "" 			&& cars[i].model != filter.model
			|| filter.minPrice 				&& cars[i].price < filter.minPrice
			|| filter.maxPrice 				&& cars[i].price > filter.maxPrice
			|| filter.minMileage 			&& cars[i].mileage < filter.minMileage
			|| filter.maxMileage 			&& cars[i].mileage > filter.maxMileage
			|| filter.minEngineSize			&& cars[i].engineSize < filter.minEngineSize
			|| filter.maxEngineSize			&& cars[i].engineSize > filter.maxEngineSize
			|| filter.transmission != "" 	&& cars[i].transmission != filter.transmission
			|| filter.color != "" 			&& cars[i].color != filter.color)) {
				result[index] = cars[i];
				index++;
		}
	}
	size = index;
	return result;
}

bool setFilter(int key) {
	if(key < 1 || key > 10) {
		filter.noFilter = true;
		return false;
	}
	string value;
	cout << "Value: ";
	cin >> value;
	switch(key) {
		case 1:
			filter.make = value;
			break;
		case 2:
			filter.model = value;
			break;
		case 3:
			filter.minPrice = stoi(value);
			break;
		case 4:
			filter.maxPrice = stoi(value);
			break;
		case 5:
			filter.minMileage = stoi(value);
			break;
		case 6:
			filter.maxMileage = stoi(value);
			break;
		case 7:
			filter.minEngineSize = stof(value);
			break;
		case 8:
			filter.maxEngineSize = stof(value);
			break;
		case 9:
			filter.transmission = value;
			break;
		case 10:
			filter.color = value;
			break;
	}
	return true;
}

int main() {
	string fileData;
	ifstream file("cars.txt");
	int arrSize = 10;
	Car cars[arrSize];
	int k = 0;
	string word[7];
	while (getline(file, fileData)) {
		int j = 0;
		word[j] = "";
		for (int i = 0; i < fileData.length(); i++) {
			if (fileData[i] == ' ') {
				j++;
				word[j] = "";
				continue;
			}
			word[j] += fileData[i];
		}
		cars[k].make = word[0];
		cars[k].model = word[1];
		cars[k].price = stoi(word[2]);
		cars[k].mileage = stoi(word[3]);
		cars[k].engineSize = stof(word[4]);
		cars[k].transmission = word[5];
		cars[k].color = word[6];
		k++;
	}
	file.close();
	cout << "Select filter\n"
	<< "============================================================================================================================\n";
	cout << "1) make, 2) model, 3) minPrice 4) maxPrice, 5) minMileage 6) maxMileage 7) minEngine 8) maxEngine 9) Transmission, 10) Color"  << endl;
	cout << "* Other whice wil be shown all cars " << endl
	<< "* To see the search result write letters " << endl;
	int filterKey;
	while (cin >> filterKey) {
		if (!setFilter(filterKey)) {
			break;
		}
	}
	int size = MAX_SIZE;
	Car * filteredCars = applyFilters(cars, size);
	printCars(size, filteredCars);
	return 0;
}
