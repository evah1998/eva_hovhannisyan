#include <iostream>
#include "polynomial.h"

using namespace std;

Polynomial newPolynomial();

int main() {
		int Operator;
		cout << "1.Add\n2.Multiply\n3.Multiply By Number\n";
		cout << "Input option: 1 | 2 | 3 | 4: ";
		cin >> Operator;
        Polynomial p = newPolynomial();
		switch(Operator) {
			case 1:
				{
        			Polynomial p1 = newPolynomial();
					Polynomial result = p.Add(p1);
					p.print();
					cout << "+ ";
        			p1.print();
					cout << " = ";
					result.print();
					break;
				}
 			case 2:
				{
        			Polynomial p1 = newPolynomial();
					Polynomial result = p.Multiply(p1);
					cout << "(";
					p.print();
					cout << ") * (";
        			p1.print();
					cout << ") = ";
					result.print();
					break;
				}
        	case 3:
				{
					int n;
					cout << "Input number: ";
					cin >> n;
					Polynomial result = p.MultiplyByNumber(n);
					p.print();
					result.print();
					break;
				}
			case 4:
				{
        			Polynomial p1 = newPolynomial();
					Polynomial result = p.Subtract(p1);
					p.print();
					cout << "- ";
        			p1.print();
					cout << " = ";
					result.print();
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
