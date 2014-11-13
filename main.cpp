#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "calculator.h"

using namespace std;

int main(){

  calculator calc;
  int option = 0;
  int a = 0, b = 0;
  int answer = 0;
  int k = 0;


  int isRunning = 1;

  cout << "Integer Calculator" << endl << endl;

  while(isRunning){

    cout << "Please select from the options below:" << endl;
    cout << "1. \t Add" << endl;
    cout << "2. \t Subtract" << endl;
    cout << "3. \t Multiply" << endl;
    cout << "4. \t Divide" << endl;
    cout << "5. \t Exit" << endl;
    cout << endl << "Option: ";
    cin >> option;
    cout << endl;

    if(option == 1){
      cout << "Please enter the first number: ";
      cin >> a;
      cout << endl;

      cout << "Please enter the second number: ";
      cin >> b;
      cout << endl;
      
      calc.setAddCount(0);
      answer = calc.add(a , b);
      k = calc.getAddCount();

      cout << "The answer is " << answer << endl;
      cout << "Number of Recursions " << k << endl << endl;
    }

    else if(option == 2){
      cout << "Please enter the first number: ";
      cin >> a;
      cout << endl;

      cout << "Please enter the second number: ";
      cin >> b;
      cout << endl;
      calc.setSubCount(0);
      answer = calc.subtract(a , b);
      k = calc.getSubCount();

      cout << "The answer is " << answer << endl;
      cout << "Number of Recursions " << k << endl << endl;
    }

    else if(option == 3){
      cout << "Please enter the first number: ";
      cin >> a;
      cout << endl;

      cout << "Please enter the second number: ";
      cin >> b;
      cout << endl;

      calc.setMulCount(0);
      answer = calc.multiply(a, b);
      k = calc.getMulCount();

      cout << "The answer is " << answer << endl;
      cout << "Number of Recursions " << k << endl << endl;
    }

    else if(option == 4){
      cout << "Please enter the first number: ";
      cin >> a;
      cout << endl;

      cout << "Please enter the second number: ";
      cin >> b;
      cout << endl;
      calc.setDivCount(0);
      answer = calc.divide(a, b);
      k = calc.getDivCount();

      cout << "The answer is " << answer << endl;
      cout << "Number of Recursions " << k << endl << endl;
    }

    else if(option == 5){
      isRunning = 0;
    }

    else{
      cout << "Invalid input!" << endl << endl;
    }

  } //while isRunning

  cout << "Thank you and have a nice day!" << endl << endl;

  return EXIT_SUCCESS;

} //main
