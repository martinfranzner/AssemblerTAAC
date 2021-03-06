//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CONTROLLER_H
#define TAACCERTO_CONTROLLER_H


#include "../Loader/Loader.hpp"
#include "../Helper/Helper.h"
#include "../Memory/Memory.hpp"
#include "../Cache/Cache.h"
#include "../CPU/CPU.hpp"

class Controller {

  Loader loader;
  CPU cpu;
  Memory memory;
  Helper helper;
  Cache cache;
  vector<unsigned int> instructionVector;

public:
  Controller();

  void init(string instructionPath, unsigned int &memInitPos);

};


#endif //TAACCERTO_CONTROLLER_H
