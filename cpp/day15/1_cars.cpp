#include <iostream>
#include <fstream>

using namespace std;

struct Cars {
	string make;
	string model;
	int price;
	int mileage;
	float engineSize;
	string transmission;
	string color;
};

void printCars(int size, int *ptr, Cars *cars) {
	for (int i = 0; i < size; i++) {
		Cars temp = cars[ptr[i]];
		cout << temp.make << '\t' << temp.model << '\t' <<  temp.price <<  '\t' << temp.mileage << '\t' << temp.engineSize << '\t' << temp.transmission << '\t' << temp.color << endl;
	}
}
	
int main() {
	string fileDate;
	ifstream file("cars.txt");
	int arrSize = 10;
	Cars cars[arrSize];
	int k = 0;
	string word[7];
	while (getline(file, fileDate)) {
		int j = 0;
		word[j] = "";
		for (int i = 0; i < fileDate.length(); i++) {
			if (fileDate[i] == ' ') {
				j++;
				word[j] = "";
				continue;
			}
			word[j] += fileDate[i];
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
	<< "===============================\n";
	cout << "Make";
	for (int i = 0; i < arrSize; i++) {
		if (cars[i].make != cars[i - 1].make) {
			cout << "\t" << cars[i].make << "\t\t";
			if (i == 0) {
				cout << "Transmission\t automatic\t Color\t" << cars[i].color;
			} else if (i == 2) {
				cout << "\t\t manual\t\t\t " << cars[i].color;
			} else if (i == 3) {
				cout << "\t\t\t\t " << cars[6].color;
			}
			cout << endl;
		}
	}

	int indexarr[10] = {};
	int *ptr = indexarr;
	int size = 0;
	string car;
	cin >> car;
	for (int i = 0; i < arrSize; i++) {
		if (cars[i].make == car) {
			indexarr[size] = i;
			size++;
			cout << "size if =" << size << endl;
		} else if (cars[i].transmission == car) {
			indexarr[size] = i;
			size++;
		} else if (cars[i].color == car) {
			indexarr[size] = i;
			size++;
		}
	}
	printCars(size, ptr, cars);
	return 0;
}
