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
#include <stdio.h>
class Fetcher {
private:
    int FL;
    unsigned int PC;
    std::vector<int> regVet;
public:
    Fetcher();
    void fetchInstruction(Memory &memory, int &posicaoIncialMemoria);
};
#endif /* Executor_hpp */
