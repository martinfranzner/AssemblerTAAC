//
//  EmachineController.hpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 14/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef Inicializador_hpp
#define Inicializador_hpp

#include "Memory.hpp"
#include "Executor.hpp"

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class EmachineController {
private:
  std::vector<int> instructionVector;
public:
  const vector<int> &getInstructionVector() const;

public:
  EmachineController();

  void inicia(string caminhoInstructions, int& posicaoIncialMemoria);

  vector<int> getVectorFromFile(const string &instructionsPath) const;
};

#endif /* Inicializador_hpp */
