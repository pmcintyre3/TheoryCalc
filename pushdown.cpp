#include <cstdlib>
#include <cstdio>
#include <utility>
#include <string>
#include <vector>
#include <iostream>

#include "state.h"
#include "pushdown.h"

using namespace std;

pushdown::pushdown(){}

pushdown::~pushdown(){};

string pushdown::addition(string s){

  //PDA Variables
  stack.clear();
  start.clear();
  F.clear();
  answer = "";

  //create Addition PDA
  state* qStart = new state();
  state* q1 = new state();
  state* q2 = new state();
  state* q3 = new state();
  state* qAccept = new state();

  //reject state
  state* nullState = new state();

  //push qS and qA in the right spots
  start.push_back(qStart);
  F.push_back(qAccept);

  //qStart transitions
  qStart->setLabel("qStart");
  pair<state*, char> dQS_E = make_pair(q1, '$');
  pair<state*, char> dQS_0 = make_pair(nullState, ' ');
  pair<state*, char> dQS_1 = make_pair(nullState, ' ');

  qStart->setDeltaE(dQS_E);
  qStart->setDelta0(dQS_0);
  qStart->setDelta1(dQS_1);

  //Q1 transitions
  q1->setLabel("q1");
  pair<state*, char> dQ1_E = make_pair(nullState, ' ');
  pair<state*, char> dQ1_0 = make_pair(q2, ' ');
  pair<state*, char> dQ1_1 = make_pair(q1, '1');

  q1->setDeltaE(dQ1_E);
  q1->setDelta0(dQ1_0);
  q1->setDelta1(dQ1_1);

  //Q2 transitions
  q2->setLabel("q2");
  pair<state*, char> dQ2_E = make_pair(nullState, ' ');
  pair<state*, char> dQ2_0 = make_pair(q3, ' ');
  pair<state*, char> dQ2_1 = make_pair(q2, '1');

  q2->setDeltaE(dQ2_E);
  q2->setDelta0(dQ2_0);
  q2->setDelta1(dQ2_1);

  //Q3 transitions
  q3->setLabel("q3");
  pair<state*, char> dQ3_E = make_pair(qAccept, ' ');
  pair<state*, char> dQ3_0 = make_pair(nullState, ' ');
  pair<state*, char> dQ3_1 = make_pair(nullState, ' ');

  q3->setDeltaE(dQ3_E);
  q3->setDelta0(dQ3_0);
  q3->setDelta1(dQ3_1);

  //qAccept transitions
  qAccept->setLabel("qAccept");
  pair<state*, char> dQA_E = make_pair(nullState, (char) 0);
  pair<state*, char> dQA_0 = make_pair(nullState, (char) 0);
  pair<state*, char> dQA_1 = make_pair(nullState, (char) 0);

  qAccept->setDeltaE(dQA_E);
  qAccept->setDelta0(dQA_0);
  qAccept->setDelta1(dQA_1);

  //add terminating string
  s += " X";

  //run Addition_PDA on w
  state* current = new state();
  state* next = new state();

  const char* c = s.c_str();
  char st = ' ';

  current = start[0];

  //transition from start state first time
  next = current->getDeltaE().first;
  st = current->getDeltaE().second;
  if (st != ' '){
    stack.push_back(st);
  }

  current = next;

  //while its not at the end of the string
  while (*c != 'X'){

    //non-accept states
    //if c is a zero
    if (*c == '0'){
      next = current->getDelta0().first; //move along 'zero' path
      st = current->getDelta0().second; //get stack variable for this path
      if (st != ' '){ //if it has a variable, push it on the stack
	stack.push_back(st);
      }
      c++; //move c
    }
    //if c is a one
    else if (*c == '1'){
      next = current->getDelta1().first; //move along 'one' path
      st = current->getDelta1().second; //get stack variable for this path
      if (st != ' '){ //if it has a variable, push it on stack
	stack.push_back(st);
      }
      c++; //move c
    }
    else if (*c == ' '){ //if c is empty
      next = current->getDeltaE().first; //check epsilon path
      if (&next != &nullState){ //if it doesn't lead to a reject state
	st = current->getDeltaE().second; //grab stack variable for this path
	if (st != ' '){ //if it has a variable, push it on the stack
	  stack.push_back(st);
	}
	c++; //move c
      }
      else{
	perror("Incorrectly formatted state"); //incorrect format
	exit(0);
      }
    }
    current = next; //move pointer

  } //while

  //accept state
  int size = stack.size();

  //if current state is an accept state, return the stack, which has the answer
  if (current == F[0]){
    for (int i = 0; i < size; i++){
      if (stack.back() != '$')
	answer += stack.back();
      stack.pop_back();
    }
    //break;
  }

  delete qAccept;
  delete q1;
  delete q2;
  delete q3;
  delete qStart;
  delete nullState;
  //return the answer
  return answer;
} //addition

