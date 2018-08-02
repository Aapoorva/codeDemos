#include "iostream"
#define MIN -2179367

using namespace std;

int main(){

	int n,max,sec_max;
	cout<<"n = ";
	cin>>n;
	int a[n],b[n];
	int j = 0, k = n-1;
	for (int i = 0 ; i < n; ++i){
		cin>>a[i];
	}
	max = sec_max = MIN;
	for (int i = 1; i < n; ++i){
		if(max < a[i]){
			sec_max = max;
			max = a[i];
		}
		else if(sec_max < a[i] && a[i] != max)
			sec_max = a[i];
	}
	if (sec_max == MIN)
		cout<<"no sec max";
	else 
		cout<<sec_max;
	return 0;
}