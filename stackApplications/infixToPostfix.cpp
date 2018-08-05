#include "iostream"
#include "stack"
#include "string"

using namespace  std;

int operatorPredecence(char op){
	switch (op){
		case '+' :
		case '-' :
			return 1;
		case '*' :
		case '/' :
			return 2;
		case '^' :
			return 3;
	}
	return -1;
}

string postfix(string infixExp){
	string postfixExp;
	stack<char> paraNoperator;
	char stackTop;

	paraNoperator.push('(');

	for (int i = 0 ; infixExp[i] != '\0' ; i++){

		if (infixExp[i] == '(')
			paraNoperator.push('(');

		//it is a number or variable append to postfix expression
		else if ((infixExp[i] >= 'a' && infixExp[i] <= 'z') || (infixExp[i] >= 'A' && infixExp[i] <= 'Z'))
			postfixExp = postfixExp.append(1,infixExp[i]);

		else if (infixExp[i] == ')'){

			stackTop = paraNoperator.top();

			while (stackTop != '('){
				paraNoperator.pop();
				postfixExp = postfixExp.append(1,stackTop);
				stackTop = paraNoperator.top();
			}
			paraNoperator.pop();
		}

		// operator encountered
		else {
			
			stackTop = paraNoperator.top();
			// pop untill all higher priority and same operator at top are removed
			while ( operatorPredecence(stackTop) >= operatorPredecence(infixExp[i])){
				
				paraNoperator.pop();
				postfixExp = postfixExp.append(1,stackTop);
				stackTop = paraNoperator.top();
			}
			// push lower priority operator
			paraNoperator.push(infixExp[i]);
		}
	}
	return postfixExp;
}

int main(){
	string infixExp;
	getline(cin,infixExp);
	infixExp = infixExp.append(1,')');

	cout<<postfix(infixExp);

	return 0;
}