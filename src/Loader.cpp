#include <fstream>
#include "Loader.hpp"

Loader::Loader() {
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

void Loader::insereMemoria(Memory &m, unsigned int posInicMemoria, vector<int> vetorDeInstrucoes) {
  for (auto each : vetorDeInstrucoes) {
    m.getMemoria()->at(posInicMemoria) = each;
    posInicMemoria++;
  }
}

