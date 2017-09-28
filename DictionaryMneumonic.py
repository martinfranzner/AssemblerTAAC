#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep  5 15:17:55 2017

@author: martinfranzner
"""

#dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
#print ("dict['Name']: ", dict['Name'])
#print ("dict['Age']: ", dict['Age'])

import re 


def createDic(file):
    dic = {}
    i = 0;
    for line in file:
        string = re.sub(r'\s+', '', line)
        if(string.rsplit(';', 1)[0] != ''):
            dic[string.rsplit(';', 1)[0]] = i
            i += 1
    return dic

def register(file):
    regdic = {}
    i = 0
    for line in file:
        string = re.sub(r'\s+', '', line)
        regdic[string] = i
        i+= 1
        
    return regdic

def createInstructions(file, dicionario, registradores):
    vetor=[]
    comandoVet=[]
    auxVet=[]
    auxComandos = []
    registrador_registrador = 0
    addr = 0
    immediate = 0
    auxCount = 0
    isRegAddres = False
    
    i=0
    temMov = True
    for line in file:
        string = re.sub(r'\s+', ' ', line)
        if(string.rsplit(';', 1)[0] != ''):
            #print(string.rsplit(';',1)[0])
            if(string.rsplit(';',1)[0] != 'MOV'):
                commands = (string.rsplit(';',1)[0])
                commands = commands.replace(',', ' ')
                #print(commands)
                command = commands.split(" ")
                print(command)
        
        if "MOV" in command:
            temMov = True
        else:
            temMov = False
        
        for j in command:
            if not temMov:
                if j in dicionario:
                    comandoVet.append(dicionario[j])  
                    #print(comandoVet)
                elif j in registradores:
                    comandoVet.append(int(registradores[j]))
                elif '[' in j:
                    comandoVet.append(int(j.strip("[]")))
                else:
                    comandoVet.append(int(j))
            else:
                if j == "MOV":
                    auxComandos.append(j)
                elif j in registradores:
                    registrador_registrador += 1
                    auxComandos.append(int(registradores[j]))
                elif '[' in j:
                    addr += 1
                    auxComandos.append(int(j.strip("[]")))

                    if auxCount == 1:
                        isRegAddres = False
                    else:
                        isRegAddres = True
                else:
                    immediate += 1
                    auxComandos.append(int(j))
            
            auxCount += 1
            
        for co in auxComandos:
            if registrador_registrador == 2:
                if co == "MOV":
                    comandoVet.append(dicionario["MOV_RR"])
                else:
                    comandoVet.append(co)
            elif registrador_registrador == 1 and addr == 1:
                if co == "MOV":
                    if isRegAddres:
                        comandoVet.append(dicionario["MOV_RM"])
                    else:
                        comandoVet.append(dicionario["MOV_MR"])
                else:
                    comandoVet.append(co)
            elif registrador_registrador == 1 and immediate == 1:
                if co == "MOV":
                    comandoVet.append(dicionario["MOV_RI"])
                else:
                    comandoVet.append(co)
            elif addr == 1 and immediate == 1:
                if co == "MOV":
                    comandoVet.append(dicionario["MOV_MI"])
                else:
                    comandoVet.append(co)
                    
        registrador_registrador = 0
        addr = 0
        immediate = 0    
        auxCount = 0
        auxComandos.clear()
        
    return comandoVet



    

if __name__ == "__main__":

    path_opcode= ('./OPCODES.esym.txt') 
    path_reg= ('./REGCODES.esym.txt') 
    path_instructions= ('./testeInstructions.txt') 
    
    
    days_file_op = open(path_opcode,'r')
    aux_op = days_file_op.readlines()
    
    days_file_reg = open(path_reg,'r')
    aux_reg = days_file_reg.readlines()
    
    dici_reg = register(aux_reg)
    print(dici_reg)
    
    dici_op = createDic(aux_op)
    print(dici_op)
    
    days_file_instructions = open(path_instructions,'r')
    aux_inst = days_file_instructions.readlines()
    
    vetor_instructions = createInstructions(aux_inst, dici_op, dici_reg)
    
    print(vetor_instructions)
   
   


