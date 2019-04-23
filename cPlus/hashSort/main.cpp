// basic file operations
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Configuration.hpp"
#include "SortingTest.hpp"
#include "HashingSortTest.hpp"
#include "SegmentedNaiveTest.hpp"
#include "SegmentedHashTest.hpp"
#include "SegmentedOptHashTest.hpp"
#include "HashTest.hpp"

using namespace std;
#define DEBUG_ARRAY 0

int main (int argc,char* argv[]) {
	if(argc < 8) {
        printf("\nNeed to pass array length, distribution, uniqueness, list order, amount of copied elements as paramete, blocks to read, test to execute");
        return 0;
	}

    srand (3141618);

    Configuration configuration = { atoi(argv[1]), atoi(argv[2]), strtod(argv[3],NULL), atoi(argv[4]), strtod(argv[5],NULL),  atoi(argv[6]), DEBUG_ARRAY};

    int testType = atoi(argv[7]);
    switch (testType) {
        case 0: {
            SortingTest compTest;
            compTest.run(configuration);
            break;
        }
        case 1:{
            HashTest hashTest;
            hashTest.run(configuration);
            break;
        }
        case 2: {
            HashingSortTest hashSortTest;
            hashSortTest.run(configuration);
            break;
        }
        case 3: {
            SegmentedNaiveTest segmentedNaiveTest;
            segmentedNaiveTest.run(configuration);
            break;
        }
        case 4: {
            SegmentedHashTest segmentedHashTest;
            segmentedHashTest.run(configuration);
            break;
        }
        case 5: {
            SegmentedOptHashTest segmentedOptHashTest;
            segmentedOptHashTest.run(configuration);
            break;
        }
    }
    
	return 0;
}
