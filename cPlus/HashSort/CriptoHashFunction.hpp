#include <string>
#include "HashFunction.hpp"

using namespace std;

class CriptoHashFunction: public HashFunction {
	public:
		string hash(int list[], int length);
};
