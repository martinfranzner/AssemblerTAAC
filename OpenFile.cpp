//
//  OpenFile.cpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#include "OpenFile.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
OpenFile::OpenFile(string  nomeDeArquivo) : nomeArquivo(nomeDeArquivo){
    
}

vector<int> & OpenFile::toLineString()
{
    ifstream meuArquivo;
    string nome = nomeArquivo;
    string linha;
    vector<int> * V = new vector<int>();
    
    meuArquivo.open(nome);
    
    if (meuArquivo.is_open())
    {
        while (getline(meuArquivo, linha))
        {
            unsigned long ul = std::stoul (linha,nullptr,0); // converte a linha pra int
            V->push_back(ul);
        }
        meuArquivo.close();
    }
    else
    {
        cout << "Erro de abertura de arquivo";
    }
    
    return *V;
}

OpenFile::~OpenFile() {
}

