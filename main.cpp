#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cctype>
#include <limits>

#include "calculator.h"

using namespace std;

int main(){
  
  //menu items and i/o variables
  calculator calc;
  string option = "";
  int a = 0, b = 0;
  int answer = 0;
  int k = 0;

  //menu loop variable
  int isRunning = 1;

  //title
  cout << "Integer Calculator" << endl << endl;

  //loop
  while(isRunning){
    
    //menu
    cout << "Please select from the options below:" << endl;
    cout << "1. \t Add" << endl;
    cout << "2. \t Subtract" << endl;
    cout << "3. \t Multiply" << endl;
    cout << "4. \t Divide" << endl;
    cout << "5. \t Exit" << endl;
    cout << endl << "Option: ";
    cin >> option;

    //if input is not an integer, trigger cin.fail(). This will clear
    //cin and make sure it doesn't use the faulty input in another
    //variable
    if(cin.fail()){
      cout << "Invalid input!" << endl << endl;
      cin.clear();
      cin.ignore(numeric_limits<int>::max(),'\n');
      continue;
    }//if cin.fail()

    cout << endl;

    //addition
    if(option == "1" || option == "Add" || option == "add"){
      cout << "~Addition~" << endl;
      cout << "Please enter the first number: ";    
      cin >> a;

      //if input is not an integer, trigger cin.fail(). This will clear
      //cin and make sure it doesn't use the faulty input in another
      //variable
      if(cin.fail()){
	cout << "Invalid Input!" << endl << endl;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	continue;
      } //if cin.fail()

      cout << endl;
      cout << "Please enter the second number: ";
      cin >> b;

      //if input is not an integer, trigger cin.fail(). This will clear
      //cin and make sure it doesn't use the faulty input in another
      //variable
      if(cin.fail()){
	cout << "Invalid Input!" << endl << endl;
	cin.clear();
	continue;
      } //if cin.fail()
      cout << endl;

      //reset counter variable
      calc.setAddCount(0);
      answer = calc.add(a , b);
      k = calc.getAddCount();
      
      cout << "The answer is " << answer << endl;
      cout << "Number of Recursions " << k << endl << endl;
    }//addition
  
    //subtraction
    else if(option == "2" || option == "Subtract" || option == "subtract"){
      cout << "~Subtraction~" << endl;
      cout << "Please enter the first number: ";
      cin >> a;

      //if input is not an integer, trigger cin.fail(). This will clear
      //cin and make sure it doesn't use the faulty input in another
      //variable
      if(cin.fail()){
	cout << "Invalid Input!" << endl << endl;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	continue;
      } //if cin.fail()

      cout << "Please enter the second number: ";
      cin >> b;

      //if input is not an integer, trigger cin.fail(). This will clear
      //cin and make sure it doesn't use the faulty input in another
      //variable
      if(cin.fail()){
	cout << "Invalid Input!" << endl << endl;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	continue;
      } //if cin.fail()
      cout << endl;

      //reset counter variable
      calc.setSubCount(0);
      answer = calc.subtract(a , b);
      k = calc.getSubCount();
      
      cout << "The answer is " << answer << endl;
      cout << "Number of Recursions " << k << endl << endl;
    } //subtraction

    //multiplication
    else if(option == "3" || option == "Multiply" || option == "multiply"){
      cout << "~Multiplication~" << endl;

      cout << "Please enter the first number: ";
      cin >> a;

      //if input is not an integer, trigger cin.fail(). This will clear
      //cin and make sure it doesn't use the faulty input in another
      //variable
      if(cin.fail()){
	cout << "Invalid Input!" << endl << endl;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	continue;
      } //if cin.fail()

      cout << "Please enter the second number: ";
      cin >> b;

      //if input is not an integer, trigger cin.fail(). This will clear
      //cin and make sure it doesn't use the faulty input in another
      //variable
      if(cin.fail()){
	cout << "Invalid Input!" << endl << endl;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	continue;
      } //if cin.fail()
      cout << endl;
      
      //reset counter variable
      calc.setMulCount(0);
      answer = calc.multiply(a, b);
      k = calc.getMulCount();
      
      cout << "The answer is " << answer << endl;
      cout << "Number of Recursions " << k << endl << endl;
    } //multiplication

    //division
    else if(option == "4" || option == "Divide" || option == "divide"){
      cout << "~Division~" << endl;
      cout << "Please enter the first number: ";
      cin >> a;

      //if input is not an integer, trigger cin.fail(). This will clear
      //cin and make sure it doesn't use the faulty input in another
      //variable
      if(cin.fail()){
	cout << "Invalid Input!" << endl << endl;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	continue;
      } //if cin.fail()

      cout << "Please enter the second number: ";
      cin >> b;

      //if input is not an integer, trigger cin.fail(). This will clear
      //cin and make sure it doesn't use the faulty input in another
      //variable
      if(cin.fail()){
	cout << "Invalid Input!" << endl << endl;
	cin.clear();
	cin.ignore(numeric_limits<int>::max(),'\n');
	continue;
      } //if cin.fail()
      cout << endl;

      //reset counter variable
      calc.setDivCount(0);
      answer = calc.divide(a, b);
      k = calc.getDivCount();

      cout << "The answer is " << answer << endl;
      cout << "Number of Recursions " << k << endl << endl;
    } //division
    
    //Exit program
    else if(option == "5" || option == "Exit" || option == "exit"){
      //sets loop variable to false
      isRunning = 0;
    }

    //catch-all for invalid input. Does not bail from loop
    else{
      cout << "Invalid input!" << endl << endl;
    } //else

  } //while (isRunning)

  //Exit message
  cout << "Thank you and have a nice day!" << endl << endl;

  return EXIT_SUCCESS;

} //main
