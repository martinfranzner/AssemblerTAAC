//
// Created by eborsa on 01/11/17.
//

#include "Controller.h"

Controller::Controller() {}

void Controller::init(string instructionPath, int &memInitPos) {
  this->instructionVector = helper.getVectorFromFile(instructionPath);
  this->loader.insereMemoria(this->memory, memInitPos,instructionVector );
//  this->fetcher.fetchInstructionInMemory(this->memory, memInitPos);
  this->fetcher.fetchInstruction(this->instructionVector, this->cache, this->memory, memInitPos);
}

