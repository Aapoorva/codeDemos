#include "iostream"

using namespace std;

int main(){
	int n;
	cin>>n;
	for (int i = 0; i <=n; ++i){
		for(int j = i; j <= n ; j++){
			cout<<" ";
		}
		for(int j = 1; j <= 2*i - 1 ; j++){
			if(j==1 || j==2*i-1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<"\n";
	}
	// for (int i = n-1; i <= 0; --i){
	// 	for(int j = i; j <= n ; j++){
	// 		cout<<" ";
	// 	}
	// 	for(int j = 1; j <= 2*i - 1 ; j++){
	// 		if(j==1 || j==2*i-1)
	// 			cout<<"*";
	// 		else
	// 			cout<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	return 0;
}