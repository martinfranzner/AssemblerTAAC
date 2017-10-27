#include "Executor.hpp"

Executor::Executor() {
  this->regVet = *new std::vector<int>(4);
  this->FL = 0;
  this->PC = 0;
}

void Executor::executar(vector<int> memory, int& posicaoIncialMemoria) {
  this->PC = posicaoIncialMemoria;
  bool status = true;
  while (status) {
      //cout << "O que tem na posicao: "<<PC <<"da memoria= "<< memory[PC] << endl;
    switch (memory[PC]) {
      case 0:
        PC++;
        break;
      case 1:
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
        PC++;//vai da instrucao pros registradores
        regVet[memory[PC]] = regVet[memory[PC + 1]]; // pega o valor que esta no vetor de registrador da memory
        PC++;//agora esta no prox reg
        PC++;//agora esta na proxima instrucao
        break;
      case 3: // MOV REG, MEM
        PC++;
        regVet[memory[PC]] = memory[memory[PC + 1]];   // duvida se joga direto o da memory ou o que?? *******
        PC++;//agora esta na MEM
        PC++;//agora esta na proxima instrucao
        break;
      case 4: // MOV MEM, REG
        PC++;
        memory[memory[PC]] = regVet[memory[PC + 1]];
        PC++;
        PC++;
        break;
      case 5: // MOV REG , IMEDIATE
        PC++;
        regVet[memory[PC]] = memory[PC + 1];
        PC++;
        PC++;
        break;
      case 6: // MOV MEM, IMEDIATE
        PC++;
        memory[memory[PC]] = memory[PC + 1];
        PC++;
        PC++;
        break;
      case 7: //ADD REG, REG
        PC++;
        regVet[memory[PC]] += regVet[memory[PC + 1]];
        PC++;
        PC++;
        break;
      case 8: //SUB REG, REG
        PC++;
        regVet[memory[PC]] = regVet[memory[PC]] - regVet[memory[PC + 1]];
        PC++;
        PC++;
        break;
      case 9: //CMP REG, REG
        PC++;
        FL = regVet[memory[PC]] - regVet[memory[PC + 1]];
        PC++;
        PC++;
        break;
      case 10: // JMP
        PC++; // como faz? joga o PC para o valor que vem depois do JMP?? ******
        PC = memory[PC];
        break;
      case 11: // JZ jump if zero
        PC++;
        if (FL == 0) {
          PC = PC + memory[PC];
        } else {
          PC++;
        }
        break;
      case 12: // JG jump ig greater
        PC++;
        if (FL > 0) {
          PC = PC + memory[PC];
        } else {
          PC++;
        }
        break;
      case 13: // JL jump ig greater
        PC++;
        if (FL < 0) {
          PC = PC + memory[PC];
        } else {
          PC++;
        }
        break;
      case 14: // OUT REG
        PC++;
           // cout<<"Entrou no case OUT, valor PC dps de ++: "<<endl;
        if (memory[PC] == 0) { // OUT AX: ...
          cout << "AX " << regVet[memory[PC]] << endl;
        } else if (memory[PC] == 1) { // OUT BX: ...
          cout << "BX " << regVet[memory[PC]] << endl;
        } else if (memory[PC] == 2) { // OUT CX: ...
          cout << "CX " << regVet[memory[PC]] << endl;
        } else if (memory[PC] == 3) { // OUT CX: ...
          cout << "DX " << regVet[memory[PC]] << endl;
        } else {
          cout << "Erro no comando OUT" << endl;
        }
        PC++;
        break;
      case 15: // INC REG
        PC++;
        regVet[memory[PC]] = regVet[memory[PC]] + 1;
        PC++;
        break;
      case 16: // DEC REG
        PC++;
        regVet[memory[PC]] = regVet[memory[PC]] - 1;
        PC++;
        break;
      case 17: // MUL REG, REG
        PC++;
        regVet[memory[PC]] = regVet[memory[PC]] * regVet[memory[PC + 1]];
        PC++;
        PC++;
        break;
      case 18: // DIV REG, REG
        PC++;
        regVet[memory[PC]] = regVet[memory[PC]] / regVet[memory[PC + 1]];
        PC++;
        PC++;
        break;
      default:
        break;
    }
      //cout<<"Valor AX: "<<regVet[0]<<" Valor BX: "<<regVet[1]<<endl;
      //cout <<"Valor PC: "<<PC << endl;
  }
  posicaoIncialMemoria = PC;
}
