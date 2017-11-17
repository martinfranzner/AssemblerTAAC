//
// Created by eborsa on 17/11/17.
//

#include "CacheLine.h"


const string &CacheLine::getTag() const {
  return tag;
}

void CacheLine::setTag(const string &tag) {
  CacheLine::tag = tag;
}

const string &CacheLine::getRow() const {
  return row;
}

void CacheLine::setRow(const string &row) {
  CacheLine::row = row;
}

const vector<pair<string, int>> &CacheLine::getWords() const {
  return words;
}

void CacheLine::setWords(const vector<pair<string, int>> &words) {
  CacheLine::words = words;
}
