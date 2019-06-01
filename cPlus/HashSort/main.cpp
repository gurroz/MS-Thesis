// basic file operations
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Configuration.hpp"
#include "SortingTest.hpp"
#include "HashingSortTest.hpp"
#include "OptSortingTest.hpp"
#include "SegmentedNaiveTest.hpp"
#include "SegmentedHashTest.hpp"
#include "SegmentedOptHashTest.hpp"

#include "HashTest.hpp"
#include "HashTableTest.hpp"

#include "MemoryUtil.cpp"

using namespace std;

int main (int argc,char* argv[]) {
	if(argc < 10) {
        printf("\nNeed to pass array length, distribution, uniqueness, list order, amount of copied elements as paramete, blocks to read, test to execute, debug and memory check");
        return 0;
	}
    
    srand (3141618);

    Configuration configuration = {atoi(argv[1]), atoi(argv[2]), strtod(argv[3],NULL), atoi(argv[4]), strtod(argv[5],NULL), atoi(argv[6])
        , atoi(argv[8]), atoi(argv[9])};

    if(atoi(argv[8])) { // Debug
        cout << "Length: " <<  atoi(argv[1]) << " Dist: " << atoi(argv[2]) << " UNIQ: " << strtod(argv[3],NULL) << " ORDER: " << atoi(argv[4]) <<  " COPIES: " << strtod(argv[5],NULL) << " BLOCKS: " << atoi(argv[6]) << " TEST: " << atoi(argv[7]) << " DEBUG: " << atoi(argv[8]) << " MEMORY: " <<  atoi(argv[9]) << endl;
    }
    
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
        case 6: {
            printf("Running HashTableTest\n");
            HashTableTest hasTableTest;
            hasTableTest.run(configuration);
            break;
        }
        case 7: {
            printf("Running OptSortingTest\n");
            OptSortingTest optSortingTest;
            optSortingTest.run(configuration);
            break;
        }
        default:
            printf("Running default: %d", testType);
            break;
    }
    
    printf("Exiting\n\n");
	return 0;
}
