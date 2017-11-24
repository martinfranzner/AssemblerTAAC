//
// Created by eborsa on 09/11/17.
//

#include <bitset>
#include "MemoryAddress.h"


#define BLOCKSIZE 64

MemoryAddress::MemoryAddress() = default;

const string &MemoryAddress::getTag() const {
  return tag;
}


MemoryAddress::MemoryAddress(int PC) {
  bitset<24> bit = PC;
  string bin = bit.to_string();
  this->word = bin.substr(bin.length() - 6);
  this->tag = bin.substr(0, 11);
  this->row = bin.substr(12, 7);

}

const string &MemoryAddress::getRow() const {
  return row;
}

const string &MemoryAddress::getWord() const {
  return word;
}







