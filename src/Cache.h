//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CACHE_H
#define TAACCERTO_CACHE_H


#include <vector>
#include "CacheLine.h"


class Cache {
  // a memoria tem 16777216bytes
  // a tag sao 2^11 = 2048 blocos
  // Ou seja, essa memoria tem 2048 blocos
  // E cada bloco tem 8192bytes
  // Uma cahce tem 128 linhas
  // cada cache line tem 64 bytes (8192/128)
  // mas os endereços so usarao 24 bytes
  // word com 6bits que eh o conteudo
  // roll que eh qual linha da cache com 7bits
  // tag com 11 bits falando qual bloco da memoria principal
private:
  std::vector<CacheLine> cacheLines;
  int position=0;
public:
  Cache();

  void insertInstrucion(CacheLine newLine);

  const std::vector<CacheLine >* getCacheLines() const ;

  void setCacheLines(const std::vector<CacheLine *> &cacheLines);

  std::vector<CacheLine >* getCacheLinesNotConst();
};





#endif //TAACCERTO_CACHE_H
