
#include "Cache.h"

Cache::Cache() {
    this->cache = *new vector<pair<string, vector<pair<string, int>>>>(128);//eh o tag, depois vem a row e a word
    
    for (int i = 0; i < 128; i++)
    {
        this->cache.at(i).second = *new vector<pair<string, int>>(64);
    }

}

int Cache::consultCache(Memory &memory, int pc){
    bitset<24> bit = pc;
    string bin = bit.to_string();
    
    string word = "";
    string tag = "";
    string row = "";
    // transforma pra string e pega os bits que interessam
    word = bin.substr(bin.length() - 6);//ultimos 6
    tag = bin.substr(0, 11);//primeiros 11
    row = bin.substr(12, 7);//os sete depois dos 11 do tag
    
    int indexCashLine = std::stoi(row, nullptr, 2); // transforma o row em string de binario para int
    
    if (this->cache.at(indexCashLine).first == "")
    {
        cout << "Cache miss" << endl;
        vector<pair<string, int>> c ;//= *new vector<pair<string, int>>();
        c = memory.returnToCache(tag, pc);
        this->cache.at(indexCashLine).first = tag;
        this->cache.at(indexCashLine).second = c;
        
        auto values = find_if(this->cache.at(indexCashLine).second.begin(), this->cache.at(indexCashLine).second.end(),
                              [&word](const pair<string, int>&p) { return p.first == word; });
        
        //pair<string, int> aux = *values._Ptr;
        pair<string, int> aux = *values;
        return aux.second;
    }
    else
    {
        unsigned int tag2 = std::stoi(this->cache.at(indexCashLine).first, nullptr, 2);
        if (stoi(tag, nullptr, 2) == tag2)
        {
            cout << "Cache hit" << endl;
            auto values = find_if(this->cache.at(indexCashLine).second.begin(), this->cache.at(indexCashLine).second.end(),
                                  [&word](const pair<string, int>&p) { return p.first == word; });
            
            //pair<string, int> aux = *values._ptr;
            pair<string, int> aux = *values;
            return aux.second;
        }
    }
    
    return 0;

}


int Cache::updateCache(Memory &memory, unsigned int pc)
{
    bitset<24> b = pc;
    string bin = b.to_string();
    
    string w = "";
    string t = "";
    string r = "";
    
    w = bin.substr(bin.length() - 6);
    t = bin.substr(0, 11);
    r = bin.substr(12, 7);
    
    int linhaR = std::stoi(r, nullptr, 2);
    
    if (this->cache.at(linhaR).first == "")
    {
        return this->consultCache(memory, pc);
    }
    else
    {
        unsigned int tag = std::stoi(this->cache.at(linhaR).first, nullptr, 2);
        if (stoi(t, nullptr, 2) == tag)
        {
            cout << "Cache hit" << endl;
            for (int i = 0; i < 64; i++)
            {
                if (this->cache.at(linhaR).second.at(i).first == w)
                {
                    this->cache.at(linhaR).second.at(i).second = memory.getMemoria()->at(pc);
                    return this->cache.at(linhaR).second.at(i).second;
                }
            }
        }
    }
    
    return 0;
}




/*
const std::vector<MemoryAddress>* Cache::getCacheLines() const  {
  return &cacheLines;
}


void Cache::insertInstruction(MemoryAddress newLine) {
  if(position==128){
    position=0;
  }else {
    this->getCacheLinesNotConst()->at(position) = newLine;
    position++;
  }
}
*/
/*
std::vector<MemoryAddress >* Cache::getCacheLinesNotConst() {
  return &this->cacheLines;
}

int Cache::fetchInstruction(unsigned int &instruction, Memory &memory) {
  if(!isInCache(instruction)) // Cache miss
  {                                               // A cache faz isso
    this->cacheMiss++;
    insertInstructionInCache(instruction, memory);
  }
  else{
    this->cacheHit++;
  }
  return fetchInCache(instruction).second;
}

bool Cache::isInCache(int instruction) {
  for (auto i : *this->getCacheLines()) {
    if(i.getWord() == instruction){
      return true;
    }
  }
  return false;
}

void Cache::insertInstructionInCache(unsigned int &instruction, Memory &memory) {
  for (unsigned int i=0; i<memory.getMemoria()->size();i++) {
    if(memory.getMemoria()->at(i) == instruction){
      MemoryAddress address;
      address.setWord(memory.getMemoria()->at(i));
      address.setTag(static_cast<int>((i/memory.getMemoria()->size())*BLOCKSIZE));
      address.setRoll(i%BLOCKSIZE);
      this->insertInstruction(address);
      break;
    }
  }
}

const pair<bool, int> Cache::fetchInCache(int instruction) const {
  for (auto i : *this->getCacheLines()) {
    if(i.getWord() == instruction){
      return {true, i.getWord()};
    }
  }
  return {false,-1};
}

*/



