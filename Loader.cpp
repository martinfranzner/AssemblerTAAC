#include <fstream>
#include "Loader.hpp"

Loader::Loader() = default;

void Loader::insereMemoria(Memory &m, unsigned int initMemPos, vector<unsigned int> vetorDeInstrucoes) {
  for (auto each : vetorDeInstrucoes) {
    m.getMemoria()->at(initMemPos) = each;
    initMemPos++;
  }
}

