#include "Node.h"

using namespace std;

Node::Node() : isStart(false), isAccept(false), isReject(false), delta0(NULL), delta1(NULL), deltaE(NULL){};

Node::Node(bool s, bool a, bool r) : isStart(s), isAccept(a), isReject(r), delta0(NULL), delta1(NULL), deltaE(NULL){};

Node::Node(bool s, bool a, bool r, Node* d0, Node* d1, Node* dE) : isStart(s), isAccept(a), isReject(r), delta0(d0), delta1(d1), deltaE(dE) {};

void Node::setIsStart(bool s){
  isStart = s;
}

void Node::setIsReject(bool r){
  isReject = r;
}

void Node::setIsAccept(bool a){
  isAccept = a;
}

Node* Node::setDelta0(Node* n){
  delta0 = n;
}

Node* Node::setDelta1(Node* n){
  delta1 = n;
}

Node* Node::setDeltaE(Node* n){
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

Node* Node::getDelta0(){
  return delta0;
}

Node* Node::getDelta1(){
  return delta1;
}

Node* Node::getDeltaE(){
  return deltaE;
}
