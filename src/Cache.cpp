
#include "Cache.h"

Cache::Cache() {
  CacheLine inicializador;
  for (int i = 0; i < CACHE_LINES; i++)
  {
    this->cacheLines.push_back(inicializador);
  }
}

int Cache::getWord(Memory &memory, unsigned long pc) {
  bitset<24> bit = pc;
  string bin = bit.to_string();
  string word = bin.substr(bin.length() - 6);     //ultimos 6
  string tag = bin.substr(0, 11);                 //primeiros 11
  string row = bin.substr(12, 7);                 //os sete depois dos 11 do tag
  auto cacheRow = static_cast<unsigned long>(std::stoi(row, nullptr, 2));
  if (cacheLines.at(cacheRow).getTag().empty())
    return cachedMissed(memory, pc, word, tag, cacheRow);
  else
    return cacheHitted(word, tag, cacheRow);
}


int Cache::cachedMissed(Memory &memory, unsigned long pc, const string &word, const string &tag,
                        unsigned long row)
{
  vector<pair<string, int>> rowAndWord;
  rowAndWord = memory.getRowAndWord(tag, pc);
  cacheLines.at(row).setTag(tag);
  cacheLines.at(row).setRowAmdWord(rowAndWord);
  cacheMiss++;
  for(auto wordInRow: cacheLines.at(row).getRowAmdWord())
    if(wordInRow.first == word)
      return wordInRow.second;
}

int Cache::cacheHitted(const string &word, const string &tag, unsigned long cacheRow) {
  int tag2 = stoi(cacheLines.at(cacheRow).getTag(), nullptr, 2);
  if (stoi(tag, nullptr, 2) == tag2)
  {
    for(auto wordInCacheRow: cacheLines.at(cacheRow).getRowAmdWord())
     if(wordInCacheRow.first == word)
     {
       cacheHit++;
       return wordInCacheRow.second;
     }
  }
}

int Cache::updateCache(Memory &memory, unsigned int PC) {
  bitset<24> b = PC;
  string bin = b.to_string();
  string otherWord = bin.substr(bin.length() - 6);//ultimos 6
  string otherTag = bin.substr(0, 11);//primeiros 11
  string otherRow = bin.substr(12, 7);//os sete depois dos 11 do tag
  auto searchedRow = static_cast<unsigned long>(std::stoi(otherRow, nullptr, 2));

  if (this->cacheLines.at(searchedRow).getTag().empty())
    return this->getWord(memory, PC);
  else
  {
    int tag = std::stoi(this->cacheLines.at(searchedRow).getTag(), nullptr, 2);
    if (stoi(otherTag, nullptr, 2) == tag)
    {
      this->cacheHit++;
      for (auto i = 0; i < 64; i++)
        if (this->cacheLines.at(searchedRow).getRowAmdWord().at(i).first == otherWord)
        {
          this->cacheLines.at(searchedRow).getRowAmdWord().at(i).second = memory.getMemoria()->at(PC);
          return this->cacheLines.at(searchedRow).getRowAmdWord().at(i).second;
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



