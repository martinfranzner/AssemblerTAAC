#ifndef Inicializador_hpp
#define Inicializador_hpp

#include "Memory.hpp"
#include "CPU.hpp"

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Loader {
private:
public:
  Loader();

  void insereMemoria(Memory &m, unsigned int initMemPos, vector<unsigned int> vetorDeInstrucoes);
};

#endif /* Inicializador_hpp */
