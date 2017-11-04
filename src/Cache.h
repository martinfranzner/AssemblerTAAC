//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CACHE_H
#define TAACCERTO_CACHE_H


#include <vector>
#include "MemoryAddress.h"
#include "Memory.hpp"

#define BLOCKSIZE 64


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
  std::vector<MemoryAddress> cacheLines;
  int position=0;
  int cacheHit = 0;
  int cacheMiss=0;
public:
  Cache();

  void insertInstruction(MemoryAddress newLine);

  const std::vector<MemoryAddress >* getCacheLines() const ;

  std::vector<MemoryAddress >* getCacheLinesNotConst();

  int fetchInstruction(unsigned int &instruction, Memory &memory);

  bool isInCache(int instruction);

  void insertInstructionInCache(unsigned int &instruction, Memory &memory);

  const pair<bool, int> fetchInCache(int instruction) const;

};





#endif //TAACCERTO_CACHE_H
