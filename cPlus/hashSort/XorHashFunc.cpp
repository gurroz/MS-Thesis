#include "XorHashFunction.hpp"
#include <string>

using namespace std;

string XorHashFunction::hash(int list[], int length) {
	long hash = 0;
	for(int i = 0; i < length; i++) {
		hash ^= (hash << 5) + (hash >> 2) + list[i];
	}

	return to_string(hash);
}