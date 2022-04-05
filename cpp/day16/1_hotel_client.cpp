#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream HOTELS_FILE;
const string HOTELS_FILENAME = "hotels.txt";

enum HotelMenuEnum {
  SHOW_ALL = 0,
  FILTER_BY_CITY = 1,
  FILTER_BY_STARS = 2,
  BOOK_HOTEL = 3
};

struct Room {
  string number;
  string count;
  string price;
};

struct Hotel {
	int id;
  string name;
  string city;
  string stars;
  string swimmingPool;
  vector<Room> rooms;
};

struct Check {
    string Name;
    string City;
	int roomsNumber;
};
bool isFreeRoom(int, int, vector<Hotel>&);
void initHotels(vector<Hotel>&);
void showMenu();
bool isTrueDate(int *, int *, int *); 
void getCurrentMonthNumber(string, string, string*, int *, int *, int *);
void hotelFiltration(vector<Hotel>&);

int main() {
  vector<Hotel> hotels;
  initHotels(hotels);
  hotelFiltration(hotels);

  return 0;
}

void initHotels(vector<Hotel> &hotels) {
  try {
    HOTELS_FILE.open(HOTELS_FILENAME);

    if (HOTELS_FILE.fail()) {
      throw ("File " + HOTELS_FILENAME + " not found");
    }

    string fileLine = "";
		int id = 0;

    while (getline(HOTELS_FILE, fileLine)) {
      Hotel hotel = {};
      Room room = {};
      int hotelInfoIndex = 1;
      int roomInfoIndex = 1;
      bool isHotelInfoQueue = true;

      for (int i = 0; i < fileLine.length(); i++) {
        // check if room parsing should start
        if (fileLine[i] == '[') {
          isHotelInfoQueue = false;
          continue;
        }

        /**
         * if case - parsing hotel info
         * else case - parsing information about hotel rooms
        */
        if (isHotelInfoQueue) {
          // get next hotel field divided by comma
          if (fileLine[i] == ',' && fileLine[i + 1] == ' ') {
            i++;
            hotelInfoIndex++;
			hotel.id = id;
            continue;
          }

          /**
           * split hotel info data
           * 1 - name
           * 2 - city
           * 3 - stars
           * 4 - swimming pool
          */
          switch (hotelInfoIndex) {
            case 1:
              hotel.name += fileLine[i];
              break;
            case 2:
              hotel.city += fileLine[i];
              break;
            case 3:
              hotel.stars += fileLine[i];
              break;
            case 4:
              hotel.swimmingPool += fileLine[i];
              break;
          }
        } else {
          // get next room information divided by comma
          if (fileLine[i] == ',' && fileLine[i + 1] == ' ' || fileLine[i] == ']') {
            i++;
            hotel.rooms.push_back(room);
            // reset room options
            room = {};
            roomInfoIndex = 1;
            continue;
          }

          // get next room field divided by dash
          if (fileLine[i] == '-') {
            roomInfoIndex++;
            continue;
          }

          /**
           * split hotel rooms info data
           * 1 - number
           * 2 - count
           * 3 - price
          */
          switch (roomInfoIndex) {
            case 1:
              room.number += fileLine[i];
              break;
            case 2:
              room.count += fileLine[i];
              break;
            case 3:
              room.price += fileLine[i];
              break;
          }
        }
      }

      hotels.push_back(hotel);
			id++;
    }

    HOTELS_FILE.close();
  } catch (const string err) {
    cout << err << endl;
    HOTELS_FILE.close();
    exit(0);
  }
}

void showMenu() {
  cout << "==================================" << endl;
  cout << "0) Show all hotels" << endl;
  cout << "1) Search hotel by city" << endl;
  cout << "2) Search hotel by stars" << endl;
  cout << "3) Book hotel" << endl;
  cout << "9) Exit (or another key)" << endl;
  cout << "==================================" << endl;
}

void showHotels(vector<Hotel> &hotels) {
  for (int i = 0; i < hotels.size(); i++) {
    cout << "id: " << hotels[i].id << ") ";
    cout << hotels[i].name << " ";
    cout << hotels[i].city << " ";
    cout << hotels[i].stars << " ";
    cout << hotels[i].swimmingPool << " ";

    for (int j = 0; j < hotels[i].rooms.size(); j++) {
      cout << hotels[i].rooms[j].number << " ";
      cout << hotels[i].rooms[j].count << " ";
      cout << hotels[i].rooms[j].price << " ";
    }

    cout << endl;
  }
}


void dateTo_dd_mm_yyyy(string date, string *dateParts, int *day, int *month, int *year) {
	int j = 0;
	for (int i = 0; date[i] != '\0'; i++) {
		if (date[i] == '/') {
			j++;
			continue;
		}
		dateParts[j] += date[i];
	}
	*day = stoi(dateParts[0]);
	*month = stoi(dateParts[1]);
	*year = stoi(dateParts[2]);
}

void getCurrentMonthNumber(string currentTime, string months[12], string *currentMonth, int *currentMonthNumber, int *currentDay, int *currentYear) {
    string date[5] = {};
    int j = 0;
    for (int i = 0; currentTime[i] != '\0'; i++) {
		if (currentTime[i] == ' ' && currentTime[i + 1] != ' ') {
            j++;
            continue;
        }
        date[j] += currentTime[i];
    }
	for (int i = 0; i < 12; i++) {
        if (date[1] == months[i] + ' ') {
            *currentMonth = months[i];
            *currentMonthNumber = i + 1;
        }
    }
    *currentDay = stoi(date[2]);
 	*currentYear = stoi(date[4]);
}

