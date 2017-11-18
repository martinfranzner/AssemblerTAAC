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

const vector<pair<string, int>> &CacheLine::getWords() const {
  return words;
}

void CacheLine::setWords(const vector<pair<string, int>> &words) {
  CacheLine::words = words;
}

void CacheLine::setWordAt(string word, int value, int position) {
  this->words.at(position).first = word;
  this->words.at(position).second = value;
}

CacheLine::CacheLine() {
  std::pair<string,int> initializer = {"",-1};
  this->tag = "";
  for(int i=0;i<BLOCKSIZE;i++){
    this->words.push_back(initializer);
  }
}
