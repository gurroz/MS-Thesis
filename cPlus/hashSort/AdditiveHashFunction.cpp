#include "AdditiveHashFunction.hpp"
#include <string>

using namespace std;

string AdditiveHashFunction::hash(int list[], int length) {
	string hash;
	int sum = 0;
	for(int i = 0; i < length; i++) {
		sum = sum + list[i];
	}

	return to_string(sum);
}