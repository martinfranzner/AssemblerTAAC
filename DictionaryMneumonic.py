#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import re


def createDictionary(file):
    dic = {}
    counter = 0;
    for line in file:
        string = re.sub(r'\s+', '', line)  # Remove spaces
        if string.rsplit(';', 1)[0] != '':
            dic[string.rsplit(';', 1)[0]] = counter
            counter += 1
    return dic


def register(file):
    regdic = {}
    i = 0
    for line in file:
        string = re.sub(r'\s+', '', line)
        regdic[string] = i
        i += 1
    return regdic


def createInstructions(file, dicionario, registradores):
    vectorComand = []
    comands_aux = []
    register = 0
    index = 0
    immediate = 0
    aux_count = 0
    isRegAddres = False

    for line in file:
        string = re.sub(r'\s+', ' ', line)  # Remove espaços
        if (string.rsplit(';', 1)[0] != ''):
            if (string.rsplit(';', 1)[0] != 'MOV'):  # verifica se é MOV, se nao printa o comando
                commands = (string.rsplit(';', 1)[0])
                commands = commands.replace(',', ' ')
                command = commands.split(" ")
                print(command)
        else:
            command =[];

        if "MOV" in command:
            temMov = True
        else:
            temMov = False

        for j in command:
            if not temMov:
                if j in dicionario:
                    vectorComand.append(dicionario[j])
                elif j in registradores:
                    vectorComand.append(int(registradores[j]))
                elif '[' in j:
                    vectorComand.append(int(j.strip("[]")))
                else:
                    if j != '':
                        vectorComand.append(int(j))
            else:
                if j == "MOV":
                    comands_aux.append(j)
                elif j in registradores:
                    register += 1
                    comands_aux.append(int(registradores[j]))
                elif '[' in j:
                    index += 1
                    comands_aux.append(int(j.strip("[]")))

                    if aux_count == 1:
                        isRegAddres = False
                    else:
                        isRegAddres = True
                else:
                    immediate += 1
                    if j != '':
                        comands_aux.append(int(j))

            aux_count += 1

        for each in comands_aux:  # will just enter if it find MOV, otherwise comands_aux.size()=00
            if register == 2:  # mover um registrador no outro
                if each == "MOV":
                    vectorComand.append(dicionario["MOV_RR"])
                else:
                    vectorComand.append(each)

            elif register == 1 and index == 1:  # Para quando tem [NUM]
                if each == "MOV":
                    if isRegAddres:
                        vectorComand.append(dicionario["MOV_RM"])
                    else:
                        vectorComand.append(dicionario["MOV_MR"])
                else:
                    vectorComand.append(each)

            elif register == 1 and immediate == 1:  # Para quando tem somente num
                if each == "MOV":
                    vectorComand.append(dicionario["MOV_RI"])
                else:
                    vectorComand.append(each)

            elif index == 1 and immediate == 1:  # Para quando tem [NUM] e NUM
                if each == "MOV":
                    vectorComand.append(dicionario["MOV_MI"])
                else:
                    vectorComand.append(each)

        register = 0
        index = 0
        immediate = 0
        aux_count = 0
        comands_aux.clear()

    return vectorComand


if __name__ == "__main__":
    path_opcode = ('./OPCODES.esym.txt')
    path_reg = ('./REGCODES.esym.txt')
    path_instructions = ('./testeProf.txt')
    # path_instructions = ('./testeInstructions.txt')

    # RegCodes
    reg_reader = open(path_reg, 'r')
    aux_reg = reg_reader.readlines()

    print("\n\n --Dicionario de Registradores--- \n")
    dici_reg = register(aux_reg)
    print(dici_reg)

    # OpCodes
    op_reader = open(path_opcode, 'r')
    op_lines = op_reader.readlines()

    print("\n\n ---Dicionario de OPCODES--- \n")
    dici_op = createDictionary(op_lines)
    print(dici_op)

    print("\n\n-------\n\n")

    # Instructions example

    instructions_reader = open(path_instructions, 'r')
    instr_lines = instructions_reader.readlines()

    instructionsVector = createInstructions(instr_lines, dici_op, dici_reg)

    print("\n\n ---OUTPUT instrucoes --- \n")
    print(instructionsVector)
