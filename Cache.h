//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CACHE_H
#define TAACCERTO_CACHE_H


#include <vector>
#include "MemoryAddress.h"
#include "Memory.hpp"
#include<math.h>
#include <utility>
#include <algorithm>
#include <limits>
#include <string>
#include <bitset>
#define BLOCKSIZE 64

using namespace std;

struct CacheStruct {
    int tag;
    int row;
    vector<int> word = *new vector<int>(64);
};

class Cache {
  // a memoria tem 16777216bytes
  // a tag sao 2^11 = 2048 blocos
  // Ou seja, essa memoria tem 2048 blocos
  // E cada bloco tem 64 linhas!!!!!! <<<<<<-------
  // Uma cahce tem 128 linhas
  // mas os endereços so usarao 24 bytes     <------
  // A roll eh a posicao no bloco !!!!! E nao na cache
  // todas aqueles que tem a mesma roll caem na mesma cashe line
  // word com 6bits que eh o conteudo
  // roll que eh qual linha da cache com 7bits
  // tag com 11 bits falando qual bloco da memoria principal
  // na cacheline so tem a tag
private:
    
  //vector<pair<string, vector<pair<string, int>>>> cache;
  unsigned int position=0;
  int cacheHit = 0;
  int cacheMiss=0;
  vector<CacheStruct> cache;
    
public:
  Cache();
  int verifyCache(Memory &memory, int pc);
    
};





#endif //TAACCERTO_CACHE_H
