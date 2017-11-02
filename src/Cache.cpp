//
// Created by eborsa on 01/11/17.
//

#include "Cache.h"

Cache::Cache() {
  for(int i=0;i<128;i++){
    CacheLine bla (-1,-1,-1);
    this->cacheLines.push_back(bla);
  }

}

const std::vector<CacheLine>* Cache::getCacheLines() const  {
  return &cacheLines;
}


void Cache::insertInstrucion(CacheLine newLine) {
  if(position==128){
    position=0;
  }else {
    newLine.setRoll(position);
    this->getCacheLinesNotConst()->at(position) = newLine;
    position++;
  }
}

std::vector<CacheLine >* Cache::getCacheLinesNotConst() {
  return &this->cacheLines;
}





