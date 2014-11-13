#ifndef CALCULATOR_H
#define CALCULATOR_H

class calculator
{
 private:
  int addCount;
  int subCount;
  int mulCount;
  int divCount;

 public:
  calculator();

  int getAddCount();
  int getSubCount();
  int getMulCount();
  int getDivCount();
  void setAddCount(int);
  void setSubCount(int);
  void setMulCount(int);
  void setDivCount(int);

  int add(int, int);
  int subtract(int, int);
  int multiply(int, int);
  int divide(int, int);
}; //calculator

#endif
