
#include "Cache.h"

Cache::Cache() {
    for (int i = 0; i < 128; i++){
        CacheStruct aux;
        aux.tag = -1;
        aux.row = -1;
        for(int j = 0; j<64; j++){
            aux.word[i] = -1;
        }
        this->cache.push_back(aux);
    }
}

int Cache::verifyCache(Memory &memory, int pc){
    int t,r,w;
    bitset<24> bit = pc;
    //fez o tag
    auto resultTag = bit>>13;
    t = (int)(resultTag.to_ulong());
    
    //faz o row
    bit = pc;
    resultTag = bit<<11;
    resultTag = resultTag>>17;
    r = (int)(resultTag.to_ulong());
    
    //faz o word
    bit = pc;
    resultTag = bit<<18;
    resultTag = resultTag>>18;
    w = (int)(resultTag.to_ulong());

    if (this->cache.at(r).tag == t){
        cout << "Cache hit" << endl;
        int contentToReturn = this->cache.at(r).word.at(w);
        
        return contentToReturn;
        
    }
    else{
        cout << "Cache miss" << endl;
        //se nao tem nada na posicao da cache ainda
        if(this->cache.at(r).tag == -1){ //linha esta zerada tem que passar o bloco da memoria para a cache
            vector<int> vec = memory.grabOnMemory(t, r, w, pc);
            this->cache.at(r).tag = t;
            this->cache.at(r).row = r;
            this->cache.at(r).word = vec;
            int contentToReturn = this->cache.at(r).word.at(w);
            
            return contentToReturn;
        }
        else if (this->cache.at(r).tag != t){ // se ja tem algo na cache e tem que atualizar a memoria e ela
            // joga oq ta na cacheline pra memoria e puxa o que ta na memoria para la
            vector<int> vec = memory.updateMemory(t, r, w, pc,this->cache.at(r).word);
            this->cache.at(r).tag = t;
            this->cache.at(r).row = r;
            this->cache.at(r).word = vec;
            int contentToReturn = this->cache.at(r).word.at(w);
            
            return contentToReturn;
        }
    }
    
    return 0;

}






