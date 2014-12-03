#ifndef _NODE_H_
#define _NODE_H_

//Node represents nodes in a pushdown automata.
//The next pointers are pointers for the values
//0 or 1 in the language

class Node{
  
 private:
  bool isStart; //------------------- Determines if it is a start state
  bool isAccept; //------------------ Determines if it is an accept state
  bool isReject; //------------------ Determines if it is a reject state

  char onStack; //------------------- Character requirement on stack

  std::pair<Node*, char> delta0; //------------------- On input "0", will point to another node
  std::pair<Node*, char> delta1; //------------------- On input "1", will point to another node
  std::pair<Node*, char> deltaE; //------------------- On input "epsilon" (empty string), will point to another node

  friend class PDA; //--------------- Allows PDA class to edit these values

 public:
  Node(); //------------------------ Constructor
  Node(bool, bool, bool); //constructor w/o transition values
  Node(bool, bool, bool, std::pair<Node*, char>, std::pair<Node*, char>, std::pair<Node*, char>); // Constructor with values
  ~Node();

  void setIsStart(bool); //--------- Change isStart value
  void setIsAccept(bool); //-------- Change isAccept value
  void setIsReject(bool); //-------- Change isReject value
  void setOnStack(char); //--------- Change onStack value
  void setDelta0(std::pair<Node*, char>); //--------- Change delta0 value
  void setDelta1(std::pair<Node*, char>); //--------- Change delta1 value
  void setDeltaE(std::pair<Node*, char>); //--------- Change deltaE value

  bool getIsStart(); //------------- Retrieve isStart value
  bool getIsAccept(); //------------ Retrieve isAccept value
  bool getIsReject(); //------------ Retrieve isReject value
  char getOnStack(); //------------- Retrieve onStack value
  std::pair<Node*, char> getDelta0(); //------------- Retrieve delta0 value
  std::pair<Node*, char> getDelta1(); //------------- Retrieve delta1 value
  std::pair<Node*, char> getDeltaE(); //------------- Retrieve deltaE value

}; //Node.h

#endif
