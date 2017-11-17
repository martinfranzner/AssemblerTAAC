//
// Created by eborsa on 17/11/17.
//

#include "cacheLine.h"


const string &cacheLine::getTag() const {
  return tag;
}

void cacheLine::setTag(const string &tag) {
  cacheLine::tag = tag;
}

const string &cacheLine::getRow() const {
  return row;
}

void cacheLine::setRow(const string &row) {
  cacheLine::row = row;
}

const vector<pair<string, int>> &cacheLine::getWords() const {
  return words;
}

void cacheLine::setWords(const vector<pair<string, int>> &words) {
  cacheLine::words = words;
}
