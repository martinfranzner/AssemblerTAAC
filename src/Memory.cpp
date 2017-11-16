//
//  Memory.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Memory.hpp"

Memory::Memory() {
  this->memory.resize(16777216);
}

vector<pair<string, int>> Memory::getRowAndWord(string string1, unsigned int pc){
    string tagMem = "";
    string bin = "";
    string wordMem = "";
    bitset<24> binMem;
    vector<pair<string, int>> cacheWord(64);
    int j = 0;
    for (int i = pc; i < (int)this->memory.size(); i++)
    {
        binMem = i;
        bin = binMem.to_string();
        wordMem = bin.substr(bin.length() - 6);
        tagMem = bin.substr(0, 11);
        if (string1.compare(tagMem) == 0)
        {
            cacheWord.at(j) = *new pair<string, int>(wordMem, this->memory.at(i));
            j++;
        }
        if (j == 64)
            break;
    }
    return cacheWord;
}


