#include "iostream"

using namespace std;

int main(){
	int n,mid;
	cin>>n;
	mid = n/2;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; j++){
			if(i==mid || j == mid || (i==0 && j>mid) || (i<mid && j==0) || (i>mid && j==n-1) || (i==n-1 && j<mid))
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}