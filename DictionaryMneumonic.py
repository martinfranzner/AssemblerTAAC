#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep  5 15:17:55 2017

@author: martinfranzner
"""

#dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
#print ("dict['Name']: ", dict['Name'])
#print ("dict['Age']: ", dict['Age'])






if __name__ == "__main__":
    
    
    mneu = {'NOP': 0, 'HALT':1, 'MOV1':2, 'MOV2':3, 'MOV3':4,'MOV4':5, 'MOV5':6,'ADD':7,
             'SUB':8, 'CMP':9, 'JMP':10, 'JZ':11, 'OUT':12,
             'INC':13, 'DEC':14, 'MUL':15,'DIV':16}
    

    
    
    path= ('/Users/martinfranzner/Documents/PUC COMPUTAÇÃO/4o semestre/Arquitetura Computadores 2/Assembler/OPCODES.esym.txt') 
    days_file = open(path,'r')
    print(days_file.read())
   