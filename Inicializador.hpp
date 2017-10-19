//
//  Inicializador.hpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 14/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Inicializador_hpp
#define Inicializador_hpp

#include "OpenFile.hpp"
#include "Memory.hpp"
#include "Executor.hpp"

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Inicializador {
private:
    
public:
    Inicializador(string caminhoInstructions, int posicaoIncialMemoria);
    
};
#endif /* Inicializador_hpp */
