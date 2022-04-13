#include <iostream>
#include "polynomial.h"

using namespace std;

Polynomial::Polynomial(int n, int* a) {
	_n = n;
	_a = new int [n];
	for (int i = 0; i <= n; ++i) {
		_a[i] = a[i];
	}
}

void Polynomial::print() {
	for(int i = _n; i >= 0; --i) {
		if (_a[i] != 0) {
			if (i != _n && _a[i] > 0) {
				cout << "+";
  			}
			if (_a[i] != 1) {
				cout << _a[i];
			}
			if (i != 0) {
				cout << "X";
				if (i != 1) {
					cout << "^" << i;
				}
			}
		}
	}
 	cout << " ";
}

Polynomial Polynomial::Add(Polynomial other) {
	int newN = max(_n, other._n);
	int * newA = new int [newN + 1];
	for (int i = 0; i <= newN; ++i) {
		newA[i] = _a[i] + other._a[i];
	}
	return Polynomial(newN, newA);
}

Polynomial Polynomial::Multiply(Polynomial other) {
	int newN = _n + other._n;
	int *newA = new int[newN + 1]{0};
	for (int deg = newN; deg >= 0; --deg) {
		for (int i = deg; i >= 0 && deg - i <= other._n; --i) {
			int j = deg - i;
			newA[deg] += (_a[i] * other._a[j]);
		}
	}
	Polynomial result(newN, newA);
	return result;
}

Polynomial Polynomial::Multiply(int number) {
    int newN = _n;
    int *newA = new int[newN + 1]{0};
    for (int i = newN; i >= 0; --i) {
        newA[i] = _a[i] * number;
    }
    Polynomial result(newN, newA);
    return result;
}

void Polynomial::setN(int n) {
	_n = n;	
}

int Polynomial::getN() const {
	return _n;
}

int Polynomial::getA(int i) const {
	return _a[i];
}
