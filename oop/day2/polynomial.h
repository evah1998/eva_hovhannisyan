using namespace std;
#ifndef POLYNOMIAL
#define POLYNOMIAL

class Polynomial {
	private:
	// The maximum degree of Polynomial
		int _n;
		int* _a;
	public:
		void setN(int n);
		int getN() const;
		void setA(int* a, int n);
		int getA(int) const;
		Polynomial(int n, int* a);
		Polynomial();

		Polynomial Multiply(Polynomial);
		Polynomial MultiplyByNumber(int);
		Polynomial Add(Polynomial);
		Polynomial Subtract(Polynomial);
		void print();
		friend ostream &operator<<(ostream &out, const Polynomial&);
		friend istream &operator>>(istream &input, Polynomial&);
		Polynomial operator+(const Polynomial&);
		Polynomial operator*(const Polynomial&);
		Polynomial operator-(const Polynomial&);
		Polynomial& operator+=(const Polynomial&);
		const Polynomial operator*(int);
		Polynomial& operator-=(const Polynomial&);
		Polynomial& operator*=(const Polynomial&);
		bool operator==(const Polynomial&);

		//Polynomial& operator<<(const Polynomial&);
	//	Polynomial& operator>>(const Polynomial&);
};

#endif
