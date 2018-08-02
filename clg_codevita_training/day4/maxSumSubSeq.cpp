#include "iostream"

using namespace std;

int main(){
	int n,sum,maxSum=0;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];

	sum = a[0];

	for (int i = 1; i < n; ++i){
		if(a[i-1] > a[i]){
			if (maxSum < sum)
				maxSum = sum;
			sum = a[i];
		}
		else
			sum = sum + a[i];
	}

	if (maxSum < sum)
		maxSum = sum;

	cout<<maxSum;

	return 0;
}