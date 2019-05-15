#include "PrimeHashFunction.hpp"
#include <string>

using namespace std;

string PrimeHashFunction::hash(int list[], int length) {
    long hashVal = 17;
    for(int i = 0; i < length; i++) {
        hashVal = hashVal * 19 + list[i];
    }

    return to_string(hashVal);
}
