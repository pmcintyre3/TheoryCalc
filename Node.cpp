#include <cstdlib>
#include <unistd.h>

#include "Node.h"

using namespace std;

Node::Node() : isStart(false), isAccept(false), isReject(false), delta0(NULL), delta1(NULL), deltaE(NULL){};

Node::Node(bool s, bool a, bool r) : isStart(s), isAccept(a), isReject(r), delta0(NULL), delta1(NULL), deltaE(NULL){};

Node::Node(bool s, bool a, bool r, Node* d0, Node* d1, Node* dE) : isStart(s), isAccept(a), isReject(r), delta0(d0), delta1(d1), deltaE(dE) {};

Node::~Node(){
  delete delta0;
  delete delta1;
  delete deltaE;
}

void Node::setIsStart(bool s){
  isStart = s;
}

void Node::setIsReject(bool r){
  isReject = r;
}

void Node::setIsAccept(bool a){
  isAccept = a;
}

void Node::setOnStack(char c){
  onStack = c;
}

void Node::setDelta0(Node* n){
  delta0 = n;
}

void Node::setDelta1(Node* n){
  delta1 = n;
}

void Node::setDeltaE(Node* n){
  deltaE = n;
}

bool Node::getIsStart(){
  return isStart;
}

bool Node::getIsReject(){
  return isReject;
}

bool Node::getIsAccept(){
  return isAccept;
}

char Node::getOnStack(){
  return onStack;
}

Node* Node::getDelta0(){
  return delta0;
}

Node* Node::getDelta1(){
  return delta1;
}

Node* Node::getDeltaE(){
  return deltaE;
}
