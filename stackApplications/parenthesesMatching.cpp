#include "iostream"
#include "stack"

using namespace std;

void checkBalancing(string inputStr){
	stack<char> parentheses;
	char currParentheses;

	for (int i = 0; inputStr[i]!='\0'; ++i){
		if (inputStr[i] == '{' || inputStr[i] == '[' || inputStr[i] == '(')
			parentheses.push(inputStr[i]);

		else if (parentheses.size() > 1){
			currParentheses = parentheses.top();
			parentheses.pop();

			if (currParentheses == '{' && inputStr[i] != '}' ){
				cout<<"No\n";
				return;
			}
			else if (currParentheses == '(' && inputStr[i] != ')' ){
				cout<<"No\n";
				return;
			}
			else if (currParentheses == '[' && inputStr[i] != ']' ){
				cout<<"No\n";
				return;
			}
		}
	}
	if (parentheses.size() > 0)
		cout<<"No\n";
	else
		cout<<"YES\n";
}

int main(){
	int t;
	string inputStr;

	cin>>t;
	getline(cin,inputStr);
	
	while(t>0){
		
		getline(cin,inputStr);
		checkBalancing(inputStr);
		t--;
	}

	return 0;
}