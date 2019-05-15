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
#include "MemoryUtil.cpp"

using namespace std;

int main (int argc,char* argv[]) {
	if(argc < 9) {
        printf("\nNeed to pass array length, distribution, uniqueness, list order, amount of copied elements as paramete, blocks to read, test to execute and debug");
        return 0;
	}
    
    srand (3141618);

    Configuration configuration = {atoi(argv[1]), atoi(argv[2]), strtod(argv[3],NULL), atoi(argv[4]), strtod(argv[5],NULL), atoi(argv[6]), atoi(argv[8])};

    int testType = atoi(argv[7]);
    switch (testType) {
        case 0: {
            printf("Running SortingTest\n");
            SortingTest compTest;
            compTest.run(configuration);
            break;
        }
        case 1:{
            printf("Running HashTest\n");
            HashTest hashTest;
            hashTest.run(configuration);
            break;
        }
        case 2: {
            printf("Running HashingSortTest\n");
            HashingSortTest hashSortTest;
            hashSortTest.run(configuration);
            break;
        }
        case 3: {
            printf("Running SegmentedNaiveTest\n");
            SegmentedNaiveTest segmentedNaiveTest;
            segmentedNaiveTest.run(configuration);
            break;
        }
        case 4: {
            printf("Running SegmentedHashTest\n");
            SegmentedHashTest segmentedHashTest;
            segmentedHashTest.run(configuration);
            break;
        }
        case 5: {
            printf("Running SegmentedOptHashTest\n");
            SegmentedOptHashTest segmentedOptHashTest;
            segmentedOptHashTest.run(configuration);
            break;
        }
        default:
            printf("Running default: %d", testType);
            break;
    }
    
    printf("Exiting");
	return 0;
}
