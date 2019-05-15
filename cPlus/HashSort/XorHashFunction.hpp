#include <string>
#include "HashFunction.hpp"

using namespace std;

class XorHashFunction: public HashFunction {
	public:
		string hash(int list[], int length);
};