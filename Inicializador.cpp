//
//  Inicializador.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 14/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Inicializador.hpp"
Inicializador::Inicializador(string caminhoInstructions, int posicaoIncialMemoria){
    vector<int> instructionsVector;
    
     OpenFile *inst = new OpenFile(caminhoInstructions);
    instructionsVector = inst->toLineString();
    
    
    Memory *m = new Memory();
    m->insereMemoria(instructionsVector, posicaoIncialMemoria);
    Executor *e = new Executor();
    e->executar(*m->getMemoria(), posicaoIncialMemoria);
    
    
}
