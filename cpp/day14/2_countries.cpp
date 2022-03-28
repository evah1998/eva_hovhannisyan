#include <iostream>
#include <fstream>

using namespace std;

struct countries {
	string countryName;
	string capital;
	string domain;
	long population;
	int area;
	long GDP;
	int phoneCode;
};
enum PhoneCodes {
   	Armenia = 374,
	Georgia = 995
};
int getPhoneCode(int index) {
	switch(index) {
		case 0:
			return Armenia;
			break;
		case 1:
			return Georgia;
			break;
		default :
			return 0;
			break;
	}
}

int main(int argc, char* argv[]) {
	string fileDate;
	ifstream file("countries.txt");
	int arrsize = 2;
	countries country[arrsize];
	string word[6];
	int k = 0;
	while(getline(file, fileDate)) {
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
			country[k].countryName = word[0];
			country[k].capital = word[1];
			country[k].domain = word[2];
			country[k].population = stol(word[3]);
			country[k].area = stoi(word[4]);
			country[k].GDP = stol(word[5]);
			country[k].phoneCode = getPhoneCode(k);
			k++;
	}

	int searchCommand;
	string search = "search";
	string compare = "compare";
	if (argv[1] == search) {
		cout << "For CountryName input 1 || For Capital input 2 || For Domain input 3" << endl;
		cout << "==================================================================" << endl;
		cout << "Input search mode (countryName / capital / domain) : ";
		cin >> searchCommand;
		string inputCountry, inputCapital, inputDomain;
		int index = 0;
		switch (searchCommand) {
			case 1:
				cout << "Input Country name: ";
				cin >> inputCountry;
				for (int i = 0; i < arrsize; i++) {
					if (country[i].countryName == inputCountry) {
						index = i;
						break;
					}
				}
				break;
			case 2:
				cout << "Input Capital: ";
				cin >> inputCapital;
				for (int i = 0; i < arrsize; i++) {
                    if (country[i].capital == inputCapital) {
                        index = i;
                        break;
                    }
                }
				break;
			case 3:
				cout << "Input domain: ";
				cin >> inputDomain;
				for (int i = 0; i < arrsize; i++) {
                    if (country[i].domain == inputDomain) {
                        index = i;
                        break;
                    }
                }
				break;

		}
		cout << "Country - " << country[index].countryName << endl
		<< "Capital - " << country[index].capital << endl
		<< "Domain - " << country[index].domain << endl 
		<< "Population - " << country[index].population << endl
		<< "Area - " << country[index].area << endl
		<< "GDP - " << country[index].GDP << endl
		<< "Phone Code - " << country[index].phoneCode << endl;
		
	} else if (argv[1] == compare) {
		int index_1, index_2;
		string countryOne, countryTwo;
		cout << "Input first Country: ";
		cin >> countryOne;		
		cout << "Input second Country: ";
		cin >> countryTwo;
		for (int i = 0; i < arrsize; i++) {
			if (country[i].countryName == countryOne) {
				index_1 = i;
			}
			if (country[i].countryName == countryTwo) {
				index_2 = i;
			}
		}
		cout << "===========================================" << endl;
		cout << "\t   | " << country[index_1].countryName << "     | " << country[index_2].countryName << endl;
		cout << "===========================================" << endl;

		cout << "Capital\t   | " << country[index_1].capital << "     | " << country[index_2].capital << endl;
		cout << "Domain\t   | " << country[index_1].domain << "         | " << country[index_2].domain << endl;
		if (country[index_1].population > country[index_2].population) {
			cout << "Population | " << country[index_1].population << "     > " << country[index_2].population << endl;
		} else if (country[index_1].population < country[index_2].population) {
			cout << "Population | " << country[index_1].population << "     < " << country[index_2].population << endl;
		}

		if (country[index_1].area < country[index_2].area) {
			cout << "Area\t   | " << country[index_1].area << "       < " << country[index_2].area << endl;
		} else if (country[index_1].area > country[index_2].area) {
			cout << "Area\t   | " << country[index_1].area << "       > " << country[index_2].area << endl;
		}

		if (country[index_1].GDP < country[index_2].GDP) { 
			cout << "GDP\t   | " << country[index_1].GDP << " < " << country[index_2].GDP << endl;
		} else if (country[index_1].GDP > country[index_2].GDP) { 
			cout << "GDP\t   | " << country[index_1].GDP << " > " << country[index_2].GDP << endl;
		}

		cout << "Phone Code | " << country[index_1].phoneCode << "         | " << country[index_2].phoneCode << endl;
	}
	return 0;
}
