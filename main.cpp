//
//  main.cpp
//  Borsa&MartinAssembler
//
//  Created by Martin Franzner on 19/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include <iostream>
#include "Memory.hpp"
#include "Executor.hpp"
#include "EmachineController.hpp"

#include <vector>
#include <string>

using namespace std;
namespace {
    std::string basePath = "/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Arquitetura Computadores 2/Assembler/";
}
int main(int argc, const char * argv[]) {
    string caminhoInstructions = basePath+"MDCcodificado.txt";
    EmachineController emachine = *new EmachineController();
    Executor executor = * new Executor;
    
    int initPosition = 0;
    emachine.inicia(caminhoInstructions,initPosition);

    return 0;
}
