//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CACHE_H
#define TAACCERTO_CACHE_H


#include "../Memory/Memory.hpp"
#include "../MemoryAddres/MemoryAddres.h"
#include "../CacheLine/CacheLine.h"
#include<math.h>
#include <utility>
#include <algorithm>
#include <limits>
#include <bitset>
#include <vector>
#include <string>

using namespace std;
#define BLOCKSIZE 64
#define CACHE_LINES 128

class Cache {
private:
  vector< CacheLine > cacheLines;
  int cacheHitCounter = 0;
  int cacheMissCounter = 0;

public:

  Cache();

  int getCacheHit() const;

  int getCacheMiss() const;

  int getWord(Memory &memory, unsigned long pc);

  void cacheMissEvent(Memory &memory, unsigned long pc, MemoryAddres newAddressRequest);

  int returnWord(MemoryAddres &newAddressRequest);

  void updateCacheLine(Memory &memory, unsigned long pc, const MemoryAddres &newAddressRequest) ;

  void updateMemory(Memory &);
};


#endif //TAACCERTO_CACHE_H
