//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CONTROLLER_H
#define TAACCERTO_CONTROLLER_H


#include "Loader.hpp"
#include "Helper.h"

class Controller {

  Loader loader;
  Fetcher fetcher;
  Memory memory;
  Helper helper;
  Cache cache;
  vector<int> instructionVector;

public:
  Controller();

  void init(string instructionPath, int &memInitPos);

};


#endif //TAACCERTO_CONTROLLER_H
