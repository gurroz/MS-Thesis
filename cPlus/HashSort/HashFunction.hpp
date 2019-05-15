#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

#include <string>
using namespace std;

class HashFunction {
	public:
		virtual string hash(int list[], int length) = 0;
};
#endif
