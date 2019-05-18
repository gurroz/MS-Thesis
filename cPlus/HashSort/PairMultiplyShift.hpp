#include <string>
#include <random>
#include "HashFunction.hpp"

using namespace std;

class PairMultiplyShift: public HashFunction {
    uint64_t a1Constant[512];
    uint64_t a2Constant[512];

	public:
        PairMultiplyShift();
		string hash(int list[], int length);
};
