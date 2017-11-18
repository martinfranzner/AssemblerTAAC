//
//  Memory.hpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Memory_hpp
#define Memory_hpp
using word = int;
using addres = unsigned int;

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<math.h>
#include <bitset>
#include <utility>
#include <limits>
#include <string>
#include "../MemoryAddres/MemoryAddres.h"
#include "../CacheLine/CacheLine.h"

using namespace std;

class CacheLine{
  string tag;
  string row;
  vector<pair<string, int>> words;
public:
  const string &getTag() const;

  void setTag(const string &tag);

  const vector<pair<string, int>> &getWords() const;

  void setWords(const vector<pair<string, int>> &words);

  void setWordAt(string word, int value, int position);
};

class Memory
{
private:
    vector<unsigned int> wordsInMemory;
    
public:
  Memory();
  vector<unsigned int>* getMemoria(){return &this->wordsInMemory;};
  CacheLine getMemoryAddres(string searchedTag, unsigned int pc);
    
};
#endif /* Memory_hpp */
