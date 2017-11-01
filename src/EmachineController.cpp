#include <fstream>
#include "EmachineController.hpp"

EmachineController::EmachineController() {
  this->instructionVector = *new std::vector<int>();
}

vector<int> EmachineController::getVectorFromFile(const string &instructionsPath) const {
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

void EmachineController::inicia(string caminhoInstructions, int& posicaoIncialMemoria) {
  this->instructionVector = getVectorFromFile(caminhoInstructions);
    Memory m;//= *new Memory();
  m.insereMemoria(instructionVector, posicaoIncialMemoria);
    Executor e ;//= *new Executor();
  e.executar(m.getMemoria(), posicaoIncialMemoria);
}

const vector<int> &EmachineController::getInstructionVector() const {
  return instructionVector;
}

