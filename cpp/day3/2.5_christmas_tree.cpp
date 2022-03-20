#include <iostream>
using namespace std;

void firstTree(int, int);
void secondTree(int, int, int);
void thirdTree(int, int, int);
void fourthTree(int, int, int);

int main() {
	int n;
	cout << "Input number: ";
	cin >> n;
	const int num = n;
	int i,j;

/* First christas tree
 *****
 ****
 ***
 **
 *   */

	firstTree(num, num);

/*Second christas tree
     *
    **
   ***
  ****
 *****   */

	secondTree(i, j, num);

/*Third christas tree
 *
 **
 ***
 ****
 *****   */

	thirdTree(i, j, num);

/*Fourth christmas tree
     *
    * *
   * * *
  * * * *
 * * * * *     */

	fourthTree(i, j, num);
	return 0;
}

void firstTree(int i, int j) {

	while (i) {
                int j = i;
                while (j) {
                        cout << "*";
                        j--;
                }
                cout << "\n";
                i--;
        }
        cout << "\n";
}
void secondTree(int i, int j, int num) {	
	i = 1;
        while (i <= num) {
		j = 1;                
                while (j <= num - i) {
                        cout << " ";
                        j++;
                } 
		j = 1;               
                while (j <= i) {
                        cout << "*";
                        j++;
                }
                cout << "\n";
                i++;
        }
        cout << "\n";
}
void thirdTree(int i, int j, int num) {
	i = 1;
        while (i <= num) {
                int j = 1;
                while (j <= i) {
                        cout << "*";
                        j++;
                }
                cout << "\n";
                i++;
        }
        cout << "\n";

}
void fourthTree(int i, int j, int num) {
	i = 1;
        while (i <= num) {
                int j = 1;
                while (j <= num - i) {
                        cout << " ";
                        j++;
                }
                j = 1;
                while (j <= i) {
                        cout << "* ";
                        j++;
                }
                cout << "\n";
                i++;
        }
        cout << "\n";

}
