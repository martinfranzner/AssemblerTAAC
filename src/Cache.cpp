
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

  auto indexCashLine = static_cast<unsigned long>(std::stoi(row, nullptr, 2)); // transforma o row em string de binario para int

  if (cacheLines.at(indexCashLine).getTag().empty())
  {
    this->cacheMiss++;
    vector<pair<string, int>> rowAndWord;
    rowAndWord = memory.returnToCache(tag, pc);
    cacheLines.at(indexCashLine).setTag(tag);
    cacheLines.at(indexCashLine).setRowAmdWord(rowAndWord);

    auto values = find_if(cacheLines.at(indexCashLine).getRowAmdWord().begin(),
                          cacheLines.at(indexCashLine).getRowAmdWord().end(),
                          [&word](const pair<string, int> &pair)
                          { return pair.first == word; }
                         );
    return (*values).second;
  }
  else {
    int tag2 = std::stoi(cacheLines.at(indexCashLine).getTag(), nullptr, 2);
    if (stoi(tag, nullptr, 2) == tag2) {
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


int Cache::updateCache(Memory &memory, unsigned int PC) {
  bitset<24> b = PC;
  string bin = b.to_string();

  string otherWord = bin.substr(bin.length() - 6);//ultimos 6
  string otherTag = bin.substr(0, 11);//primeiros 11
  string otherRow = bin.substr(12, 7);//os sete depois dos 11 do tag

  auto searchedRow = static_cast<unsigned long>(std::stoi(otherRow, nullptr, 2));

  if (cacheLines.at(searchedRow).getTag().empty()) {
    return this->consultCache(memory, PC);
  }
  else {
    int tag = std::stoi(cacheLines.at(searchedRow).getTag(), nullptr, 2);
    if (stoi(otherTag, nullptr, 2) == tag) {
      cacheHit++;
      for (auto i = 0; i < 64; i++)
      {
        if (cacheLines.at(searchedRow).getRowAmdWord().at(i).first == otherWord)
        {
          cacheLines.at(searchedRow).getRowAmdWord().at(i).second = memory.getMemoria()->at(PC);
          return cacheLines.at(searchedRow).getRowAmdWord().at(i).second;
        }
      }
    }
  }

  return 0;
}

int Cache::getCacheHit() const {
  return cacheHit;
}

int Cache::getCacheMiss() const {
  return cacheMiss;
}



