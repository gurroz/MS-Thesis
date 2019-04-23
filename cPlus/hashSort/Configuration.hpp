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

//#define TOTAL_LIST_NUMBER 1036800
#define TOTAL_LIST_NUMBER 4

struct Configuration
{
    int arrayLength;
    int distribution;
    double uniqueness;
    int listOrder;
    double copiedElements;
    int blocksLength;
    int debug;
    
    string toString()
    {
        string str;
        str += "Array_Length: ";
        str += arrayLength;
        str += " Distribution: ";
        str += distribution;
        str += " Uniq: ";
        str += uniqueness;
        str += " Order: ";
        str += listOrder;
        str += " CopiedElements: ";
        str += copiedElements;
        str += " blocksLength: ";
        str += blocksLength;
        
        return str;
    }
};

#endif /* Configuration_hpp */
