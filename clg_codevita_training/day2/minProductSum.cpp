#include "iostream"

using namespace std;

int main(){
	int n,k,sum,min = 100000,mod_pos=-1;
	cin>>n>>k;
	int a1[n],a2[n];

	for (int i = 0; i < n; ++i)
		cin>>a1[i];

	for (int i = 0; i < n; ++i)
		cin>>a2[i];

	sum = 0;
	for (int j = 0; j < n; ++j)
		sum = sum + a1[j]*a2[j];

	for (int i = 0; i < 2*n; ++i){

		if(min > sum)
			min = sum;

		// modification
		if(i%2 == 0){
			mod_pos++;
			a1[mod_pos]+= 2*k;
		}
		if(i%2 == 1){
			a1[mod_pos]-= 2*k;
		}

		// calculating sum of products
		sum = 0;
		for (int j = 0; j < n; ++j)
			sum = sum + a1[j]*a2[j];

		// reverse the modification
		if(i%2 == 0){
			a1[mod_pos]-= 2*k;
		}
		if(i%2 == 1){
			a1[mod_pos]+= 2*k;
		}
	}

	cout<<min<<endl;
}