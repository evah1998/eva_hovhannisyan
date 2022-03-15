#include "mylib.h" 
using namespace std;

int main(int argc, char* argv[]) {
	const int size = argc - 1;
	char ** args = argv + 1;
	char ** end = args + size - 1;
	int sum1 = 0;
	int sum2 = 0;
	while (args <= end) {
		sum1 += my_atoi(*args);
		sum2 += atoi(*args);
		*args ++;
	}

	cout << "Sum my_atoi : " << sum1 << endl;
	cout << "Sum atoi : " << sum2 << endl;

	return 0;
}
