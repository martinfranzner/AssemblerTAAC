//
// Created by eborsa on 09/11/17.
//

#include "CacheLine.h"


#define BLOCKSIZE 64

CacheLine::CacheLine() {
  this->tag = "";
  std::pair<string,int> initializer = {"",-1};
  for(int i=0;i<BLOCKSIZE;i++){
    this->rowAndWord.push_back(initializer);
  }
}

const string &CacheLine::getTag() const {
  return tag;
}

CacheLine::CacheLine(const string &tag, const vector<pair<string, int>> &rowAmdWord) : tag(tag),
                                                                                       rowAndWord(rowAmdWord) {}

vector<pair<string, int>> &CacheLine::getRowAmdWord()  {
  return rowAndWord;
}

void CacheLine::setTag(const string &tag) {
  CacheLine::tag = tag;
}

void CacheLine::setRowAmdWord(const vector<pair<string, int>> &rowAmdWord) {
  CacheLine::rowAndWord = rowAmdWord;
}



