// https://www.geeksforgeeks.org/number-whose-xor-sum-given-array-given-number-k/
#include "iostream"

using namespace std;

int main(){
	int n,minSum = 1000,No1,No2,sum;
	cin>>n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin>>a[i];

	for (int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			sum = a[i] + a[j];
			sum = sum < 0 ? -sum : sum;
			if (minSum > sum){
				minSum = sum;
				No1 = a[i];
				No2 = a[j];
							}
		}
	}

	cout<<"minSum = "<<minSum<<"\n";
	cout<<No1<<" "<<No2;
	return 0;
}