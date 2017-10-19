//
//  main.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//
//#include "OpenFile.hpp"
//#include "Memory.hpp"

#include "Inicializador.hpp"
#include "Memory.hpp"
#include "OpenFile.hpp"

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    
    string caminhoInstructions = "/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Arquitetura Computadores 2/Assembler/ArquivosCodigos.txt";
    Inicializador *init = new Inicializador(caminhoInstructions, 0);
    

    
    return 0;
}
