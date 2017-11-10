//
// Created by eborsa on 09/11/17.
//

#include "CacheLine.h"




CacheLine::CacheLine() {
  this->tag = "";

}

const string &CacheLine::getTag() const {
  return tag;
}

CacheLine::CacheLine(const string &tag, const vector<pair<string, int>> &rowAmdWord) : tag(tag),
                                                                                       rowAmdWord(rowAmdWord) {}

vector<pair<string, int>> &CacheLine::getRowAmdWord()  {
  return rowAmdWord;
}

void CacheLine::setTag(const string &tag) {
  CacheLine::tag = tag;
}

void CacheLine::setRowAmdWord(const vector<pair<string, int>> &rowAmdWord) {
  CacheLine::rowAmdWord = rowAmdWord;
}



