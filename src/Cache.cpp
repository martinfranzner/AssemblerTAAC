//
// Created by eborsa on 01/11/17.
//

#include <termcap.h>
#include "Cache.h"

Cache::Cache() {
  for(int i=0;i<128;i++){
    MemoryAddress bla (-1,-1,-1);
    this->cacheLines.push_back(bla);
  }

}

const std::vector<MemoryAddress>* Cache::getCacheLines() const  {
  return &cacheLines;
}


void Cache::insertInstruction(MemoryAddress newLine) {
  if(position==128){
    position=0;
  }else {
    this->getCacheLinesNotConst()->at(position) = newLine;
    position++;
  }
}

std::vector<MemoryAddress >* Cache::getCacheLinesNotConst() {
  return &this->cacheLines;
}

int Cache::fetchInstruction(unsigned int &instruction, Memory &memory) {
  if(!isInCache(instruction)) // Cache miss
  {                                               // A cache faz isso
    this->cacheMiss++;
    insertInstructionInCache(instruction, memory);
  }
  else{
    this->cacheHit++;
  }
  return fetchInCache(instruction).second;
}

bool Cache::isInCache(int instruction) {
  for (int i=0; i<this->getCacheLines()->size();i++) {
    if(this->getCacheLines()->at(i).getWord() == instruction){
      return true;
    }
  }
  return false;
}

void Cache::insertInstructionInCache(unsigned int &instruction, Memory &memory) {
  for (int i=0; i<memory.getMemoria()->size();i++) {
    if(memory.getMemoria()->at(i) == instruction){
      MemoryAddress address;
      address.setWord(memory.getMemoria()->at(i));
      address.setTag(static_cast<int>((i/memory.getMemoria()->size())*BLOCKSIZE));
      address.setRoll(i%BLOCKSIZE);
      this->insertInstruction(address);
      break;
    }
  }
}

const pair<bool, int> Cache::fetchInCache(int instruction) const {
  for (int i=0; i<this->getCacheLines()->size();i++) {
    if(this->getCacheLines()->at(i).getWord() == instruction){
      return {true, this->getCacheLines()->at(i).getWord()};
    }
  }
  return {false,-1};
}





