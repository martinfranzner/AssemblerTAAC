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
    dicionario = {}
    i = 0
    for line in file:
        string = re.sub(r'\s+', '', line)
        dicionario[string] = i
        i+= 1
        
    return dicionario
    

if __name__ == "__main__":
    
    
    """mneu = {'NOP': 0, 'HALT':1, 'MOV1':2, 'MOV2':3, 'MOV3':4,'MOV4':5, 'MOV5':6,'ADD':7,
             'SUB':8, 'CMP':9, 'JMP':10, 'JZ':11, 'OUT':12,
             'INC':13, 'DEC':14, 'MUL':15,'DIV':16}
    """
    
    

    
    
    path_opcode= ('/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Arquitetura Computadores 2/Assembler/OPCODES.esym.txt') 
    path_reg= ('/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Arquitetura Computadores 2/Assembler/REGCODES.esym.txt') 
    
    days_file_op = open(path_opcode,'r')
    aux_op = days_file_op.readlines()
    
    days_file_reg = open(path_reg,'r')
    aux_reg = days_file_reg.readlines()
    
    dici_reg = register(aux_reg)
    print(dici_reg)
    
    dici_op = createDic(aux_op)
    print(dici_op)
    
    
    
   


