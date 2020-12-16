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

int main(){
	cout << "Welcome to console calculator" << endl;
	cout << "Select mode:" << endl << "1 Expression mode" << endl << "2 two numbers mode" << endl;
	string modeInput;
	short int modeNumber;
	bool complete = false;

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
	cout << "Enter expression:" << endl;
	string input;
	cin >> input;
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




