#include "iostream"
#include "vector"

using namespace std;

void createCute(vector< vector<int> > &cutes, int m, int n){
	int number;
	string input_str;

	for (int i = 0; i < m; i++)	{
		// adding a row to vector
		cutes.push_back(vector<int>(0));
		// adding elements to new row
		getline(cin,input_str);
		for (int j = 0; j < input_str.length(); j+=2){
			number = input_str[j] - '0';
			cutes[i].push_back(number);
		}	
	}
	cout<<"created";
}

int main()
{
	int m,n;

	string input_str;

	getline(cin,input_str);

	m = input_str[0] - '0';
	n = input_str[2] - '0';

	vector< vector<int> > cutes(m);

	createCute(cutes,m,n);

	while(cutes.size() != 0){
	}

	return 0;
}