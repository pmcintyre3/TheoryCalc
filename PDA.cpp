#include <cstdlib>
#include <iostream>

#include "PDA.h"

using namespace std;

PDA::pda() : states(NULL), sigma(''), gamma(''), qStart(NULL), qAccept(NULL){

} //blank pda constructor

PDA::pda(vector<Node*> q, char* s, char* g, pair* d, Node* qS, Node* qA) : states(q), sigma(s), gamma(g), delta(d), qStart(qS), qAccept(qA){
  
  numStates = states.size();
  

} //pda constructor

PDA::~pda(){
  for(int i = 0; i < 1000; i++){
    delete(states[i]);
  }
} 

void PDA::setStates(vector<Node*> q){
  states = q;
}

void PDA::setSigma(char * s){
  sigma = s;
}

void PDA::setGamma(char * g){
  gamma = g;
}

void PDA::setQStart(Node* n){
  n.qStart = !n.qStart;
}

void PDA::setQAccept(Node* n){
  n.qAccept = !n.qAccept;
}

void PDA::setNumStates(int m){
  numStates = m;
}

vector<Node*> PDA::getStates(){
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
