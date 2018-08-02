#include "iostream"

using namespace std;

int main(){
	
	int n,k,output=0;
	cin>>n;
	int a[n];

	for (int i = 0; i < n; ++i){
		cin>>a[i];
		output = output ^ a[i];
	}
	cin>>k;

	output = output ^ k;

	cout<<output;

	return 0;
}