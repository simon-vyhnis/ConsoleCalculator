/*
 * Main.cpp
 *
 *  Created on: Dec 12, 2020
 *      Author: simon
 */
#include <iostream>
#include <string>
using namespace std;

void modeExpression();
void modeTwoNumbers();
int getNumber();
bool checkIfContains(string main, string contains);

int main(){
	cout << "Welcome to console calculator" << endl;
	cout << "Select mode:" << endl << "1 Expression mode" << endl << "2 two numbers mode" << endl;
	string modeInput;
	short int modeNumber;
	bool complete = false;
	//loop until user enters correct mode number
	while(!complete){
			cin >> modeInput;
			try{
				modeNumber = stoi(modeInput);
				switch(modeNumber){
					case(1):
						modeExpression();
						complete = true;
						break;
					case(2):
						modeTwoNumbers();
						complete = true;
						break;
					default:
						cout << "Invalid mode, please enter 1, or 2" << endl;
				}
			}catch(const invalid_argument & e){
				cout << "Invalid mode, please enter 1, or 2" << endl;
			}
		}
	cout << "Thank you for using console calculator" << endl;

}

void modeExpression(){
	string input;
	string rightSide;
	string leftSide;

	int number1;
	int number2;
	int result;
	//loop until user enter a right expression
	while(true){
		cout << "Enter expression:" << endl;
		cin >> input;
		if(checkIfContains(input, "+")){
			//separate numbers from expression
			rightSide = input.substr(0, input.find("+"));
			leftSide = input.substr(input.find("+")+1,input.length());
			//parse numbers to int type
			try{
				number1 = stoi(rightSide);
				number2 = stoi(leftSide);
				result = number1 + number2;
				break;
			}catch(const invalid_argument & e){
				cout << "Invalid expression, available operations: +,-,*,/" << endl;
			}

		}else if(checkIfContains(input, "-")){
			//separate numbers from expression
			rightSide = input.substr(0, input.find("-"));
			leftSide = input.substr(input.find("-")+1,input.length());
			//parse numbers to int type
			try{
				number1 = stoi(rightSide);
				number2 = stoi(leftSide);
				result = number1 - number2;
				break;
			}catch(const invalid_argument & e){
				cout << "Invalid expression, available operations: +,-,*,/" << endl;
			}

		}else if(checkIfContains(input, "*")){
			//separate numbers from expression
			rightSide = input.substr(0, input.find("*"));
			leftSide = input.substr(input.find("*")+1,input.length());
			//parse numbers to int type
			try{
				number1 = stoi(rightSide);
				number2 = stoi(leftSide);
				result = number1 * number2;
				break;
			}catch(const invalid_argument & e){
				cout << "Invalid expression, available operations: +,-,*,/" << endl;
			}
		}else if(checkIfContains(input, "/")){
			//separate numbers from expression
			rightSide = input.substr(0, input.find("/"));
			leftSide = input.substr(input.find("/")+1,input.length());
			//parse numbers to int type
			try{
				number1 = stoi(rightSide);
				number2 = stoi(leftSide);
				result = number1 / number2;
				break;
			}catch(const invalid_argument & e){
				cout << "Invalid expression, available operations: +,-,*,/" << endl;
			}
		}else{
			cout << "Invalid expression, available operations: +,-,*,/" << endl;
		}
	}
	cout << "=" << result << endl;
}


void modeTwoNumbers(){
	int number1;
	int number2;
	cout << "Enter the 1. number:";
	number1 = getNumber();
	cout << "Enter the 2. number:";
	number2 = getNumber();
	int sum = number1 + number2;
	int substract = number1 - number2;
	int multiply = number1 * number2;
	int divide = number1 / number2;
	cout << number1 << " + " << number2 << " = " << sum << endl;
	cout << number1 << " - " << number2 << " = " << substract << endl;
	cout << number1 << " * " << number2 << " = " << multiply << endl;
	cout << number1 << " / " << number2 << " = " << divide << endl;
}

//get cin string and parse it to number
int getNumber(){
	bool complete = false;
	int result;
	string input;
	while(!complete){
		cin >> input;
		try{
			result = stoi(input);
			complete = true;
		}catch(const invalid_argument & e){
			cout << "Invalid number, please enter a normal number" << endl;
		}
	}
	return result;
}

//check if main string contain contains string
bool checkIfContains(string main, string contains){
	return main.find(contains) != string::npos;
}



