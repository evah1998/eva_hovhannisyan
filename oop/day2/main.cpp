#include <iostream>
#include "polynomial.h"

using namespace std;

Polynomial newPolynomial();

int main() {
		int Operator;
		cout << "1.+\n2.*\n3.* Number\n4.-\n5.+=\n6.*=\n7.-=\n8.==\n";
		cout << "Input option: 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8: ";
		cin >> Operator;
        Polynomial p = newPolynomial();
		switch(Operator) {
			case 1:
				{
        			Polynomial p1 = newPolynomial();
					Polynomial result = p + p1;
					cout << p << "+ " << p1 << " = " << result;
					break;
				}
 			case 2:
				{
        			Polynomial p1 = newPolynomial();
					Polynomial result = p * p1;
					cout << "(" << p << ") * (" << p1 << ") = " << result;
					break;
				}
        	case 3:
				{
					int n;
					cout << "Input number: ";
					cin >> n;
					Polynomial result = p * n;
					cout << p << result;
					break;
				}
			case 4:
				{
        			Polynomial p1 = newPolynomial();
					Polynomial result = p - p1;
					cout << p << "- " << p1 << " = " << result;
					break;
				}
 			case 5:
				{
        			Polynomial p1 = newPolynomial();
					cout << p << " + " << p1 << " = ";
					p += p1;
					cout << p;
					break;
				}
 			case 6:
				{
        			Polynomial p1 = newPolynomial();
					cout << p << " * " << p1 << " = ";
					p *= p1;
					cout << p;
					break;
				}
			case 7:
				{
        			Polynomial p1 = newPolynomial();
					cout << p << " - " << p1 << " = ";
					p -= p1;
					cout << p;
					break;
				}
 			
 			case 8:
				{
        			Polynomial p1 = newPolynomial();
					cout << p << " == " << p1 << " is ";
					if (p == p1) {
						cout << "true\n";
						break;
					}
					cout << "false\n";
					break;
				}

		}        
		cout << endl;
        return 0;
}

Polynomial newPolynomial() {
    int n;
    cout << "Max degree of palynomial =  ";
    cin >> n;
    int* a = new int [n + 1];
    for(int i = n; i >= 0; --i) {
        cout << "a [" << i << "] = ";
        cin >> a[i];
    }
    Polynomial obj(n, a);
    return obj;
}
