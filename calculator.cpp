#include <iostream>
#include <cstdlib>
#include "calculator.h"

using namespace std;

calculator::calculator() : addCount(0), subCount(0), mulCount(0), divCount(0) {};

int calculator::add(int x, int y){

  cout << "x: " << x << " y: " << y << endl;
  if (y == 0) //base case
    return x;
  else if(x >= 0 && y > 0){ //case 1: i.e 2 + 2
    addCount++;
    return calculator::add((x + 1), (y - 1));
  }
  else if(x >= 0 && y < 0){ //case 2: i.e 2 + (-2)
    addCount++;
    return calculator::add((x - 1), (y + 1));
  } //else
  else if(x <= 0 && y > 0){ //case 3: i.e (-2) + 2
    addCount++;
    return calculator::add((x + 1), (y - 1));
  } //else
  else if(x <= 0 && y < 0){ //case 4: i.e (-2) + (-2)
    addCount++;
    return calculator::add((x - 1), (y + 1));
  } //else if
  else{
    addCount = -1;
    cout << endl << "Invalid input" << endl;
    return 0;
  } //else
} //add

int calculator::subtract(int x, int y){
  if (y == 0) //base case
    return x;
  else if(x >= 0 && y > 0){ //case 1: i.e 2 - 2
    subCount++;
    return calculator::subtract((x - 1), (y - 1));
  }
  else if(x >= 0 && y < 0){ //case 2: i.e 2 - (-2)
    subCount++;
    return calculator::subtract((x + 1), (y + 1));
  }
  else if(x <= 0 && y > 0){ //case 3: i.e (-2) - 2
    subCount++;
    return calculator::subtract((x - 1), (y - 1));
  }
  else if(x <= 0 && y < 0){ //case 4: i.e (-2) - (-2)
    subCount++;
    return calculator::subtract((x + 1), (y + 1));
  } //else
  else{
    subCount = -1;
    cout << endl << "Invalid input" << endl;
    return 0;
  } //else
} //subtract

int calculator::multiply(int x, int y){
  cout << "x: " << x << ", y: " << y << endl;
  //base cases --------------------------------

  if (y == 0 || x == 0)
    return 0;
  else if(y % x == x)
    return x;
  else if (y % x == (0 - x))
    return (0 - x); //or -x

  //recursive cases ---------------------------

  else if (x > 0 && y > 0){ //case 1: i.e 2 * 2
    mulCount++;
    return x + calculator::multiply(x, (y - 1));
  } //case 1
  else if (x > 0 && y < 0){ //case 2: i.e 2 * (-2)
    mulCount++;
    return (0 - x) + calculator::multiply(x, (y + 1));
  } //case 2
  else if (x < 0 && y > 0){ //case 3: i.e (-2) * 2
    mulCount++;
    return x + calculator::multiply(x, (y - 1));
  } //case 3
  else if(x < 0 && y < 0){ //case 4: i.e (-2) * (-2)
    mulCount++;
    return (0 - x) + calculator::multiply(x, (y + 1));
  } //case 4

  //error case --------------------------------

  else{
    mulCount = -1;
    cout << endl << "Invalid input" << endl;
    return 0;
  } //else
} //multiply

int calculator::divide(int x, int y){
  cout << "x: " << x << ", y: " << y << endl;

  //base cases --------------------------------

  if(y == 0){
    cout << endl << "Cannot divide by zero!" << endl;
    divCount = -1;
    return -1;
  }
  else if(x == 0){
    return 0;
    cout << "x = 0" << endl;
  }
  else if(y == x || (-y) == (-x)){
    return 1;
    cout << "y == x or -y == -x" << endl;
  }
  else if (y == (-x) || (-y) == x){
    return (-1);
    cout << "y = -x or x = -y" << endl;
  }
  else if(abs(y) > abs(x)){
    cout << "absolute value: divide" << endl;
    return 0;
  }

  //recursive cases ---------------------------
  
  if(x > 0 && y > 0){ //case 1: 10 / 2
    divCount++;
    return 1 + calculator::divide((x - y), y);
  }
  else if(x > 0 && y < 0){ //case 2: 10 / (-2)
    divCount++;
    return (-1) + calculator::divide((x + y), y);
  }
  else if(x < 0 && y > 0){ //case 3: (-10) / 2
    divCount++;
    return (-1) + calculator::divide((x + y), y);
  }
  else if(x < 0 && y < 0){ //case 4: (-10) / (-2)
    divCount++;
    return 1 + calculator::divide((x - y), y);
  }
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
