#include <string>
#include "HashFunction.hpp"

using namespace std;

class PrimeHashFunction: public HashFunction {
	public:
		string hash(int list[], int length);
};