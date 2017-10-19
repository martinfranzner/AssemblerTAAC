//
//  Executor.hpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 19/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Executor_hpp
#define Executor_hpp
#include "Memory.hpp"
#include <stdio.h>
class Executor {
private:
    int FL,PC;
    int regVet[4];
public:
    Executor();
    void executar(vector<int> memory, int posicaoIncialMemoria);
};
#endif /* Executor_hpp */
