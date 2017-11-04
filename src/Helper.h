//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_HELPER_H
#define TAACCERTO_HELPER_H

#include <iostream>
#include "vector"
using namespace std;

class Helper {
public:

  vector<unsigned int> getVectorFromFile(const string &instructionsPath) const;

};


#endif //TAACCERTO_HELPER_H
