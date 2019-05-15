//
//  Configuration.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef Configuration_hpp
#define Configuration_hpp

#include <stdio.h>
#include <string>

using namespace std;

#define TOTAL_LIST_NUMBER 1036800
//#define TOTAL_LIST_NUMBER 6

struct Configuration
{
    int arrayLength;
    int distribution;
    double uniqueness;
    int listOrder;
    double copiedElements;
    int blocksLength;
    int debug;
    int memoryCheck;
    
    string toString()
    {
        string str;
        str += "Array_Length: ";
        str += to_string(arrayLength);
        str += " Distribution: ";
        str += to_string(distribution);
        str += " Uniq: ";
        str += to_string(uniqueness);
        str += " Order: ";
        str += to_string(listOrder);
        str += " CopiedElements: ";
        str += to_string(copiedElements);
        str += " blocksLength: ";
        str += to_string(blocksLength);
        
        return str;
    }
};

#endif /* Configuration_hpp */
