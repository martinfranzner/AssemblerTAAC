//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CONTROLLER_H
#define TAACCERTO_CONTROLLER_H


#include "Loader.hpp"

class Controller {

  Loader loader;
  Fetcher fetcher;
  Memory memory;

public:
  Controller();

  void inicia(string caminhoInstructions, int& posicaoIncialMemoria);

};


#endif //TAACCERTO_CONTROLLER_H
