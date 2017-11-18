//
// Created by eborsa on 09/11/17.
//

#ifndef TAACCERTO_CACHELINE_H
#define TAACCERTO_CACHELINE_H


#include <iostream>
#include <vector>

using namespace std;

class MemoryAddres {

  string tag;
  string row;
  string word;
  vector<pair<string, int>> words;

public:
  const vector<pair<string, int>> &getWords() const;


  void setWordAt(string word, int value, int position);

  const string &getRow() const;

  const string &getWord() const;

  const string &getTag() const;


  MemoryAddres();

  MemoryAddres(int PC);
};


#endif //TAACCERTO_CACHELINE_H
