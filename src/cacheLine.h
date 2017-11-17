//
// Created by eborsa on 17/11/17.
//

#ifndef TAACCERTO_CACHELINE_H
#define TAACCERTO_CACHELINE_H

#include <iostream>
#include <vector>

using namespace std;

class cacheLine {
  string tag;
  string row;
  vector<pair<string, int>> words;
public:
  const string &getTag() const;

  void setTag(const string &tag);

  const string &getRow() const;

  void setRow(const string &row);

  const vector<pair<string, int>> &getWords() const;

  void setWords(const vector<pair<string, int>> &words);
};


#endif //TAACCERTO_CACHELINE_H
