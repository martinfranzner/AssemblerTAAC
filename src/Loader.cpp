#include <fstream>
#include "Loader.hpp"

Loader::Loader() {
  this->instructionVector = *new std::vector<int>();
}

vector<int> Loader::getVectorFromFile(const string &instructionsPath) const {
  ifstream file;
  string linha="";
  vector<int> instructionsVector;

  file.open(instructionsPath);
  if (file.is_open())
  {
    while (getline(file, linha))
      instructionsVector.push_back(stoi(linha));
    file.close();
  }
  else {
      cout << "Error, Can't Open File";
      throw std::logic_error("Error, Can't Open File");
  }
  return instructionsVector;
}

void Loader::inicia(string caminhoInstructions, int &posicaoIncialMemoria, Memory &mainMemory) {
  this->instructionVector = this->getVectorFromFile(caminhoInstructions);
  this->insereMemoria(mainMemory, posicaoIncialMemoria);
//  Fetcher e ;
//  e.fetchInstruction(*mainMemory.getMemoria(), posicaoIncialMemoria);
}

void Loader::insereMemoria(Memory &m, unsigned int posInicMemoria) {
  for (auto each : this->instructionVector) {
    m.getMemoria()->at(posInicMemoria) = each;
    posInicMemoria++;
  }
}

const vector<int> &Loader::getInstructionVector() const {
  return instructionVector;
}

