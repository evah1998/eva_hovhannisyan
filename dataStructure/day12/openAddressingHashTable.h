#ifndef OPEN_ADDRESSING_HASH_TABLE
#define OPEN_ADDRESSING_HASH_TABLE

#include <iostream>
#include <string.h>

using namespace std;

int TABLE_SIZE = 20;
class Table {
    public:
        string _key;
        string _value;
        bool _deleted = false;
        Table(string key, string value) {
            _key = key;
            _value = value;
        }
};

class HashTable {
    private:
        Table **_table;

        int hashFunction(string&);
        void resize();
        void rehash();
    public:
        HashTable();
        void insert(string, string);
        void remove(string);
        string search(string);
        void printTable();
        ~HashTable();
};


HashTable::HashTable() {
    _table = new Table*[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; ++i) {
        _table[i] = NULL;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete _table[i];
    }
    delete[] _table;
}

int HashTable::hashFunction(string& s) {
	int hashVal = 0;
    int ascii;
	for(int i = 0; i < s.size(); ++i) {
		ascii = s[i] > 96 ? s[i] - 96 : s[i] - 64;
		hashVal = (hashVal * 32 + ascii) % TABLE_SIZE;
	}
	return hashVal;
}

void HashTable::resize() {
    TABLE_SIZE *= 2;
    Table **tmp = new Table*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        tmp[i] = NULL;
    }
    for (int i = 0; i < TABLE_SIZE / 2; ++i) {
        tmp[i] = _table[i];
    }
    _table = tmp;
}

void HashTable::rehash() {
    TABLE_SIZE /= 2;
    Table **tmp = new Table*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        tmp[i] = NULL;
    }
    for (int i = 0; i < TABLE_SIZE; ++i) {
        tmp[i] = _table[i];
    }
    _table = tmp;
}

void HashTable::insert(string key, string value) {
    int index = hashFunction(key);
    while (_table[index] && !_table[index]->_deleted) {
        ++index;
        if (index >= TABLE_SIZE) {
            resize();
        }
    }
    _table[index] = new Table(key, value);
}

void HashTable::remove(string key) {
    int index = hashFunction(key);
    for (int i = index; i < TABLE_SIZE; ++i) {
        if (!_table[i]->_deleted && _table[i]->_key == key) {
            _table[i]->_deleted = true;
            break;
        }
    }
    for (int i = TABLE_SIZE - 1; i > 0; --i) {
        if (_table[i]) {
            if (i < TABLE_SIZE / 2) {
                rehash();
            }
        }
    }
}

string HashTable::search(string key) {
    int index = hashFunction(key);
    while (_table[index] || _table[index]->_deleted) {
        if (_table[index]->_key == key) {
            if (!_table[index]->_deleted) {
                return _table[index]->_value;
            } else {
                return "key not found";
            }
        }
        ++index;
    }
    return "key not found";
}

void HashTable::printTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "[" << i << "] "; 
        if (_table[i] && !_table[i]->_deleted) {
            cout << _table[i]->_key << "->" << _table[i]->_value;
        }
        cout << endl;
    }
}

#endif