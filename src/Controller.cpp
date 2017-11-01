//
// Created by eborsa on 01/11/17.
//

#include "Controller.h"

Controller::Controller() {}

void Controller::inicia(string caminhoInstructions, int &posicaoIncialMemoria) {
  this->loader.inicia(caminhoInstructions, posicaoIncialMemoria, this->memory);
  this->fetcher.fetchInstruction(this->memory, posicaoIncialMemoria);
}

