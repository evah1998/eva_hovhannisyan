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

int findCarsIndex(int arrSize, string date, int *ptr, Cars *cars) {
	int size = 0;
	for (int i = 0; i < arrSize; i++) {
		if (cars[i].make == date) {
			ptr[size] = i;
			size++;
		} else if (cars[i].transmission == date) {
			ptr[size] = i;
			size++;
		} else if (cars[i].color == date) {
			ptr[size] = i;
			size++;
		} 
	}
	return size;
}

int price(int arrSize, int minPrice, int maxPrice, int *ptr, Cars *cars) {
	int size = 0;
	for (int i = 0; i < arrSize; i++) {
		if (cars[i].price >= minPrice && cars[i].price <= maxPrice) {
				ptr[size] = i;
				size++;
		}
	}
	return size;
}

int findCarsIndexTwo(int Size, string date, int *ptr, int *arr, Cars *cars) {
	int size = 0;
	for (int i = 0; i < Size; i++) {
		if (cars[ptr[i]].make == date) {
			arr[size] = i;
			size++;
		} else if (cars[ptr[i]].transmission == date) {
	cout<< " sizetransmission = " << size << endl;
			arr[size] = i;
			size++;
		} else if (cars[ptr[i]].color == date) {
	cout<< " sizecolor = " << size << endl;
	cout<< "  ptr[size]= " << ptr[size] << endl;
			arr[size] = ptr[i];
	cout<< "  ptr[size]newwww= " << ptr[size] << endl;
			size++;
		} 
	}
	return size;
}

int priceTwo(int Size, int minPrice, int maxPrice, int *ptr, int *arr, Cars *cars) {
	int size = 0;
	for (int i = 0; i < Size; i++) {
		if (cars[ptr[i]].price >= minPrice && cars[ptr[i]].price <= maxPrice) {
				arr[size] = ptr[i];
				size++;
		}
	}
	return size;
}

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
	<< "=======================================================================\n";
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

	cout << "\n \t\t <<<<<<<<<<<<<< Price (Min // Max) >>>>>>>>>>>>>> \n\n";
	int Size, size;
	int indexarr[10] = {};
	int indexptr[10] = {};
	int *ptr = indexarr;
	string date1, date2, date3;
	string addOrExit;
	cin >> date1;
	if (date1 == "min") {
		int minPrice;
		int maxPrice = 35000;
		cout << "Min: ";
		cin >> minPrice;
		Size = price(arrSize, minPrice, maxPrice, ptr, cars);
	} else if (date1 == "max") {
		int maxPrice;
		int minPrice = 0;
		cout << "Max: ";
		cin >> maxPrice;
		Size = price(arrSize, minPrice, maxPrice, ptr, cars);
	} else {
		Size = findCarsIndex(arrSize, date1, ptr, cars);
	}
	cout << "Add or exit: ";
	cin >> addOrExit;
	if (addOrExit == "add") {
		cin >> date2;
		int *arr = indexptr;
 		if (date2 == "min") {
			int minPrice;
			int maxPrice = 35000;
			cout << "Min: ";
			cin >> minPrice;
			Size = priceTwo(Size, minPrice, maxPrice, ptr, arr, cars);
		} else if (date2 == "max") {
			int maxPrice;
			int minPrice = 0;
			cout << "Max: ";
			cin >> maxPrice;
			Size = priceTwo(Size, minPrice, maxPrice, ptr, arr, cars);
		} else {	
			size = findCarsIndexTwo(Size, date2, ptr, arr, cars);
		}
		printCars(size, arr, cars);
	} else if (addOrExit == "exit") {
		printCars(Size, ptr, cars);
	}
	return 0;
}
