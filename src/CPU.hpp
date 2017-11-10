//
//  CPU.hpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 19/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Executor_hpp
#define Executor_hpp



#include "Memory.hpp"
#include "Cache.h"
#include <cstdio>

class CPU {
private:
  int FL;
  unsigned int PC;
  std::vector<int> regVet;
public:
  CPU();

  void requireInstruction(vector<unsigned int> &instructionVector, Cache &cache, Memory &memory, unsigned int &initMemPos);

};

#endif /* Executor_hpp */
