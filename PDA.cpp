#include <cstdlib>
#include <iterator>
#include <iostream>

#include "Node.h"
#include "PDA.h"

using namespace std;

pda::pda() : states(NULL), sigma({ 0 }), gamma({ 0 }), delta(NULL), qStart(NULL), qAccept(NULL){

} //blank pda constructor

pda::pda(vector<Node*> q, std::vector<char> s, vector<char> g, vector< vector<Node*> > d, vector<Node> qS, vector<Node> qA) : states(q), sigma(s), gamma(g), delta(d), qStart(qS), qAccept(qA){

	numStates = states.size();

	int sigma_size = sizeof(sigma) / sizeof(sigma[0]);

	if (sigma_size != 3){
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
		if (it == states.begin()) //if iterator is at the beginning, the node it points to will be the start state
			pda::setQStart(*it);

		if ((*it)->getIsAccept == true){

		}
		//connect the Nodes
		for (auto row = delta.begin(); row != delta.end(); ++row){

			alphaOption = 0;

			for (auto col = row->begin(); col != row->end(); ++col){
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

				if ((*it)->getDelta0() == NULL && (*it)->getDelta1() == NULL && (*it)->getDeltaE == NULL){
					(*it)->setIsAccept(false);
					(*it)->setIsReject(true);
				} //if
				else{
					perror("Delta not formatted correctly. Missing transition values");
					exit(0);
				} //else
			}
		}

	}


} //pda constructor

pda::~pda(){
  for(int i = 0; i < 1000; i++){
    delete(states[i]);
  }
} 

void pda::createNode(){
  Node * n = new Node();
}

void pda::deleteNode(Node * n){
  delete n;
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

void pda::setQStart(Node* n){
	qStart = n;
}

void pda::setQAccept(Node* n){
  qAccept = n;
}

void pda::setNumStates(int m){
  numStates = m;
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

struct Node* pda::getQStart(){
  return qStart;
}

struct Node* pda::getQAccept(){
  return qAccept;
}

int pda::getNumStates(){
  return numStates;
}
