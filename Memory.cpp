//
//  Memory.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Memory.hpp"
Memory::Memory(){
    this->memoria = new vector<int>(16777216); // aloca a memoria um vetor de 16 mega cada posicao um tamnho int
}

void Memory::insereMemoria(vector<int> instrucoes, unsigned int posInicMemoria){

    vector<int>::iterator it = this->memoria->begin();
    advance (it,posInicMemoria);
    cout<<"Posicao Inicial Memoria: "<<&it<<endl;
    
    
    vector<int>::iterator at = instrucoes.begin();
    
    while(it != this->memoria->end() && at != instrucoes.end()){
       // this->memoria[i] = instrucoes[j];
        it = at;
        cout<<*it<<endl;
        it++;
        at++;
    }
}
