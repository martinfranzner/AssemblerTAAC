//
// Created by eborsa on 01/11/17.
//

#include "src/catch.hpp"
#include "src/EmachineController.hpp"

using namespace std;

string basePath = "/home/eborsa/CLionProjects/TAAC/martinViadao/AssemblerTAAC/";

SCENARIO("Parte De Cache do Trabalho"){
  GIVEN("Criando uma memoria") {
    WHEN("fazemos qualquer merda") {
      THEN("Coco") {
        REQUIRE(1 == 1);
      }
    }
  }
  WHEN("fazemos qualquer merda") {
    THEN("Coco") {
      string caminhoInstructions = basePath + "MDCcodificado.txt";
      EmachineController emachine;
      Executor executor;
      int initPosition = 0;
      emachine.inicia(caminhoInstructions, initPosition);
      REQUIRE(&emachine != nullptr);
      REQUIRE(&executor != nullptr);
    }
  }
}

