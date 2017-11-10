//
// Created by eborsa on 09/11/17.
//

#ifndef TAACCERTO_CACHELINE_H
#define TAACCERTO_CACHELINE_H



#include <iostream>
#include <vector>
using namespace std;

class CacheLine {

  string tag;
  vector<pair<string, int>> rowAndWord;

public:
  const string &getTag() const;

  vector<pair<string, int>> &getRowAmdWord();

  void setTag(const string &tag);

  void setRowAmdWord(const vector<pair<string, int>> &rowAmdWord);

  CacheLine();

  CacheLine(const string &tag, const vector<pair<string, int>> &rowAmdWord);

};


#endif //TAACCERTO_CACHELINE_H
