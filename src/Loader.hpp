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
  std::vector<int> instructionVector;
public:
  const vector<int> &getInstructionVector() const;

public:
  Loader();

  void inicia(string caminhoInstructions, int &posicaoIncialMemoria, Memory &mainMemory);

  vector<int> getVectorFromFile(const string &instructionsPath) const;

  void insereMemoria(Memory &m, unsigned int posInicMemoria);
};

#endif /* Inicializador_hpp */
