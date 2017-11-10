//
//  Memory.hpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Memory_hpp
#define Memory_hpp
using word = int;
using addres = unsigned int;

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<math.h>
#include <bitset>
#include <utility>
#include <limits>
#include <string>

using namespace std;
class Memory {
private:
    vector<unsigned int> memory;
    
public:
    Memory();
    vector<unsigned int>* getMemoria(){return &this->memory;};
    vector<pair<string, int>> returnToCache(string t, unsigned int pc);
    
};
#endif /* Memory_hpp */
