#include <string>
#include "HashFunction.hpp"

using namespace std;

class AdditiveHashFunction: public HashFunction {
	public:
		string hash(int list[], int length);
};