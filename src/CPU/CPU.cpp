#include "CPU.hpp"

CPU::CPU() {
  this->regVet = *new std::vector<int>(4);
  this->FL = 0;
  this->PC = 0;
}

void CPU::requireInstruction
    (vector<unsigned int> &instructionVector, Cache &cache, Memory &memory, unsigned int &initMemPos)
{
  unsigned int reg1, reg2, mem, imediate;

  this->PC = initMemPos;
  bool status = true;
  int nextInstruction;
  while (status)
  {
      nextInstruction = cache.getWord(memory, PC);
    switch (nextInstruction)
    {
      case 0: // NOP
        PC++;
        break;
      case 1: // HALT
        cout << "Number Of Cache Hit: " << cache.getCacheHit() << "\n";
        cout << "Number Of Cache Miss: " << cache.getCacheMiss() << "\n";
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
        reg2 = cache.getWord(memory, (PC + 1));
        regVet[instructionVector.at(PC)] = reg2;
        PC++; //agora esta no prox reg
        PC++; //agora esta na proxima instrucao
        break;
      case 3: // MOV REG, MEM
        PC++;
        mem = cache.getWord(memory, (PC + 1));
        if(mem > instructionVector.size())
        {
          mem = cache.getWord(memory, PC + 1);
          regVet[instructionVector.at(PC)] = memory.getMemoria()->at(mem);
        }
        else
          cout<<"Erro ao acessar memoria, instrucao MOV REG, MEM"<<endl;
        PC++;
        PC++;
        break;
      case 4: // MOV MEM, REG
        PC++;
        reg1 = cache.getWord(memory, PC + 1);
            memory.getMemoria()->at(memory.getMemoria()->at(PC)) = regVet[reg1];
        PC++;
        PC++;
        break;
      case 5: // MOV REG , IMEDIATE
        PC++;
        imediate = cache.getWord(memory, PC + 1);
        regVet[instructionVector.at(PC)] = imediate;
        PC++;
        PC++;
        break;
      case 6: // MOV MEM, IMEDIATE
        PC++;
        mem = cache.getWord(memory, PC);
        imediate = cache.getWord(memory, PC + 1);
        memory.getMemoria()->at(mem) = imediate;
        PC++;
        PC++;
        break;
      case 7: //ADD REG, REG
        PC++;
        reg1 = cache.getWord(memory, (PC));
        reg2 = cache.getWord(memory, (PC + 1));
        regVet[reg1] = regVet[reg1] + regVet[reg2];
        PC++;
        PC++;
        break;
      case 8: //SUB REG, REG
        PC++;
        reg1 = cache.getWord(memory, (PC));
        reg2 = cache.getWord(memory, (PC + 1));
        regVet[reg1] = regVet[reg1] - regVet[reg2];
        PC++;
        PC++;
        break;
      case 9: //CMP REG, REG
        PC++;
        reg1 = cache.getWord(memory, (PC));
        reg2 = cache.getWord(memory, (PC + 1));
        FL = regVet[reg1] - regVet[reg2];
        PC++;
        PC++;
        break;
      case 10: // JMP
        PC++; // como faz? joga o PC para o valor que vem depois do JMP?? ******
        imediate = cache.getWord(memory, (PC));
        PC = imediate;
            break;
      case 11: // JZ jump if zero
        PC++;
        if (FL == 0)
          PC = PC + cache.getWord(memory, (PC));
        else
          PC++;
        break;
      case 12: // JG jump ig greater
        PC++;
        if (FL > 0)
          PC = PC + cache.getWord(memory, (PC));
        else
          PC++;
        break;
      case 13: // JL jump ig greater
        PC++;
        if (FL < 0) {
          PC = PC + cache.getWord(memory, (PC));
        }
        else {
          PC++;
        }
        break;
      case 14: // OUT REG
        PC++;
        if (cache.getWord(memory, (PC)) == 0) { // OUT AX: ...
          cout << "AX " << regVet[0] << endl;
        }
        else if (cache.getWord(memory, (PC)) == 1) { // OUT BX: ...
          cout << "BX " << regVet[1] << endl;
        }
        else if (cache.getWord(memory, (PC)) == 2) { // OUT CX: ...
          cout << "CX " << regVet[2] << endl;
        }
        else if (cache.getWord(memory, (PC)) == 3) { // OUT CX: ...
          cout << "DX " << regVet[3] << endl;
        }
        else {
          cout << "Erro no comando OUT" << endl;
        }
        PC++;
        break;
      case 15: // INC REG
        PC++;
        reg1 = cache.getWord(memory, (PC));
        regVet[reg1] = regVet[reg1] + 1;
        PC++;
        break;
      case 16: // DEC REG
        PC++;
        reg1 = cache.getWord(memory, (PC));
        regVet[reg1] = regVet[reg1] - 1;
        PC++;
        break;
      case 17: // MUL REG, REG
        PC++;
        reg1 = cache.getWord(memory, (PC));
        reg2 = cache.getWord(memory, (PC + 1));
        regVet[reg1] = regVet[reg1]*regVet[reg2];
        PC++;
        PC++;
        break;
      case 18: // DIV REG, REG
        PC++;
        reg1 = cache.getWord(memory, (PC));
        reg2 = cache.getWord(memory, (PC + 1));
        regVet[reg1] = regVet[reg1]/regVet[reg2];
        PC++;
        PC++;
        break;
      default:
        break;
    }
  }
  initMemPos = PC;
}




