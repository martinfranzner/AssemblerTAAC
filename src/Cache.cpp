
#include "Cache.h"

Cache::Cache() {
  MemoryAddres inicializador;
  for (int i = 0; i < CACHE_LINES; i++)
    this->cacheLines.push_back(inicializador);
}

int Cache::getWord(Memory &memory, unsigned long pc)
{
  MemoryAddres newAddressRequested(pc);
  auto cacheRow = static_cast<unsigned long>(std::stoi(newAddressRequested.getRow(), nullptr, 2));
  if (cacheLines.at(cacheRow).getTag().empty())
    return cachedMissed(memory, pc, cacheRow, newAddressRequested);
  else
    return cacheHitted(cacheRow, newAddressRequested);
}

int Cache::cachedMissed(Memory &memory,
                        unsigned long pc,
                        unsigned long cacheRow,
                        MemoryAddres newAddressRequest) {
  //  if (cacheLines.at(cacheRow).getTag().empty())
//  {
//     So atualiza a cache line
//  }
//  else
//  {
//    Atualiza a memoria principal
//    Atualiza a cache line
//  }
  MemoryAddres menAddress;
  menAddress = memory.getMemoryAddres2(newAddressRequest.getTag(), pc);
  cacheLines.at(cacheRow).setMemoryBlockTag(newAddressRequest.getTag());
  cacheLines.at(cacheRow).setWords(menAddress.getWords());
  cacheLines.at(cacheRow).setWords(menAddress.getWords());
  cacheMiss++;
  auto bla = newAddressRequest.getWord();
  for(auto wordInRow: cacheLines.at(cacheRow).getWords())
    if(wordInRow.first == newAddressRequest.getWord())
      return wordInRow.second;
}

int Cache::cacheHitted(unsigned long cacheRow, MemoryAddres &newAddressRequest) {
  int tag2 = stoi(cacheLines.at(cacheRow).getTag(), nullptr, 2);
  if (stoi(newAddressRequest.getTag(), nullptr, 2) == tag2)
  {
    for(auto wordInCacheRow: cacheLines.at(cacheRow).getWords())
      if(wordInCacheRow.first == newAddressRequest.getWord())
      {
        cacheHit++;
        return wordInCacheRow.second;
      }
  }
}

int Cache::updateCache(Memory &memory, unsigned int PC) {
  MemoryAddres newAddressRequested(PC);
  auto searchedRow = static_cast<unsigned long>(std::stoi(newAddressRequested.getRow(), nullptr, 2));

  if (this->cacheLines.at(searchedRow).getTag().empty())
    return this->getWord(memory, PC);
  else
  {
    int tag = std::stoi(this->cacheLines.at(searchedRow).getTag(), nullptr, 2);
    if (stoi(newAddressRequested.getTag(), nullptr, 2) == tag)
    {
      this->cacheHit++;
      for (auto i = 0; i < 64; i++)
        if (this->cacheLines.at(searchedRow).getWords().at(i).first == newAddressRequested.getWord())
          return this->cacheLines.at(searchedRow).getWords().at(i).second;
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






