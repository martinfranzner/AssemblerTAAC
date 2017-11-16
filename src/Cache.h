//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CACHE_H
#define TAACCERTO_CACHE_H


#include <vector>
#include "Memory.hpp"
#include "CacheLine.h"
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
  vector< CacheLine > cacheLines;
  unsigned int position = 0;
  int cacheHit = 0;
  int cacheMiss = 0;


public:

  int getCacheHit() const;

  int getCacheMiss() const;

  Cache();

  int getWord(Memory &memory, unsigned long pc);

  int updateCache(Memory &memory, unsigned int PC);

  int cachedMissed(Memory &memory, unsigned long pc, const string &word, const string &tag, unsigned long row);

  int cacheHitted(const string &word, const string &tag, unsigned long cacheRow);
};


#endif //TAACCERTO_CACHE_H
