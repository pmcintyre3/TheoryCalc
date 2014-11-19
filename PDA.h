#ifndef _PDA_H_
#define _PDA_H_

#include <cstdlib>
#include <vector>

#include "Node.h"

//this is a header file for creating a pushdown automata
//in C++. It is represented as a linkedlist

class pda{
 private:
  int numStates;

  std::vector <Node*> states;
  char sigma [2];
  char gamma [10];
  
  std::pair delta [1000];

  Node* qStart;
  Node* qAccept;
  
 public:
  pda();
  pda(std::vector<Node*>, char*, char*, std::pair*, Node*, Node*);
  ~pda();


  void createNode();
  void deleteNode();
  
  void setStates(std::vector<Node*>);
  void setSigma(char*);
  void setGamma(char*);
  void setQStart(Node*);
  void setQAccept(Node*);
  void setNumStates(int);

  std::vector<Node*> getStates();
  char * getSigma();
  char * getGamma();
  Node* getQStart();
  Node* getQAccept();
  int getNumStates();
}; //PDA

#endif
