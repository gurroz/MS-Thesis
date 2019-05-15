#include "PolinomialHashFunction.hpp"
#include <string>
#include <math.h>       /* pow */


using namespace std;

string PolinomialHashFunction::hash(int list[], int length) {
	long hashVal = 0;
	for(int i = 0; i < length; i++) {
		hashVal = hashVal + list[i];
	}

	return to_string(hashVal);
}
