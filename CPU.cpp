#include "CPU.hpp"

CPU::CPU() {
  this->regVet = *new std::vector<int>(4);
  this->FL = 0;
  this->PC = 0;
}

void
CPU::requireInstruction(vector<unsigned int> &instructionVector, Cache &cache, Memory &memory, unsigned int &initMemPos) {
  unsigned int reg1,reg2,mem, imediate;

  this->PC = initMemPos;
  bool status = true;
  int nextInstruction;
  while (status){
    //nextInstruction = cache.fetchInstruction(instructionVector.at(PC), memory);
      nextInstruction = cache.verifyCache(memory, PC);
    switch (nextInstruction){
      case 0: // NOP
        PC++;
        break;
      case 1: // HALT
        cout<< "Deseja continuar? 1 or 0\n"<<endl;
        cin >> status;
        if(status==0) {
          cout << "fim do programa"<<endl;
          break;
        }
        else
          PC++;
        break;
      case 2: //MOV REG, REG
        PC++; //vai da instrucao pros registradores

        reg1 = cache.verifyCache(memory, PC);
        reg2 = cache.verifyCache(memory, (PC+1));
        regVet[reg1] = regVet[reg2];


        //regVet[instructionVector.at(PC)] = regVet[instructionVector.at(PC + 1)]; // pega o valor que esta no vetor de registrador da memory
        PC++; //agora esta no prox reg
        PC++; //agora esta na proxima instrucao
        break;
      case 3: // MOV REG, MEM
        PC++;

        reg1 = cache.verifyCache(memory, (PC));
        mem =  cache.verifyCache(memory, (PC+1));
        regVet[reg1] = memory.getMemoria()->at(mem);
        
        //regVet[memory.getMemoria()->at(PC)] = memory.getMemoria()->at(memory.getMemoria()->at(PC + 1));   // duvida se joga direto o da memory ou o que?? *******
        PC++;//agora esta na MEM
        PC++;//agora esta na proxima instrucao
        break;
      case 4: // MOV MEM, REG
        PC++;
        reg1 = cache.verifyCache(memory, PC +1);
            memory.getMemoria()->at(memory.getMemoria()->at(PC)) = regVet[reg1];

        //memory.getMemoria()->at(memory.getMemoria()->at(PC)) = regVet[memory.getMemoria()->at(PC + 1)];
        PC++;
        PC++;
        break;
      case 5: // MOV REG , IMEDIATE
        PC++;
        reg1 = cache.verifyCache(memory, PC);
        imediate = cache.verifyCache(memory, PC +1);
            regVet[reg1] = imediate;
            //regVet[instructionVector.at(PC)] = imediate;
        //regVet[memory.getMemoria()->at(PC)] = memory.getMemoria()->at(PC + 1);
        PC++;
        PC++;
        break;
      case 6: // MOV MEM, IMEDIATE
        PC++;
        mem = cache.verifyCache(memory,PC);
        imediate = cache.verifyCache(memory, PC +1);
        memory.getMemoria()->at(mem) = imediate;
        PC++;
        PC++;
        break;
      case 7: //ADD REG, REG
        PC++;
        reg1 = cache.verifyCache(memory, (PC));
        reg2 = cache.verifyCache(memory, (PC+1));
        regVet[reg1] = regVet[reg1] + regVet[reg2];
        

        //regVet[memory.getMemoria()->at(PC)] += regVet[memory.getMemoria()->at(PC + 1)];
        PC++;
        PC++;
        break;
      case 8: //SUB REG, REG
        PC++;
        reg1 = cache.verifyCache(memory, (PC));
        reg2 = cache.verifyCache(memory, (PC+1));
        regVet[reg1] = regVet[reg1] - regVet[reg2];
    


        //regVet[memory.getMemoria()->at(PC)] = regVet[memory.getMemoria()->at(PC)] - regVet[memory.getMemoria()->at(PC + 1)];
        PC++;
        PC++;
        break;
      case 9: //CMP REG, REG
        PC++;
        reg1 = cache.verifyCache(memory, (PC));
        
        reg2 = cache.verifyCache(memory, (PC+1));
        FL = regVet[reg1] - regVet[reg2];


        //FL = regVet[memory.getMemoria()->at(PC)] - regVet[memory.getMemoria()->at(PC + 1)];
        PC++;
        PC++;
        break;
      case 10: // JMP
        PC++; // como faz? joga o PC para o valor que vem depois do JMP?? ******
        imediate = cache.verifyCache(memory, (PC));
        PC = imediate;
            break;
      case 11: // JZ jump if zero
        PC++;
        if (FL == 0) {
          PC = PC + cache.verifyCache(memory, (PC));
        } else {
          PC++;
        }
        break;
      case 12: // JG jump ig greater
        PC++;
        if (FL > 0) {
          PC = PC + cache.verifyCache(memory, (PC));
        } else {
          PC++;
        }
        break;
      case 13: // JL jump ig greater
        PC++;
        if (FL < 0) {
          PC = PC + cache.verifyCache(memory, (PC));
        } else {
          PC++;
        }
        break;
      case 14: // OUT REG
        PC++;
        // cout<<"Entrou no case OUT, valor PC dps de ++: "<<endl;
        if (cache.verifyCache(memory, (PC)) == 0) { // OUT AX: ...
          cout << "AX " << regVet[0] << endl;
        } else if (cache.verifyCache(memory, (PC)) == 1) { // OUT BX: ...
          cout << "BX " << regVet[1] << endl;
        } else if (cache.verifyCache(memory, (PC)) == 2) { // OUT CX: ...
          cout << "CX " << regVet[2] << endl;
        } else if (cache.verifyCache(memory, (PC)) == 3) { // OUT CX: ...
          cout << "DX " << regVet[3] << endl;
        } else {
          cout << "Erro no comando OUT" << endl;
        }
        PC++;
        break;
      case 15: // INC REG
        PC++;
        reg1 = cache.verifyCache(memory, (PC));
        regVet[reg1] = regVet[reg1] + 1;

        //regVet[memory.getMemoria()->at(PC)] = regVet[memory.getMemoria()->at(PC)] + 1;
        PC++;
        break;
      case 16: // DEC REG
        PC++;
        reg1 = cache.verifyCache(memory, (PC));
        regVet[reg1] = regVet[reg1] - 1;

        //regVet[memory.getMemoria()->at(PC)] = regVet[memory.getMemoria()->at(PC)] - 1;
        PC++;
        break;
      case 17: // MUL REG, REG
        PC++;
        reg1 = cache.verifyCache(memory, (PC));
        reg2 = cache.verifyCache(memory, (PC+1));

        regVet[reg1] = regVet[reg1]*regVet[reg2];

        //regVet[memory.getMemoria()->at(PC)] = regVet[memory.getMemoria()->at(PC)] * regVet[memory.getMemoria()->at(PC + 1)];
        PC++;
        PC++;
        break;
      case 18: // DIV REG, REG
        PC++;
        reg1 = cache.verifyCache(memory, (PC));
        reg2 = cache.verifyCache(memory, (PC+1));
        regVet[reg1] = regVet[reg1]/regVet[reg2];

            //regVet[memory.getMemoria()->at(PC)] = regVet[memory.getMemoria()->at(PC)] / regVet[memory.getMemoria()->at(PC + 1)];
        PC++;
        PC++;
        break;
      default:
        break;
    }
  }
  initMemPos = PC;
}




