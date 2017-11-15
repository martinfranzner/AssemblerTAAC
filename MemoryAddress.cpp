//
// Created by eborsa on 01/11/17.
//

#include "MemoryAddress.h"

int MemoryAddress::getTag() const {
  return tag;
}

int MemoryAddress::getRoll() const {
  return roll;
}

int MemoryAddress::getWord() const {
  return word;
}

void MemoryAddress::setTag(int tag) {
  this->tag = tag;
}

void MemoryAddress::setRoll(int roll) {
  this->roll = roll;
}

void MemoryAddress::setWord(int word) {
  this->word = word;
}

MemoryAddress::MemoryAddress(int tag, int roll, int word) : tag(tag), roll(roll), word(word) {}

MemoryAddress::MemoryAddress() {}
