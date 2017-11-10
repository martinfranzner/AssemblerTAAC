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

using namespace std;

class Cache {
private:
  vector< CacheLine > cacheLines;
  unsigned int position = 0;
  int cacheHit = 0;
  int cacheMiss = 0;


public:
  Cache();

  int consultCache(Memory &memory, unsigned long pc);

  int updateCache(Memory &memory, unsigned int pc);

  void setMemoryAddres(const string &bin, string &word, string &tag, string &row) const;
};


#endif //TAACCERTO_CACHE_H
