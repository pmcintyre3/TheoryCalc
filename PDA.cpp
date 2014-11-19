#include <cstdlib>
#include <iostream>

#include "PDA.h"

using namespace std;

PDA::pda() : states(NULL), sigma(''), gamma(''), qStart(NULL), qAccept(NULL){
  struct Node * current = new Node(true, false, NULL, NULL);
  states.push_back(current);
  numStates = 0;
  numStates++;
} //blank pda constructor

PDA::pda(vector<struct Node*> q, char* s, char* g, pair* d, struct Node* qS, struct Node* qA) : states(q), sigma(s), gamma(g), delta(d), qStart(qS), qAccept(qA){

  numStates = states.size();

} //pda constructor

PDA::~pda(){
  for(int i = 0; i < 1000; i++){
    delete(states[i]);
  }
} 

void PDA::createNode(){
  struct Node * n = new Node();
  states.push_back(n);
  numStates++;
}

void PDA::deleteNode(){
  delete(states.back());
  states.pop_back();
  numStates--;
}

void PDA::setStates(vector<struct Node*> q){
  states = q;
}

void PDA::setSigma(char * s){
  sigma = s;
}

void PDA::setGamma(char * g){
  gamma = g;
}

void PDA::setQStart(struct Node* n){
  n.qStart = !n.qStart;
}

void PDA::setQAccept(struct Node* n){
  n.qAccept = !n.qAccept;
}

void PDA::setNumStates(int m){
  numStates = m;
}

void PDA::setDelta0(struct Node * c, struct Node * n){
  c.delta0 = n;
}

void PDA::setDelta1(struct Node * c, struct Node * n){
  c.delta1 = n;
}

struct Node* PDA::getDelta0(struct Node * c){
  return c.delta0;
}

struct Node* PDA::getDelta1(struct Node * c){
  return c.delta1;
}


vector<struct Node*> PDA::getStates(){
  return states;
}

char * PDA::sigma(){
  return sigma;
}

char * PDA::gamma(){
  return gamma;
}

struct Node* PDA::getQStart(){
  return qStart;
}

struct Node* PDA::getQAccept(){
  return qAccept;
}

int PDA::getNumStates(){
  return numStates;
}
