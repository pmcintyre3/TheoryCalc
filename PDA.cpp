#include <cstdlib>
#include <iterator>
#include <iostream>

#include "Node.h"
#include "PDA.h"

using namespace std;

pda::pda() : states(NULL), sigma({ 0 }), gamma({ 0 }), delta(NULL), qStart(NULL), qAccept(NULL), stack({0}){

  Node* n = new Node();

  n->setIsStart(true);
  n->setIsAccept(true);

  states.push_back(n);

  qStart.push_back(n);

  qAccept.push_back(n);

  sigma.push_back('0');
  sigma.push_back('1');

  gamma.push_back('0');
  gamma.push_back('1');
  gamma.push_back('#');
  gamma.push_back('X');

  } //blank pda constructor

pda::pda(vector<Node*> q, std::vector<char> s, vector<char> g, vector< vector<Node*> > d, vector<Node*> qS, vector<Node*> qA) : states(q), sigma(s), gamma(g), delta(d), qStart(qS), qAccept(qA), stack({0}){

  numStates = states.size();

  int sigma_size = sizeof(sigma) / sizeof(sigma[0]);

  if (sigma_size < 0){
    perror("Sigma is not formatted correctly");
    exit(0);
  }

  //keep track of which number is associated with which node in delta. delta[row][0] is where the Node states[row] goes to on "0",
  //index 1 is for "1",and index 2 is reserved for "epsilon".
  int alphaOption = 0;

  //Setting up the PDA. Start with the list of Nodes in states variable and as you encounter their transitions in delta, connect them
  //using delta0 and delta1. The elements in delta are pairs of transitions for the states in q. The first of the pair is a node's 
  //transition on '0' and the second is the transition on '1'. Use setDelta0(it.first()) and setDelta1(it.second()) to
  //set the transition values

  auto it = states.begin();

  for (it; it != states.end(); ++it){
    if (it == states.begin()){ //if iterator is at the beginning, the node it points to will be the start state
      (*it)->setIsStart(true);
      qStart.push_back(*it);
    }
    else{
      (*it)->setIsStart(false);
    }
    //connect the Nodes
    for (auto row = delta.begin(); row != delta.end(); ++row){
      if(row->size() != sigma_size){
	perror("Delta not formatted correctly.");
      }

      alphaOption = 0;
		  
      for (auto col = row->begin(); col != row->end(); ++col){
	if(*col != NULL){
	  if (alphaOption == 0){
	    (*it)->setDelta0(*col);
	    alphaOption++;
	  } //else if
	  else if (alphaOption == 1){
	    (*it)->setDelta1(*col);
	    alphaOption++;
	  } //else if
	  else if (alphaOption == 2){
	    (*it)->setDeltaE(*col);
	    alphaOption++;
	  } //else if
	  else{
	    perror("Incorrect format on transition function");
	    exit(0);
	  }
	} // *col == NULL
	else{
	  perror("Incorrect format on transition function");
	  exit(0);
	}
      }	//for col	    

    } //for row

    if ((*it)->getDelta0() == NULL && (*it)->getDelta1() == NULL && (*it)->getDeltaE() == NULL){
      (*it)->setDelta0(*it);
      (*it)->setDelta1(*it);
      (*it)->setDeltaE(*it);
      
    } //else

    if((*it)->getIsAccept() == true){
      qAccept.push_back((*it));
    }
    if((*it)->getIsStart() == true){
      qStart.push_back((*it));
    }

  } //for it
  
} //pda constructor

pda::~pda(){
  for(int i = 0; i < 1000; i++){
    delete(states[i]);
  }
} 

void pda::createNode(){
  Node * n = new Node();
  Node * next = new Node();

  auto it = states.end();
  
  n = *it;

  states.push_back(next);

  delete[] n;
  delete[] next;

}

void pda::setStack(vector<char> s){
  stack = s;
}

void pda::deleteNode(Node * n){
  delete[] n;
}

void pda::setDelta(vector< std::vector<Node *> > v){
  delta = v;
}

void pda::setStates(vector<Node*> q){
  states = q;
}

void pda::setSigma(vector<char> s){
  sigma = s;
}

void pda::setGamma(vector<char> g){
  gamma = g;
}

void pda::setQStart(vector<Node*> n){
  qStart = n;
}

void pda::setQAccept(vector<Node*> n){
  qAccept = n;
}

void pda::setNumStates(int m){
  numStates = m;
}

vector<char> pda::getStack(){
  return stack;
}

vector<vector<Node *> > pda::getDelta(){
  return delta;
}

vector<Node*> pda::getStates(){
  return states;
}

vector<char> pda::getSigma(){
  return sigma;
}

vector<char> pda::getGamma(){
  return gamma;
}

vector<Node*> pda::getQStart(){
  return qStart;
}

vector<Node*> pda::getQAccept(){
  return qAccept;
}

int pda::getNumStates(){
  return numStates;
}
