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

//    vector<int>::iterator it = this->memoria->begin();
//    advance (it,posInicMemoria);
//    //cout<<"Posicao Inicial Memoria: "<<&it<<endl;
//
//
//    vector<int>::iterator at = instrucoes.begin();
//
//    while(it != this->memoria->end() && at != instrucoes.end()){
//       // this->memoria[i] = instrucoes[j];
//        this->memoria = &instrucoes;
//        it = at;
//        //cout<<*it<<endl;
//        it++;
//        at++;
//    }
    
    // ***** velho, preciso jogar o conteudo de cada posicao no vetor instrucoes pra a partir da posicao incial no vetor memoria cada um seu conteudo, deve ser muito bobo, mas nao vai *******
    int j = posInicMemoria;
    auto itt = this->memoria->begin();
    auto att = instrucoes.begin();
    while(itt != this->memoria->end() && att != instrucoes.end()){
        this->memoria->at(j) = *att;
        cout<<*itt<<endl;
        j++;
        itt++;
        att++;
    }
    
    
    
    
    
//    for (auto t = memoria->begin(); t != memoria->end(); t++) {
//        cout << *t << endl;
//    }
    
    
    
    
}
