//
// Created by eborsa on 01/11/17.
//

#ifndef TAACCERTO_CACHELINE_H
#define TAACCERTO_CACHELINE_H


class MemoryAddress {
  int tag;  //
  int roll; // é a linha da cache
  int word; // conteudo

public:
  MemoryAddress();

  MemoryAddress(int tag, int roll, int word);

  void setTag(int tag);

  void setRoll(int roll);

  void setWord(int word);

  int getTag() const;

  int getRoll() const;

  int getWord() const;
};


#endif //TAACCERTO_CACHELINE_H
