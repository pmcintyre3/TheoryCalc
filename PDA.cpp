#include <cstdlib>
#include <utility>
#include <string>
#include <iterator>
#include <iostream>

#include "Node.h"
#include "PDA.h"

using namespace std;

pda::pda(){

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

  n->setDelta0(make_pair((Node*) NULL, (char) NULL));
  n->setDelta1(make_pair((Node*) NULL, (char) NULL));
  n->setDeltaE(make_pair((Node*) NULL, (char) NULL));

  } //blank pda constructor

pda::pda(vector<Node*> q, std::vector<char> s, vector<char> g, vector< vector<pair<Node *, char > >> d, vector<Node*> qS, vector<Node*> qA) : states(q), sigma(s), gamma(g), delta(d), qStart(qS), qAccept(qA), stack({0}){

  
} //pda constructor

pda::~pda(){
  for(int i = 0; i < 1000; i++){
    delete(states[i]);
  }
} 

void pda::createNode(){

  Node * n = new Node();
  states.push_back(n);

}

void pda::deleteNode(Node * n){
  delete[] n;
}

void pda::populate(){

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
    for(auto s = qStart.begin(); s != qStart.end(); ++s){
      if (it == s){ //if iterator points to a member of qStart, then iterator points to a start state
	(*it)->setIsStart(true);
	(*it)->setIsReject(false);
      }
      else{
	(*it)->setIsStart(false);
      }
    } //s = qStart.begin()
    for(auto a = qAccept.begin(); a != qStart.end(); ++a){
      if(it == a){ //if it points to a member of qAccept, then it points to an accept state
	(*it)->setIsAccept(true);
	(*it)->setIsReject(false);
      }
      else{
	(*it)->setIsAccept(false);
      }
    }

    //connect the Nodes
    for (auto row = delta.begin(); row != delta.end(); ++row){
      if(row->size() != sigma_size){
	perror("Delta not formatted correctly.");
      }

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
      }	//for col	    

    } //for row

    if ((*it)->getDelta0().first == NULL && (*it)->getDelta1().first == NULL && (*it)->getDeltaE().first == NULL){
      (*it)->setDelta0(make_pair(*it, ' '));
      (*it)->setDelta1(make_pair(*it, ' '));
      (*it)->setDeltaE(make_pair(*it, ' '));
      
      (*it)->setIsReject(true);
    } //else

  } //for it

}

string pda::run(string s){

  Node * n = states[0];
  char c = (char) NULL;
  //check if input string is part of the alphabet (sigma)
  for(auto it = sigma.begin(); it != sigma.end(); ++it){

    auto found = s.find((*it));
    if(found == string::npos){
      cout << "Incorrectly formatted input string" << endl;
	  return "-1";
    }
    else
      continue;
  }

  stack.push_back('$');

  for(int i = 0; i < s.length(); i++){

    if(s[i] == '0'){
      c = n->getDelta0().second;
      if(c != (char) NULL){	
	stack.pop_back();
      }
      else{
	stack.push_back(s[i]);
      }

      n = n->getDelta0().first;
    }
    else if(s[i] == '1'){
      c = n->getDelta1().second;
      if(c != (char) NULL)
	stack.pop_back();
      else
	stack.push_back(s[i]);

      n = n->getDelta1().first;
    }
    else{
      if(n->getIsReject == true)
	return "-1";

      else if(n->getDeltaE.first != NULL){
	if(c !=(char) NULL)
	  stack.pop_back();
	else
	  stack.push_back(s[i]);

	n = n->getDeltaE().first;
      }

      else{
	cout << "PDA not formatted correctly" << endl;
	return "Incorrect PDA Format";
      }
    }

  }
}

void pda::setStack(vector<char> s){
  stack = s;
}

void pda::setDelta(vector< vector< pair<Node *, char> > > v){
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

vector<vector<pair<Node *, char> > > pda::getDelta(){
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