bool isTrueDate(int *day, int *month, int *year) {
    int arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (*month >= 1 && *month <= 12 && *day >= 1 && *day <= arr[*month - 1] && *year >= 1900) {
        if (*month == 2) {
            if (*year % 4 != 0 && *day <= 28) {
                return true;
            } else if (*year % 4 == 0 && *day <= arr[*month - 1]) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
    return false;
}

void hotelFiltration(vector<Hotel> &hotels) {
  while (true) {
    showMenu();
    int option;
    cout << "Option: ";
    cin >> option;

    if (option == 9) {
      break;
    }

    vector<Hotel> filteredHotels;
    string city = "";
    int stars = 0;
    int hotelId;

    switch (option) {
      case SHOW_ALL:
        showHotels(hotels);
        break;
      case FILTER_BY_CITY:
        cout << "Input city: ";
        cin >> city;
        for (int i = 0; i < hotels.size(); i++) {
          if (hotels[i].city == city) {
            filteredHotels.push_back(hotels[i]);
          }
        }
        showHotels(filteredHotels);
        break;
      case FILTER_BY_STARS:
        cout << "Input stars: ";
        cin >> stars;
        for (int i = 0; i < hotels.size(); i++) {
          if (stoi(hotels[i].stars) == stars) {
            filteredHotels.push_back(hotels[i]);
          }
        }
        showHotels(filteredHotels);
        break;
      case BOOK_HOTEL:
        cout << "Input hotel id: ";
        cin >> hotelId;

        int placesNum;
        cout << "Input places room: ";
        cin >> placesNum;

		string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		time_t t = time(0);
		string dateTime = ctime(&t);
		string currentMonth;
		int currentMonthNumber;
		int currentDay;
		int currentYear;
		getCurrentMonthNumber(dateTime, months, &currentMonth, &currentMonthNumber, &currentDay, &currentYear);
		
        string startDate;
        cout << "Input start date - format (dd/mm/yyyy): ";
        cin >> startDate;
        int startDay, startMonth, startYear;
        string startDateParts[3] = {};
        dateTo_dd_mm_yyyy(startDate, startDateParts, &startDay, &startMonth, &startYear);

		if (!isTrueDate(&startDay, &startMonth, &startYear)) {
			cout << "Input the correct date\n";
			break;
		}
		if (startYear < currentYear ||
			startYear == currentYear && startMonth < currentMonthNumber || 
			startYear == currentYear && startMonth == currentMonthNumber && startDay < currentDay) {
			cout << "Input \n";
			break;
		}
        string endDate;
        cout << "Input end date - format (dd/mm/yyyy): ";
        cin >> endDate;

        int endDay, endMonth, endYear;
        string endDateParts[3] = {};
		dateTo_dd_mm_yyyy(endDate, endDateParts, &endDay, &endMonth, &endYear);
		if (!isTrueDate(&endDay, &endMonth, &endYear)) {
			cout << "Input the correct date\n";
			break;
		}
		if (endYear < currentYear ||
			endYear == currentYear && endMonth < currentMonthNumber || 
			endYear == currentYear && endMonth == currentMonthNumber && endDay < currentDay) {
			cout << "Input \n";
			break;
		}

		ifstream booking("book.txt");
		int numberOfLines = 0;
		string fileStrings;
    	while (getline(booking, fileStrings)) {
        	numberOfLines++;
    	}
    	booking.close();
		Check check[numberOfLines];
		booking.open("book.txt");
	
		if (isFreeRoom(hotelId, placesNum, hotels)) {
        	ofstream book("book.txt", ios::app);
        	book << hotels[hotelId].name + ", " + hotels[hotelId].city + ", " + to_string(placesNum) + ", "
        	+ (startDateParts[0] + "." + startDateParts[1] + "." + startDateParts[2]) + "-"
        	+ (endDateParts[0] + "." + endDateParts[1] + "." + endDateParts[2]) << endl;
			book.close();
		}
		break;
	}
  }
}
bool isFreeRoom(int hotelId, int placesNum, vector<Hotel> &hotels)  {
		int size = 4;
		string fileLines;
		string array[size];
		ifstream booking("book.txt");

		int numberOfLines = 0;
    	while (getline(booking, fileLines)) {
        	numberOfLines++;
    	}
    	booking.close();
		Check check[numberOfLines];
		booking.open("book.txt");
		int k = 0;
		while (getline(booking, fileLines)) {
        	int j = 0;
        	array[0] = "";
        	array[1] = "";
			array[2] = "";
        	for (int i = 0; fileLines[i] != '.'; i++) {
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
			check[k].roomsNumber = stoi(array[2]);
    	 	k++;
		}
    	booking.close();

		int j = 0;
		for (int i = 0; i < numberOfLines; i++) {
			if (hotels[hotelId].name == check[i].Name && hotels[hotelId].city == check[i].City && placesNum == check[i].roomsNumber) {
				j++;
			}
		}
		if (stoi(hotels[hotelId].rooms[hotelId].count) > j) {
			return true;

		}
		return false;
}
