//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_HELPER_H
#define TAACCERTO_HELPER_H

#include <iostream>
#include <vector>
using namespace std;

class Helper {
public:
  Helper();
  vector<unsigned int> getVectorFromFile(string instructionsPath);

};


#endif //TAACCERTO_HELPER_H
