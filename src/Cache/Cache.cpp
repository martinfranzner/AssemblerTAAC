
#include "Cache.h"

Cache::Cache() {
  CacheLine inicializador;
  for (int i = 0; i < CACHE_LINES; i++)
    this->cacheLines.push_back(inicializador);
}

int Cache::getWord(Memory &memory, unsigned long pc)
{
  MemoryAddres newAddressRequested(pc);
  auto addresRow = static_cast<unsigned long>(std::stoi(newAddressRequested.getRow(), nullptr, 2));
  if (this->cacheLines.at(addresRow).getTag() == newAddressRequested.getTag()) {
    cacheHitCounter++;
    return returnWord(newAddressRequested);
  }
  else {
    this->cacheMissEvent(memory, pc, newAddressRequested);
    return returnWord(newAddressRequested);
  }
}


void Cache::cacheMissEvent(Memory &memory, unsigned long pc, MemoryAddres newAddressRequest) {
  auto addresRow = static_cast<unsigned long>(std::stoi(newAddressRequest.getRow(), nullptr, 2));
  cacheMissCounter++;
  if (cacheLines.at(addresRow).getTag().empty())
    this->updateCacheLine(memory, pc, newAddressRequest);
  else
  {
    //    Atualiza a memoria principal com a cache
    updateMemory(memory);  // <<<--------- AQUI MARTIN, Aqui está o problema.
                           // No nosso caso da boa pq o prog eh pequeno.
    this->updateCacheLine(memory, pc, newAddressRequest);
  }
}

void Cache::updateMemory(Memory &) {

}

void Cache::updateCacheLine(Memory &memory, unsigned long pc, const MemoryAddres &newAddressRequest)
{
  auto addressRow = static_cast<unsigned long>(stoi(newAddressRequest.getRow(), nullptr, 2));
  CacheLine cacheLine;
  cacheLine = memory.getMemoryAddres(newAddressRequest.getTag(), pc);
  cacheLines.at(addressRow).setTag(newAddressRequest.getTag());
  cacheLines.at(addressRow).setWords(cacheLine.getWords());
  cacheLines.at(addressRow).setWords(cacheLine.getWords());
}

int Cache::returnWord(MemoryAddres &newAddressRequest) {
  auto addresRow2 = static_cast<unsigned long>(std::stoi(newAddressRequest.getRow(), nullptr, 2));
  for(auto wordInRow: this->cacheLines.at(addresRow2).getWords())
    if(wordInRow.first == newAddressRequest.getWord())
      return wordInRow.second;
}


int Cache::getCacheHit() const {
  return cacheHitCounter;
}

int Cache::getCacheMiss() const {
  return cacheMissCounter;
}








//const string &CacheLine::getTag() const {
//  return tag;
//}

//void CacheLine::setTag(const string &tag) {
//  CacheLine::tag = tag;
//}

//const vector<pair<string, int>> &CacheLine::getWords() const {
//  return words;
//}

//void CacheLine::setWords(const vector<pair<string, int>> &words) {
//  CacheLine::words = words;
//}

