#include "mylib.h"
using namespace std;

int my_atoi(char* s) {
	int result = 0;
	int sign = 1;
	char *current = s;
	if (*s == '-') {
		sign = -1;
		current = s + 1;
	}
	while (*current != '\0') {
		if (*current < '0' || *current > '9') {
			break;
		}
		result = result * 10 + *current - '0';
		current ++;
	}
	result *= sign;
	return result;
}
