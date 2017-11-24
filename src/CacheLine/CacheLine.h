//
// Created by eborsa on 17/11/17.
//

#ifndef TAACCERTO_CACHELINE_H
#define TAACCERTO_CACHELINE_H
#include <vector>
#include <string>

using namespace std;
#define BLOCKSIZE 64

class CacheLine {
  string tag;
  string row;
  vector<pair<string, int>> words;
public:
  CacheLine();

  const string &getRow() const;

  void setRow(const string &row);

  const string &getTag() const;

  void setTag(const string &tag);

  const vector<pair<string, int>> &getWords() const;

  void setWords(const vector<pair<string, int>> &words);

  void setWordAt(string word, int value, int position);

};

#endif //TAACCERTO_CACHELINE_H
