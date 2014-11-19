#include <cstdlib>
#include <iterator>
#include <iostream>

#include "PDA.h"

using namespace std;

PDA::pda() : states(NULL), sigma(''), gamma(''), delta(NULL), qStart(NULL), qAccept(NULL){

} //blank pda constructor

PDA::pda(vector<Node*> q, char* s, char* g, vector<pair<Node*, Node*> > d, Node* qS, Node* qA) : states(q), sigma(s), gamma(g), delta(d), qStart(qS), qAccept(qA){
  
  numStates = states.size();
  
  vector< pair<Node *, Node*> > pI = d.begin();

  for(auto it = q.begin(); it != q.end(); ++it){
    if(it = q.begin())
      setQStart(q);

    for(auto i = pI.begin(); i != pI.end(); ++i){
      if(i != NULL){
	q->setDelta0(i.first());
	q->setDelta1(i.second());
      }
      
    }
  }



} //pda constructor

PDA::~pda(){
  for(int i = 0; i < 1000; i++){
    delete(states[i]);
  }
} 

void PDA::createNode(){
  Node n = new Node::Node();
}

void PDA::deleteNode(Node * n){
  delete n;
}

void PDA::setDelta(vector<int *> v){
  delta = v;
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

vector<int *> PDA::getDelta(){
  return delta;
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
