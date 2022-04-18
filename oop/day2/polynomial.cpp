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

Polynomial::Polynomial() {

}

void Polynomial::print() {
	for (int i = _n; i >= 0; --i) {
		if (_a[i] != 0) {
			if (i != _n && _a[i] > 0) {
				cout << "+";
  			}
			if (i == 0 || _a[i] != 1) {
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

Polynomial Polynomial::operator+(const Polynomial& other) {
	return this->Add(other);
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

Polynomial Polynomial::operator*(const Polynomial& other) {
	return this->Multiply(other);
}

Polynomial Polynomial::MultiplyByNumber(int number) {
    int newN = _n;
    int *newA = new int[newN + 1]{0};
    for (int i = newN; i >= 0; --i) {
        newA[i] = _a[i] * number;
    }
    Polynomial result(newN, newA);
    return result;
}

const Polynomial Polynomial::operator*(int number) {
	return this->MultiplyByNumber(number);	
}

Polynomial Polynomial::Subtract(Polynomial other) {
	return this->Add(other.MultiplyByNumber(-1));
}

Polynomial Polynomial::operator-(const Polynomial& other) {
	return this->Subtract(other);
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
	_n = max(_n, other._n);
	for (int i = 0; i <= _n; ++i) {
		_a[i] = _a[i] + other._a[i];
	}
	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
	_n = _n + other._n;
	int *newA = new int[_n + 1]{0};
	for (int deg = _n; deg >= 0; --deg) {
		for (int i = deg; i >= 0 && deg - i <= other._n; --i) {
			int j = deg - i;
			newA[deg] += (_a[i] * other._a[j]);
		}
	}
	for (int i = 0; i <= _n; ++i) {
		_a[i] = newA[i];
	}
	return *this;
}


Polynomial& Polynomial::operator-=(const Polynomial& other) {
	*this = this->Subtract(other);
	return *this;
}


bool Polynomial::operator==(const Polynomial& other) {
	if (_n != other._n) {
		return false;
	}
	for (int k = 0; k <= _n; ++k) {
		if (_a[k] != other._a[k]) {
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream &out, const Polynomial& other) {
	for (int i = other._n; i >= 0; --i) {
		if (other._a[i] != 0) {
			if (i != other._n && other._a[i] > 0) {
				out << "+";
  			}
			if (i == 0 || other._a[i] != 1) {
				out << other._a[i];
			}
			if (i != 0) {
				out << "X";
				if (i != 1) {
					out << "^" << i;
				}
			}
		}
	}
 	out << " ";
	return out;
}

istream& operator>>(istream &input, Polynomial& other) {
    cout << "Max degree of palynomial =  ";
    input >> other._n;
    for(int i = other._n; i >= 0; --i) {
        cout << "a [" << i << "] = ";
        input >> other._a[i];
    }
    return input;
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
