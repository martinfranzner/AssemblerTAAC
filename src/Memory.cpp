//
//  Memory.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Memory.hpp"

Memory::Memory() {
  this->wordsInMemory.resize(16777216);
}

vector<pair<string, int>> Memory::getMemoryAddres(string searchedTag, unsigned int pc) {
  string memoryBlockTag = "";
  string binary = "";
  string wordAddrresInMemory = "";
  int wordValue = -1;
  bitset<24> binMem;
  vector<pair<string, int>> cacheLine(64);
  int j = 0;
  for (int wordPosition = pc; wordPosition < this->wordsInMemory.size(); wordPosition++)
  {
    binMem = wordPosition;
    binary = binMem.to_string();
    wordAddrresInMemory = binary.substr(binary.length() - 6);
    memoryBlockTag = binary.substr(0, 11);
    if (searchedTag == memoryBlockTag)
    {
//      Aqui atualiza as palavras
      wordValue = this->wordsInMemory.at(wordPosition);
      cacheLine.at(j) = {wordAddrresInMemory, wordValue};
      j++;
    }
    if (j == 64)
      break;
  }
  return cacheLine;
}

MemoryAddres Memory::getMemoryAddres2(string searchedTag, unsigned int pc) {
  string memoryBlockTag = "";
  string binary = "";
  string wordAddrresInMemory = "";
  int wordValue = -1;
  bitset<24> binMem;
  MemoryAddres cacheLine;
  int j = 0;
  for (int wordPosition = pc; wordPosition < this->wordsInMemory.size(); wordPosition++)
  {
    binMem = wordPosition;
    binary = binMem.to_string();
    wordAddrresInMemory = binary.substr(binary.length() - 6);
    memoryBlockTag = binary.substr(0, 11);
    if (searchedTag == memoryBlockTag)
    {
//      Aqui atualiza as palavras
      wordValue = this->wordsInMemory.at(wordPosition);
      cacheLine.setWordAt(wordAddrresInMemory,wordValue,j);
      j++;
    }
    if (j == 64)
      break;
  }
  return cacheLine;

//  string memoryBlockTag = "";
//  string binary = "";
//  string wordInMemory = "";
//  int wordInMainMemory = -1;
//  bitset<24> binMem;
//  MemoryAddres CacheLine;
//  int j = 0;
//  for (int wordPosition = pc; wordPosition < this->wordsInMemory.size(); wordPosition++)
//  {
//    binMem = wordPosition;
//    binary = binMem.to_string();
//    wordInMemory = binary.substr(binary.length() - 6);
//    memoryBlockTag = binary.substr(0, 11);
//    if (searchedTag == memoryBlockTag)
//    {
//      wordInMainMemory = this->wordsInMemory.at(wordPosition);
//      CacheLine.setWordAt(to_string(wordInMainMemory),j);
//      j++;
//    }
//    if (j == 64)
//      break;
//  }
//  return CacheLine;
}



