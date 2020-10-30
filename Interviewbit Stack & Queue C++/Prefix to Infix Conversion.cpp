/*
Algorithm for Prefix to Infix:

Read the Prefix expression in reverse order (from right to left)
If the symbol is an operand, then push it onto the Stack
If the symbol is an operator, then pop two operands from the Stack
Create a string by concatenating the two operands and the operator between them.
string = (operand1 + operator + operand2)
And push the resultant string back to Stack
Repeat the above steps until end of Prefix expression.
*/

// CPP Program to convert prefix to Infix
#include <iostream>
#include <stack>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x) {
switch (x) {
case '+':
case '-':
case '/':
case '*':
	return true;
}
return false;
}

// Convert prefix to Infix expression
string preToInfix(string pre_exp) {
stack<string> s;

// length of expression
int length = pre_exp.size();

// reading from right to left
for (int i = length - 1; i >= 0; i--) {

	// check if symbol is operator
	if (isOperator(pre_exp[i])) {

	// pop two operands from stack
	string op1 = s.top(); s.pop();
	string op2 = s.top(); s.pop();

	// concat the operands and operator
	string temp = "(" + op1 + pre_exp[i] + op2 + ")";

	// Push string temp back to stack
	s.push(temp);
	}

	// if symbol is an operand
	else {

	// push the operand to the stack
	s.push(string(1, pre_exp[i]));
	}
}

// Stack now contains the Infix expression
return s.top();
}

// Driver Code
int main() {
string pre_exp = "*-A/BC-/AKL";
cout << "Infix : " << preToInfix(pre_exp);
return 0;
}
