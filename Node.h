#ifndef _NODE_H_
#define _NODE_H_

//Node represents nodes in a pushdown automata.
//The next pointers are pointers for the values
//0 or 1 in the language

class Node{
  
 private:
  bool isStart;
  bool isAccept;
  
  Node* delta0;
  Node* delta1;

 public:
  Node();
  Node(bool, bool, Node*, Node*);

  void setIsStart(bool);
  void setIsAccept(bool);
  void setDelta0(Node*);
  void setDelta1(Node*);

  bool getIsStart();
  bool getIsAccept();
  Node* getDelta0();
  Node* getDelta1();

  void createNode();
  void deleteNode();
  
};

#endif
