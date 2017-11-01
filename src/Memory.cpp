//
//  Memory.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Memory.hpp"

Memory::Memory() {
  this->memory = *new vector<int>(16777216);
}

//void Memory::insereMemoria(vector<int> instrucoes, unsigned int posInicMemoria) {
//  for (auto each : instrucoes) {
//    this->memory.at(posInicMemoria) = each;
//    posInicMemoria++;
//  }
//}
