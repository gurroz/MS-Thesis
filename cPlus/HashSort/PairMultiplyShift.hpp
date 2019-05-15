#include <string>
#include <random>
#include "HashFunction.hpp"

using namespace std;

class PairMultiplyShift: public HashFunction {
    int a1Constant[512];
	public:
        PairMultiplyShift();
		string hash(int list[], int length);
};
