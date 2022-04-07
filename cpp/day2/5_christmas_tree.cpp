#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Input number: ";
	cin >> n;
	const int num = n;

/* First christas tree
 *****
 ****
 ***
 **
 *   */
	int i = num;	
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

/*Second christas tree
     *
    **
   ***
  ****
 *****   */

	i = 1;
	while (i <= num) {
		int j = 1;
		while (j <= num) {
			if (j <= num - i) {
				cout << " ";
			} else {
				cout << "*";
			}
			j++;
		}
		cout << "\n";
		i++;
	}
	cout << "\n";


/*Third christas tree
 *
 **
 ***
 ****
 *****   */

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

/*Fourth christmas tree
     *
    * *
   * * *
  * * * *
 * * * * *     */
	i = 1;
        while (i <= num) {
                int j = 1;
                while (j <= num) {
					if (j <= num - i) {
                        cout << " ";
					} else {
                        cout << "* ";
					}
                        j++;
                }
               cout << "\n";
                i++;
        }
        cout << "\n";
	
	return 0;
}
