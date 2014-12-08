#include "state.h"

using namespace std;

state::state() : label(" "), delta0(make_pair((state*) NULL, (char) 0)), delta1(make_pair((state*) NULL, (char) 0)), deltaE(make_pair((state*) NULL, (char) 0))
{
}


state::~state()
{
}

void state::setLabel(std::string s){
  label = s;
}
void state::setDelta0(std::pair<state*, char> d0){
  delta0 = d0;
}
void state::setDelta1(std::pair<state*, char> d1){
  delta1 = d1;
}
void state::setDeltaE(std::pair<state*, char> dE){
  deltaE = dE;
}

std::string state::getLabel(){
  return label;
}
std::pair<state*, char> state::getDelta0(){
  return delta0;
}
std::pair<state*, char> state::getDelta1(){
  return delta1;
}
std::pair<state*, char> state::getDeltaE(){
  return deltaE;
}
