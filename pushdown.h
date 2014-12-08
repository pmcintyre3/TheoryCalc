#ifndef _PUSHDOWN_H_
#define _PUSHDOWN_H_

#include <string>
#include <vector>

#include "state.h"

class pushdown{

 private:
  std::vector<char> stack;
  std::vector<state*> states;
  std::vector<state*> start;
  std::vector<state*> F;
  std::string answer;

 public:
  pushdown();
  ~pushdown();

  std::string addition(std::string);
  std::string subtraction(std::string);
  std::string multiplication(std::string);
  std::string division(std::string);

  void setStates();
  void setStack(std::vector<char>);
};


#endif
