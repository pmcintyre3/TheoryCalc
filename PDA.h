#ifndef _PDA_H_
#define _PDA_H_

#include <cstdlib>
#include <vector>

//Node represents nodes in a pushdown automata.
//The next pointers are pointers for the values
//0 or 1 in the language

struct Node{
  bool isStart;
  bool isAccept;

  Node* delta0;
  Node* delta1;

  struct Node() : isStart(false), isAccept(false), delta0(NULL), delta1(NULL)

  struct Node(bool s, bool a, struct Node* d0, struct Node* d1) : isStart(s), isAccept(a), delta0(d0), delta1(d1)
    };

//this is a header file for creating a pushdown automata
//in C++. It is represented as a linkedlist

class pda{
 private:
  int numStates;

  std::vector <struct Node*> states;
  char sigma [2];
  char gamma [10];
  
  std::pair delta [1000];

  struct Node* qStart;
  struct Node* qAccept;
  
 public:
  pda();
  pda(std::vector<struct Node*>, char*, char*, std::pair*, struct Node*, struct Node*);
  ~pda();


  void createNode();
  void deleteNode();
  
  void setStates(std::vector<struct Node*>);
  void setSigma(char*);
  void setGamma(char*);
  void setQStart(struct Node*);
  void setQAccept(struct Node*);
  void setNumStates(int);

  void setDelta0(struct Node*, struct Node*);
  void setDelta1(struct Node*, struct Node*);

  struct Node* getDelta0(struct Node *);
  struct Node* getDelta1(struct Node *);

  std::vector<struct Node*> getStates();
  char * getSigma();
  char * getGamma();
  struct Node* getQStart();
  struct Node* getQAccept();
  int getNumStates();
}; //PDA

#endif
