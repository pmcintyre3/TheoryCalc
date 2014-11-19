#ifndef _PDA_H_
#define _PDA_H_

#include <cstdlib>
#include <utility>
#include <vector>

#include "Node.h"

//this is a header file for creating a pushdown automata
//in C++. It is represented as a linkedlist

class pda{
 private:
  int numStates; //------------------------------------------ total number of states

  std::vector <Node*> states; //----------------------------- vector (set) of states
  char sigma [2]; //----------------------------------------- array of PDA alphabet
  char gamma [10]; //---------------------------------------- array of stack alphabet
  
  std::vector<std::pair<Node *, Node *> > delta; //------------------------------- vector of transitions

  Node* qStart; //------------------------------------------- PDA start state
  Node* qAccept; //------------------------------------------ PDA accept state
  
 public:
  pda(); //-------------------------------------------------- Create PDA
  pda(std::vector<Node*>, char*, char*, std::vector< std::pair<Node *, Node *> >, Node*, Node*); // Create PDA 
  ~pda(); //------------------------------------------------- Delete PDA


  void createNode(); //-------------------------------------- create a node
  void deleteNode(Node*); //-------------------------------------- delete a node
  
  void setDelta(std::vector< std:: pair< Node *, Node *> >); // assign transition set
  void setStates(std::vector<Node*>); //--------------------- assign set of states
  void setSigma(char*); //----------------------------------- assign PDA alphabet
  void setGamma(char*); //----------------------------------- assign stack alphabet
  void setQStart(Node*); //---------------------------------- assign start state
  void setQAccept(Node*); //--------------------------------- assign accept state
  void setNumStates(int); //--------------------------------- change state counter

  std::vector< pair:: <Node *, Node *> > getDelta(); //------ return transition set
  std::vector<Node*> getStates(); //------------------------- return set of states
  char * getSigma(); //-------------------------------------- return PDA alphabet
  char * getGamma(); //-------------------------------------- return stack alphabet 
  Node* getQStart(); //-------------------------------------- return PDA start state
  Node* getQAccept(); //------------------------------------- return PDA accept state
  int getNumStates(); //------------------------------------- return number of states
}; //PDA

#endif
