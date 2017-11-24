//
// Created by eborsa on 09/11/17.
//

#ifndef TAACCERTO_CACHELINE_H
#define TAACCERTO_CACHELINE_H


#include <iostream>
#include <vector>

using namespace std;

class MemoryAddress {

  string tag;
  string row;
  string word;

public:

  const string &getRow() const;

  const string &getWord() const;

  const string &getTag() const;

  MemoryAddress();

  MemoryAddress(int PC);
};


#endif //TAACCERTO_CACHELINE_H
