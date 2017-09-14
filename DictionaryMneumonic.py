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
    

if __name__ == "__main__":
    
    
    """mneu = {'NOP': 0, 'HALT':1, 'MOV1':2, 'MOV2':3, 'MOV3':4,'MOV4':5, 'MOV5':6,'ADD':7,
             'SUB':8, 'CMP':9, 'JMP':10, 'JZ':11, 'OUT':12,
             'INC':13, 'DEC':14, 'MUL':15,'DIV':16}
    """
    
    

    
    
    path= ('/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Arquitetura Computadores 2/Assembler/OPCODES.esym.txt') 
    days_file = open(path,'r')
    aux = days_file.readlines()
    
    dici = createDic(aux)
    print(dici)
    
    
    
   


