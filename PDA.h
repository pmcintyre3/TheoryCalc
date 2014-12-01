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
  int numStates; //-------------------------------------------------------------------------------- total number of states

  std::vector <Node*> states; //------------------------------------------------------------------- vector (set) of states
  std::vector<char> sigma; //---------------------------------------------------------------------- array of PDA alphabet
  std::vector<char> gamma; //---------------------------------------------------------------------- array of stack alphabet
  
  std::vector<std::vector<Node *> > delta; //------------------------------------------------------ vector of transitions

  std::vector<Node*> qStart; //--------------------------------------------------------------------- PDA start state
  std::vector<Node*> qAccept; //-------------------------------------------------------------------- PDA accept state

  std::vector<char> stack;
  
 public:
  pda(); //---------------------------------------------------------------------------------------- Create PDA
  pda(std::vector<Node*>, std::vector<char>, std::vector<char>, std::vector< std::vector<Node *> >, std::vector<Node*>, std::vector<Node*>); //----- Create PDA 
  ~pda(); //--------------------------------------------------------------------------------------- Delete PDA


  void createNode(); //---------------------------------------------------------------------------- create a node
  void deleteNode(Node*); //----------------------------------------------------------------------- delete a node
  void populate();

  void setStack(std::vector<char>);
  void setDelta(std::vector< std::vector<Node *> >); //-------------------------------------------- assign transition set
  void setStates(std::vector<Node*>); //----------------------------------------------------------- assign set of states
  void setSigma(std::vector<char>); //------------------------------------------------------------- assign PDA alphabet
  void setGamma(std::vector<char>); //------------------------------------------------------------- assign stack alphabet
  void setQStart(std::vector<Node*>); //------------------------------------------------------------ assign start state
  void setQAccept(std::vector<Node*>); //----------------------------------------------------------- assign accept state
  void setNumStates(int); //----------------------------------------------------------------------- change state counter

  std::vector<char> getStack();
  std::vector< std::vector<Node *> > getDelta(); //------------------------------------------------ return transition set
  std::vector<Node*> getStates(); //--------------------------------------------------------------- return set of states
  std::vector<char> getSigma(); //----------------------------------------------------------------- return PDA alphabet
  std::vector<char> getGamma(); //----------------------------------------------------------------- return stack alphabet 
  std::vector<Node*> getQStart(); //---------------------------------------------------------------- return PDA start state
  std::vector<Node*> getQAccept(); //--------------------------------------------------------------- return PDA accept state
  int getNumStates(); //--------------------------------------------------------------------------- return number of states
}; //PDA

#endif
