#ifndef _NODE_H_
#define _NODE_H_

//Node represents nodes in a pushdown automata.
//The next pointers are pointers for the values
//0 or 1 in the language

class Node{
  
 private:
  bool isStart; //------------------- Determines if it is a start state
  bool isAccept; //------------------ Determines if it is an accept state
  bool isReject;

  Node* delta0; //------------------- On input "0", will point to another node
  Node* delta1; //------------------- On input "1", will point to another node
  Node* deltaE; //------------------- On input "epsilon" (empty string), will point to another node

  friend class PDA; //--------------- Allows PDA class to edit these values

 public:
  Node(); //------------------------ Constructor
  Node(bool, bool, Node*, Node*); // Constructor with values
  ~Node();


  void setIsStart(bool); //--------- Change isStart value
  void setIsAccept(bool); //-------- Change isAccept value
  void setIsReject(bool); //-------- Change isReject value
  void setDelta0(Node*); //--------- Change delta0 value
  void setDelta1(Node*); //--------- Change delta1 value
  void setDeltaE(Node*); //--------- Change deltaE value

  bool getIsStart(); //------------- Retrieve isStart value
  bool getIsAccept(); //------------ Retrieve isAccept value
  Node* getDelta0(); //------------- Retrieve delta0 value
  Node* getDelta1(); //------------- Retrieve delta1 value
  Node* getDeltaE(); //------------- Retrieve deltaE value

}; //Node.h

#endif
