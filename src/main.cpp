#include <iostream>
#include "Memory.hpp"
#include "Fetcher.hpp"
#include "Loader.hpp"

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "Controller.h"

using namespace std;
namespace {
  string basePath = "/home/eborsa/CLionProjects/TAAC/martinViadao/AssemblerTAAC/txtFiles/";
  //std::string basePath = "/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Arquitetura Computadores 2/Assembler/txtFiles";
}

//#define UNIT_TEST_ENABLE
#ifndef UNIT_TEST_ENABLE

int main(int argc, const char *argv[]) {
  string instructionPath = basePath + "MDCcodificado.txt";
  Controller controller;
  int initPosition = 0;
  controller.init(instructionPath, initPosition);

  return 0;
}

#else

int main(int argc, char *argv[]) {
  Catch::Session session; // There must be exactly one instance
  int returnCode;
  returnCode = session.applyCommandLine(argc, reinterpret_cast<const char *const *const>(argv));
  if (returnCode != 0) // Indicates a command line error
    return returnCode;
  int numFailed = session.run();
  return (numFailed < 0xff ? numFailed : 0xff);
}

#endif
