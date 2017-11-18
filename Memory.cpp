//
//  Memory.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Memory.hpp"

Memory::Memory() {
  this->memory = *new vector<unsigned int>(16777216);
}

vector<int> Memory::grabOnMemory(int t, int r, int w, unsigned int pc){
        int numLinhas = 128;
        int numWords = 64;
        int posIncioBloco = (t*numLinhas*numWords) + r*numWords;
        vector<int> vet(64);
        int j=0;
        for (int i = posIncioBloco; i < 64; i++){
            vet.at(j) = this->memory.at(i);
            j++;
        }
    
    return vet;
}

vector<int> Memory::updateMemory(int t, int r, int w, unsigned int pc, vector<int> vecW){
    int numLinhas = 128;
    int numWords = 64;
    int posIncioBloco = (t*numLinhas*numWords) + r*numWords;
    vector<int> vetReturn(64);
    int j=0;
    for (int i = posIncioBloco; i < 64; i++){ //joga o que ta na memoria para esse vetor
        vetReturn.at(j) = this->memory.at(i);
        j++;
    }
    j=0;
    for (int i = posIncioBloco; i < 64; i++){
        this->memory.at(i) = vecW.at(j);
        j++;
    }
    return vetReturn;
}


//void Memory::insereMemoria(vector<int> instrucoes, unsigned int posInicMemoria) {
//  for (auto each : instrucoes) {
//    this->memory.at(posInicMemoria) = each;
//    posInicMemoria++;
//  }
//}
