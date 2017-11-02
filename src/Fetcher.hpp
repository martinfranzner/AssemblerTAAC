//
//  Fetcher.hpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 19/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Executor_hpp
#define Executor_hpp

#include "Memory.hpp"
#include "Cache.h"
#include <stdio.h>

class Fetcher {
private:
  int FL;
  unsigned int PC;
  std::vector<int> regVet;
public:
  Fetcher();

  void fetchInstructionInMemory(Memory &memory, int &posicaoIncialMemoria);

  void fetchInstruction(vector<int> &instructionVector, Cache &cache, Memory &memory, int &posicaoIncialMemoria);

  bool isInCache(int instruction, Cache &cache);

  const pair<bool, int> fetchInCache(int instruction, Cache cache) const;

  void insertInstructionInCache(int &instruction, Memory &memory, Cache &cache);
};

#endif /* Executor_hpp */
