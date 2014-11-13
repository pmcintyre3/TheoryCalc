#include <iostream>
#include "calculator.h"

calculator::calculator() : addCount(0), subCount(0), mulCount(0), divCount(0) {};

int calculator::add(int x, int y){
  if (y == 0) //base case
    return x;
  if(y < 0){
    addCount++;
    return calculator::add((x - 1), (y + 1));
  }
  else{ //recursive
    addCount++;
    return calculator::add((x + 1), (y - 1));
  } //else
} //add

int calculator::subtract(int x, int y){
  if (y == 0) //base case
    return x;
  else if(y < 0){ //recursive if negative
    subCount++;
    return calculator::subtract((x + 1), (y + 1));
  }
  else{ //recursive if positive
    subCount++;
    return calculator::subtract((x - 1), (y - 1));
  } //else
} //subtract

int calculator::multiply(int x, int y){
  if (y == 1)
    return x;
  else if (y == -1)
    return (x - (2*x));
  else if (y < 0){
    mulCount++;
    std::cout << "x: " << x << " y: " << y << std::endl;
    return x + calculator::multiply(x, (y + 1));
  }
  else{
    mulCount++;
    return x + calculator::multiply(x, (y - 1));
  } //else
} //multiply

int calculator::divide(int x, int y){
  if (y > x){
    return 0;
  }
  else if ((x - y) == 0){
    return 1;
  }
  else if(y < 0){
    if(y == -1){
      return x;
    }
    else{
      divCount++;
      return 1 + calculator::divide((x + y), y);
    }
  }
  else{
    if (y == 1)
      return x;
    else{
      divCount++;
      return 1 + calculator::divide((x - y), y);
    } //else
  }//else
} //int

int calculator::getAddCount(){
  return addCount;
} //getAddCount

int calculator::getSubCount(){
  return subCount;
} //getSubCount

int calculator::getMulCount(){
  return mulCount;
} //getMulCount

int calculator::getDivCount(){
  return divCount;
} //getDivCount

void calculator::setAddCount(int s){
  addCount = s;
} //setAddCount

void calculator::setSubCount(int s){
  subCount = s;
} //setSubCount

void calculator::setMulCount(int s){
  mulCount = s;
} //setMulCount

void calculator::setDivCount(int s){
  divCount = s;
} //setDivCount
