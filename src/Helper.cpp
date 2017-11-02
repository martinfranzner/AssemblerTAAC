//
// Created by eborsa on 01/11/17.
//

#include <fstream>
#include "Helper.h"

vector<int> Helper::getVectorFromFile(const string &instructionsPath) const {
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