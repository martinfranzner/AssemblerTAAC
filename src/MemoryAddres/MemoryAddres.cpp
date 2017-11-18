//
// Created by eborsa on 09/11/17.
//

#include <bitset>
#include "MemoryAddres.h"


#define BLOCKSIZE 64

MemoryAddres::MemoryAddres() {
  std::pair<string,int> initializer = {"",-1};
  this->tag = "";
  for(int i=0;i<BLOCKSIZE;i++){
    this->words.push_back(initializer);
  }
}

const string &MemoryAddres::getTag() const {
  return tag;
}


MemoryAddres::MemoryAddres(int PC) {
  bitset<24> bit = PC;
  string bin = bit.to_string();
  this->word = bin.substr(bin.length() - 6);
  this->tag = bin.substr(0, 11);
  this->row = bin.substr(12, 7);

}

const string &MemoryAddres::getRow() const {
  return row;
}

const string &MemoryAddres::getWord() const {
  return word;
}

void MemoryAddres::setWordAt(const string word, int value, int position) {
  this->words.at(position).first = word;
  this->words.at(position).second = value;
}

const vector<pair<string, int>> &MemoryAddres::getWords() const {
  return words;
}






