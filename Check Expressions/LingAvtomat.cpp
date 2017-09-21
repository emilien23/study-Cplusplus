// LingAvtomat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

 static int k = 0, i = 0;
 static bool correct = true, finish = false; 
 

 enum states{

	 state0,
	 state1,
	 state2,
	 state3,
	 state4,
	 state5,
	 state6,
	 state7,
	 stateError
 };
 states doState0(char sym){ 
	 cout << "State0"<< endl; 
	 if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z'))  
		 return state1; 
	 return stateError; 
 }
 states doState1(char sym){ 
	 cout << "State1" << endl; 
	 if (sym >= '0' && sym <= '9')
		 return state1; 
	 else if (sym ==  ':')
		 return state2; 

	 return stateError; 
 }
 states doState2(char sym){
	 cout << "State2" << endl;
	 switch (sym){ 
	 case '=':
		 return state3; 
	 default: 
		 return stateError; 
	 }
 }
 states doState3(char sym){ 
	 cout << "State3" << endl;
	 if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z') || (sym >= '0' && sym <= '9'))
		 return state4; 
	 if (sym == '(')
	 {
		 k++;
		 return state3;
	 }
	 return stateError;
 }
 states doState4(char sym){
	 cout << "State4" << endl;
	 switch (sym){
	 case '*':
	 case '/':
	 case '+':
	 case '-':
		 return state5;
	 default:
		 return stateError;
	 }
 }
 states doState5(char sym){
	 cout << "State5" << endl;
	 if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z') || (sym >= '0' && sym <= '9'))
		 return state6;
	 if (sym == '(')
	 { 
		 k++;
		 return state3;
	 }
	return stateError;
 }
 states doState6(char sym){
	 cout << "State6" << endl;
	 switch (sym){
	 case '*':
	 case '/':
	 case '+':
	 case '-':
		 return state5;
		 break;
	 case ')':
	 {
		 k--;
		 return state6;
	 }
	 case ';': 
		 return state7;
	 default:
		 return stateError;
		 break;
	 }
 }
 void doStateError(){
	 cout << "StateError" << endl;
	 correct = false; 
	 finish = true;
 }
 void doState7(){ 
	 cout << "State7" << endl; 
	 if (k == 0){
		 correct = true;
		 finish = true;
	 }
	 else
		doStateError();
 }
 
 void start(char str[]){

	 states current_state = state0;


	 while (!finish){ 

		 char current_symbol = str[i];
		 switch (current_state){
			
			case state0: 
				current_state = doState0(current_symbol);
				break;
			case state1:
				current_state = doState1(current_symbol);
				break;
			case state2:
				current_state = doState2(current_symbol);
				break;
			case state3:
				current_state = doState3(current_symbol);
				break;
			case state4:
				current_state = doState4(current_symbol);
				break;
			case state5:
				current_state = doState5(current_symbol);
				break;
			case state6:
				current_state = doState6(current_symbol);
				break;
			case state7:
				doState7();
				break;
			case stateError:
				doStateError();
				break;
		 }
		 i++;
	 }
	 if (current_state == stateError)
		 doStateError(); 
 }

int main(int argc, _TCHAR* argv[])
{
	cout << "Enter expression: " << endl;
	
	char *t = new char[255];
	cin.getline(t, 255);

	char *str = new char[strlen(t) + 1];
	strcpy_s(str, strlen(t) + 1, t); 

	delete[] t;

	start(str);

	if (correct)
		cout << "Verified: correct" << endl; 
	else 
		cout << "Verified: incorrect" << endl;

	delete[] str;

	return 0;
}

