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

vector<pair<string, int>> Memory::returnToCache(string t, unsigned int pc){
    string tagMem = "";
    string bin = "";
    string wordMem = "";
    
    bitset<24> binMem;
    
    vector<pair<string, int>> c(64);
    int j = 0;
    
    for (int i = pc; i < (int)this->memory.size(); i++)
    {
        binMem = i;
        bin = binMem.to_string();
        wordMem = bin.substr(bin.length() - 6);
        tagMem = bin.substr(0, 11);
        
        if (t.compare(tagMem) == 0)
        {
            c.at(j) = *new pair<string, int>(wordMem, this->memory.at(i));
            j++;
        }
        if (j == 64)
        {
            break;
        }
        
        bin = "";
        wordMem = "";
        tagMem = "";
    }
    
    return c;
}


//void Memory::insereMemoria(vector<int> instrucoes, unsigned int posInicMemoria) {
//  for (auto each : instrucoes) {
//    this->memory.at(posInicMemoria) = each;
//    posInicMemoria++;
//  }
//}
