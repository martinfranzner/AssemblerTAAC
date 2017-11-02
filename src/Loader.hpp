#ifndef Inicializador_hpp
#define Inicializador_hpp

#include "Memory.hpp"
#include "Fetcher.hpp"

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Loader {
private:
public:
  Loader();

  vector<int> getVectorFromFile(const string &instructionsPath) const;

  void insereMemoria(Memory &m, unsigned int posInicMemoria, vector<int> vetorDeInstrucoes);
};

#endif /* Inicializador_hpp */
