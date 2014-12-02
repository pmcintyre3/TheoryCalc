#include <cstdlib>
#include <utility>
#include <unistd.h>

#include "Node.h"

using namespace std;

Node::Node() : isStart(false), isAccept(false), isReject(false), delta0(NULL), delta1(NULL), deltaE(NULL){};

Node::Node(bool s, bool a, bool r) : isStart(s), isAccept(a), isReject(r), delta0(make_pair(NULL, (char) NULL)), delta1(make_pair(NULL, (char) NULL), deltaE(NULL){};

Node::Node(bool s, bool a, bool r, pair<Node*, char> d0, pair<Node*, char> d1, pair<Node*, char> dE) : isStart(s), isAccept(a), isReject(r), delta0(d0), delta1(d1), deltaE(dE) {};

Node::~Node(){

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

void Node::setDelta0(pair<Node*, char> n){
  delta0 = n;
}

void Node::setDelta1(pair<Node*, char> n){
  delta1 = n;
}

void Node::setDeltaE(pair<Node*, char> n){
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

pair<Node*, char> Node::getDelta0(){
  return delta0;
}

pair<Node*, char> Node::getDelta1(){
  return delta1;
}

pair<Node*, char> Node::getDeltaE(){
  return deltaE;
}
