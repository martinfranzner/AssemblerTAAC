
#include "Cache.h"

Cache::Cache() {
  CacheLine inicializador;
  for (int i = 0; i < 128; i++) {
    this->cacheLines.push_back(inicializador);
  }
}

int Cache::consultCache(Memory &memory, unsigned long pc) {
  bitset<24> bit = pc;
  string bin = bit.to_string();

  string word = bin.substr(bin.length() - 6);     //ultimos 6
  string tag = bin.substr(0, 11);                 //primeiros 11
  string row = bin.substr(12, 7);                 //os sete depois dos 11 do tag

  int indexCashLine = std::stoi(row, nullptr, 2); // transforma o row em string de binario para int

  if (cacheLines.at(indexCashLine).getTag() == "")
  {
    cout << "Cache miss" << endl;
    this->cacheMiss++;
    vector<pair<string, int>> c;
    c = memory.returnToCache(tag, pc);
    cacheLines.at(indexCashLine).setTag(tag);
    cacheLines.at(indexCashLine).setRowAmdWord(c);

    auto values = find_if(cacheLines.at(indexCashLine).getRowAmdWord().begin(),
                          cacheLines.at(indexCashLine).getRowAmdWord().end(),
                          [&word](const pair<string, int> &p) { return p.first == word; }
    );

    pair<string, int> aux = *values;
    return aux.second;
  }
  else {
    int tag2 = std::stoi(cacheLines.at(indexCashLine).getTag(), nullptr, 2);
    if (stoi(tag, nullptr, 2) == tag2) {
      cout << "Cache hit" << endl;
      this->cacheHit++;
      auto values = find_if(cacheLines.at(indexCashLine).getRowAmdWord().begin(),
                            cacheLines.at(indexCashLine).getRowAmdWord().end(),
                            [&word](const pair<string, int> &p) { return p.first == word; }
      );
      pair<string, int> aux = *values;
      return aux.second;
    }
  }

  return 0;

}

void Cache::setMemoryAddres(const string &bin, string &word, string &tag, string &row) const {
  word = bin.substr(bin.length() - 6);//ultimos 6
  tag = bin.substr(0, 11);//primeiros 11
  row = bin.substr(12, 7);//os sete depois dos 11 do tag

}


int Cache::updateCache(Memory &memory, unsigned int pc) {
  bitset<24> b = pc;
  string bin = b.to_string();

  string otherWord = "";
  string otherTag = "";
  string otherRow = "";

  setMemoryAddres(bin, otherWord, otherTag, otherRow);

  int linhaR = std::stoi(otherRow, nullptr, 2);

  if (this->cacheLines.at(linhaR).getTag() == "") {
    return this->consultCache(memory, pc);
  }
  else {
    int tag = std::stoi(this->cacheLines.at(linhaR).getTag(), nullptr, 2);
    if (stoi(otherTag, nullptr, 2) == tag) {
      cout << "Cache hit" << endl;
      this->cacheHit++;
      for (int i = 0; i < 64; i++) {
        if (this->cacheLines.at(linhaR).getRowAmdWord().at(i).first == otherWord)
        {
          this->cacheLines.at(linhaR).getRowAmdWord().at(i).second = memory.getMemoria()->at(pc);
          return this->cacheLines.at(linhaR).getRowAmdWord().at(i).second;
        }
      }
    }
  }

  return 0;
}



