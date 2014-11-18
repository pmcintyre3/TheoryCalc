#ifndef _PDA_H_
#define _PDA_H_

//Node represents nodes in a pushdown automata.
//The next pointers are pointers for the values
//0 or 1 in the language

struct Node{
  bool isStart;
  bool isAccept;

  Node* delta0;
  Node* delta1;

  struct Node(bool s, bool a, struct Node* d0, struct Node* d1) : isStart(s), isAccept(a), delta0(d0), delta1(d1)
}

//this is a header file for creating a pushdown automata
//in C++. It is represented as a linkedlist

class pda{
 private:
  struct Node* states [1000];
  char sigma [2];
  char gamma [10];
  
  std::pair delta [1000];

  struct Node* qStart;
  struct Node* qAccept;
  
 public:
  pda();
  pda(struct Node**, char*, char*, std::pair*, struct Node*, struct Node*);

  void createNode();
  void deleteNode();
  
  void setStates(struct Node**);
  void setSigma(char*);
  void setGamma(char*);
  void setQStart(struct Node*);
  void setQAccept(struct Node*);

  struct Node** getStates();
  char * getSigma();
  char * getGamma();
  struct Node* getQStart();
  struct Node* getQAccept();
}; //PDA

#endif
