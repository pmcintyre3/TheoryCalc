#ifndef _STATE_H_
#define _STATE_H_

#include <string>
#include <utility>

class state
{
 private:
  std::string label;
  std::pair<state*, char> delta0;
  std::pair<state*, char> delta1;
  std::pair<state*, char> deltaE;

 public:
  state();
  ~state();

  void setLabel(std::string);
  void setDelta0(std::pair<state*, char>);
  void setDelta1(std::pair<state*, char>);
  void setDeltaE(std::pair<state*, char>);

  std::string getLabel();
  std::pair<state*, char> getDelta0();
  std::pair<state*, char> getDelta1();
  std::pair<state*, char> getDeltaE();

};

#endif
