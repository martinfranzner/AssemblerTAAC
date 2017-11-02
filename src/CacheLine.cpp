//
// Created by eborsa on 01/11/17.
//

#include "CacheLine.h"

int CacheLine::getTag() const {
  return tag;
}

int CacheLine::getRoll() const {
  return roll;
}

int CacheLine::getWord() const {
  return word;
}

void CacheLine::setTag(int tag) {
  this->tag = tag;
}

void CacheLine::setRoll(int roll) {
  this->roll = roll;
}

void CacheLine::setWord(int word) {
  this->word = word;
}

CacheLine::CacheLine(int tag, int roll, int word) : tag(tag), roll(roll), word(word) {}

CacheLine::CacheLine() {}