string pushdown::subtraction(string s){
  //PDA Variables
  stack.clear();
  start.clear();
  F.clear();
  answer = "";

  //create Addition PDA
  state* qStart = new state();
  state* q1 = new state();
  state* q2 = new state();
  state* q3 = new state();
  state* qAccept = new state();

  //reject state
  state* nullState = new state();

  //push qS and qA in the right spots
  start.push_back(qStart);
  F.push_back(qAccept);

  //qStart transitions
  qStart->setLabel("qStart");
  pair<state*, char> dQS_E = make_pair(q1, '$');
  pair<state*, char> dQS_0 = make_pair(nullState, ' ');
  pair<state*, char> dQS_1 = make_pair(nullState, ' ');

  qStart->setDeltaE(dQS_E);
  qStart->setDelta0(dQS_0);
  qStart->setDelta1(dQS_1);

  //Q1 transitions
  q1->setLabel("q1");
  pair<state*, char> dQ1_E = make_pair(nullState, ' ');
  pair<state*, char> dQ1_0 = make_pair(q2, ' ');
  pair<state*, char> dQ1_1 = make_pair(q1, '1');

  q1->setDeltaE(dQ1_E);
  q1->setDelta0(dQ1_0);
  q1->setDelta1(dQ1_1);

  //Q2 transitions
  q2->setLabel("q2");
  pair<state*, char> dQ2_E = make_pair(nullState, ' ');
  pair<state*, char> dQ2_0 = make_pair(q3, ' ');
  pair<state*, char> dQ2_1 = make_pair(q2, ' ');

  q2->setDeltaE(dQ2_E);
  q2->setDelta0(dQ2_0);
  q2->setDelta1(dQ2_1);

  //Q3 transitions
  q3->setLabel("q3");
  pair<state*, char> dQ3_E = make_pair(qAccept, ' ');
  pair<state*, char> dQ3_0 = make_pair(nullState, ' ');
  pair<state*, char> dQ3_1 = make_pair(nullState, ' ');

  q3->setDeltaE(dQ3_E);
  q3->setDelta0(dQ3_0);
  q3->setDelta1(dQ3_1);

  //qAccept transitions
  qAccept->setLabel("qAccept");
  pair<state*, char> dQA_E = make_pair(nullState, (char) 0);
  pair<state*, char> dQA_0 = make_pair(nullState, (char) 0);
  pair<state*, char> dQA_1 = make_pair(nullState, (char) 0);

  qAccept->setDeltaE(dQA_E);
  qAccept->setDelta0(dQA_0);
  qAccept->setDelta1(dQA_1);

  //add terminating character
  s += " X";

  //run Addition_PDA on w
  state* current = new state();
  state* next = new state();

  const char* c = s.c_str();
  char st = ' ';

  current = start[0];

  //transition from start state first time
  next = current->getDeltaE().first;
  st = current->getDeltaE().second;
  if (st != ' '){
    stack.push_back(st);
  }

  current = next;

  //while its not at the end of the string
  while (*c != 'X'){

    //non-accept states
    //if c is a zero
    if (*c == '0'){
      next = current->getDelta0().first; //move along 'zero' path
      st = current->getDelta0().second; //get stack variable for this path
      if (st != ' '){ //if it has a variable, push it on the stack
	stack.push_back(st);
      }
      c++; //move c
    }
    //if c is a one
    else if (*c == '1'){
      next = current->getDelta1().first; //move along 'one' path
      st = current->getDelta1().second; //get stack variable for this path
      if (st != ' '){ //if it has a variable, push it on stack
	stack.push_back(st);
      }
      else{
	stack.pop_back();
      }
      c++; //move c
    }
    else if (*c == ' '){ //if c is empty
      next = current->getDeltaE().first; //check epsilon path
      if (&next != &nullState){ //if it doesn't lead to a reject state
	st = current->getDeltaE().second; //grab stack variable for this path
	if (st != ' '){ //if it has a variable, push it on the stack
	  stack.push_back(st);
	}
	c++; //move c
      }
      else{
	perror("Incorrectly formatted state"); //incorrect format
	exit(0);
      }
    }
    current = next; //move pointer

  } //while

  //accept state
  int size = stack.size();

  //if current state is an accept state, return the stack, which has the answer
  if (current == F[0]){
    for (int i = 0; i < size; i++){
      if (stack.back() != '$')
	answer += stack.back();
      stack.pop_back();
    }
  }

  stack.clear();
  start.clear();
  F.clear();

  delete qAccept;
  delete q1;
  delete q2;
  delete q3;
  delete qStart;
  delete nullState;

  return answer;
} //subtraction

string pushdown::multiplication(string s){

  const char * c = s.c_str();
  int a = 0;
  int b = 0;
  string w = "";
  string temp = "";

  //count the number of 1s on each side of the zeroes
  while (*c != '\0'){
    while (*c == '1'){
      a++;
      c++;
    }
    if (*c == '0'){
      c++;
    }
    if (*c == '0'){
      b = 0;
      break;
    }
    while (*c == '1'){
      b++;
      c++;
    }
    c++;
  }

  for (int i = 0; i < a; i++){
    temp += "1";
  }
  temp += "00 X";

  while (b > 0){
    w += pushdown::addition(temp);
    b--;
  }

  return w;
} //multiplication

string pushdown::division(string s){

  const char * c = s.c_str();
  int a = 0;
  int b = 0;
  string w = "";
  string temp = "";
  string z = "";

  //count the number of 1s on each side of the zeroes
  while (*c != '\0'){
    while (*c == '1'){
      a++;
      c++;
    }
    if (*c == '0'){
      c++;
    }
    if (*c == '0'){
      b = 0;
      break;
    }
    while (*c == '1'){
      b++;
      c++;
    }
    c++;
  }

  for (int i = 0; i <= a; i++){
    temp += "1";
  }
  temp += "00 X";
  
  if (a < b){
    w = " ";
    return s;
  }

  while (a >= b){

    z = pushdown::subtraction(temp);
    a -= b;
    w += "1";
  }

  return w;
} //division
