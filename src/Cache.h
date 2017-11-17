//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CACHE_H
#define TAACCERTO_CACHE_H


#include <vector>
#include "Memory.hpp"
#include "MemoryAddres.h"
#include<math.h>
#include <utility>
#include <algorithm>
#include <limits>
#include <string>
#include <bitset>

#define BLOCKSIZE 64

#define CACHE_LINES 128
using namespace std;

class Cache {
private:
  vector< MemoryAddres > cacheLines;
  int cacheHit = 0;
  int cacheMiss = 0;


public:

  int getCacheHit() const;

  int getCacheMiss() const;

  Cache();

  int getWord(Memory &memory, unsigned long pc);

  int updateCache(Memory &memory, unsigned int PC);

  int cachedMissed(Memory &memory, unsigned long pc, unsigned long cacheRow, MemoryAddres newAddressRequest);

  int cacheHitted(unsigned long cacheRow, MemoryAddres &newAddressRequest);
};


#endif //TAACCERTO_CACHE_H
