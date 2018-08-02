#include "iostream"

using namespace std;

int main(){

	int n;
	cout<<"n = ";
	cin>>n;
	int a[n],b[n];
	int j = 0, k = n-1;
	for (int i = 0 ; i < n; ++i){
		cin>>a[i];
		if (a[i] == 0){
			b[j] = a[i];
			j++;
		}
		else{
			b[k] = a[i];
			k--;
		}
	}
	// // from mam
	// l=0;r=n-1;
	// while(l<r){
	// 	if(a[l]==0)
	// 		l++;
	// 	else if(a[r]==1)
	// 		r--;
	// 	else{
	// 		a[l]=0;a[r]=1;
	// 		l++;r--;
	// 	}
	// }

	for (int i = 0; i < n; ++i){
		cout<<b[i]<<" ";
	}
	return 0;
}