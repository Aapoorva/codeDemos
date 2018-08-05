#include "iostream"
#include "stack"

using namespace std;

int eval(int num1, int num2, char op){
	switch (op) {
		case '+':
			return num2 + num1;
		case '-':
			return num2 - num1;
		case '*':
			return num2 * num1;
		case '/':
			return num2 / num1;
		case '^':
			return num2 ^ num1;
	}
}

int evaluate(string postfixExp){
	stack<int> numStack;
	int num1, num2;

	for (int i = 0; postfixExp[i] != '\0' ; ++i){
		if (postfixExp[i] == '*' || postfixExp[i] == '-' || postfixExp[i] == '+' || postfixExp[i] == '/' || postfixExp[i] == '^'){

			if(numStack.size()>1){
				num1 = numStack.top();
				numStack.pop();
				num2 = numStack.top();
				numStack.pop();
				numStack.push(eval(num1,num2,postfixExp[i]));
			}
		}
		else
			numStack.push(postfixExp[i] - '0');
	}
	return numStack.top();
}

int main(){
	string postfixExp;
	getline(cin,postfixExp);

	cout<<evaluate(postfixExp);

	return 0;
}