#include "iostream"

using namespace std;

int main(){

	int n,num=0;
	cout<<"n = ";
	cin>>n;
	for (int i = 0; i < n; ++i){
		num = num + (6 + 16*i);
		cout<<num<<" ";
	}
	return 0;
}