#include <string>
#include "HashFunction.hpp"

using namespace std;

class PolinomialHashFunction: public HashFunction {
	public:
		string hash(int list[], int length);
};
