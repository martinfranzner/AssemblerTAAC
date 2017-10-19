//
//  Executor.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 19/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "Executor.hpp"
Executor::Executor(){
    
}
void Executor::executar(vector<int> memory, int posicaoIncialMemoria){
    cout<<"Entrou no executar"<<endl;
    cout<<"Memory 7"<<memory[7]<<endl;
//    ---Dicionario de OPCODES---
//    {'NOP': 0, 'HALT': 1, 'MOV_RR': 2, 'MOV_RM': 3, 'MOV_MR': 4, 'MOV_RI': 5, 'MOV_MI': 6, 'ADD': 7, 'SUB': 8, 'CMP': 9, 'JMP': 10, 'JZ': 11, 'JG': 12, 'JL': 13, 'OUT': 14, 'INC': 15, 'DEC': 16, 'MUL': 17, 'DIV': 18}
    
    PC = posicaoIncialMemoria;
    cout<<"Poosicao Inicial: "<<PC<<endl;
    while(memory[PC] != 1){
        cout<<"Memory PC: "<<memory[PC]<<endl;
        switch (memory[PC]){
            case 0:
                PC++;
                break;
            case 1:
                break;
            case 2: //MOV REG, REG
                PC++;//vai da instrucao pros registradores
                regVet[memory[PC]] = regVet[memory[PC+1]]; // pega o valor que esta no vetor de registrador da memoria
        
                PC++;//agora esta no prox reg
                PC++;//agora esta na proxima instrucao
                break;
            case 3: // MOV REG, MEM
                PC++;
                regVet[memory[PC]] = memory[PC+1];   // duvida se joga direto o da memoria ou o que?? *******
                PC++;//agora esta na MEM
                PC++;//agora esta na proxima instrucao
                break;
            case 4: // MOV MEM, REG
                PC++;
                memory[memory[PC]] = regVet[memory[PC+1]];
                PC++;
                PC++;
                break;
            case 5: // MOV REG , IMEDIATE
                PC++;
                regVet[memory[PC]] = memory[PC+1];
                PC++;
                PC++;
                break;
            case 6: // MOV MEM, IMEDIATE
                PC++;
                memory[memory[PC]] = memory[PC+1];
                PC++;
                PC++;
                break;
            case 7: //ADD REG, REG
                PC++;
                regVet[memory[PC]] += regVet[memory[PC+1]];
                PC++;
                PC++;
                break;
            case 8: //SUB REG, REG
                PC++;
                regVet[memory[PC]] = regVet[memory[PC]] - regVet[memory[PC+1]];
                PC++;
                PC++;
                break;
            case 9: //CMP REG, REG
                PC++;
                FL = regVet[memory[PC]]-regVet[memory[PC+1]];
                PC++;
                PC++;
                break;
            case 10: // JMP
                PC++; // como faz? joga o PC para o valor que vem depois do JMP?? ******
                PC = memory[PC];
                break;
            case 11: // JZ jump if zero
                PC++;
                if(FL == 0){
                    PC = memory[PC];
                }
                else{
                    PC++;
                }
                break;
            case 12: // JG jump ig greater
                PC++;
                if(FL > 0){
                    PC = memory[PC];
                }
                else{
                    PC++;
                }
                break;
            case 13: // JL jump ig greater
                PC++;
                if(FL < 0){
                    PC = memory[PC];
                }
                else{
                    PC++;
                }
                break;
            case 14: // OUT REG
                PC++;
                if(regVet[memory[PC]] == 0){ // OUT AX: ...
                    cout<<"AX "<<memory[PC]<<endl;
                }
                else if(regVet[memory[PC]] == 1){ // OUT BX: ...
                    cout<<"BX "<<memory[PC]<<endl;
                }
                else if(regVet[memory[PC]] == 2){ // OUT CX: ...
                    cout<<"CX "<<memory[PC]<<endl;
                }
                else if(regVet[memory[PC]] == 3){ // OUT CX: ...
                    cout<<"DX "<<memory[PC]<<endl;
                }
                else {
                    cout<<"Erro no comando OUT"<<endl;
                }
                PC++;
                break;
            case 15: // INC REG
                PC++;
                regVet[memory[PC]] = regVet[memory[PC]] +1;
                PC++;
                break;
            case 16: // DEC REG
                PC++;
                regVet[memory[PC]] = regVet[memory[PC]] -1;
                PC++;
                break;
            case 17: // MUL REG, REG
                PC++;
                regVet[memory[PC]] = regVet[memory[PC]] * regVet[memory[PC+1]];
                PC++;
                PC++;
                break;
            case 18: // DIV REG, REG
                PC++;
                regVet[memory[PC]] = regVet[memory[PC]] / regVet[memory[PC+1]];
                PC++;
                PC++;
                break;      
        }
        //PC++;
        cout<<PC<<endl;
        //cout<<"Rodou o while"<<endl;
    }
}
