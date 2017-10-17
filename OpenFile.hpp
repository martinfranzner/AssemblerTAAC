//
//  OpenFile.hpp
//  AssemblerLoader
//
//  Created by Martin Franzner on 06/10/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//

#ifndef OpenFile_hpp
#define OpenFile_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class OpenFile {
public:
    OpenFile(string  nomeDeArquivo);
    vector<int> & toLineString();
    virtual ~OpenFile();
private:
    string nomeArquivo;
    
    
};
#endif /* OpenFile_hpp */
