#include "iostream"
#include "math.h"
#include "vector"

using namespace std;

int isPrime(int n){
	for(int i = 2; i <= sqrt(n) ; i++)
		if (n%i == 0)
			return 0;
	return 1;
}

int main(){
	int n,sum = 0,count=0;
    vector<int> prime;
	cin>>n;
	for(int i = 2; i < n; i++)
		if (isPrime(i))
			prime.push_back(i);

	for(int i=1; i<prime.size(); i++){
		// calculating sum
		sum = 0;
		for(int j=0; j<=i; j++ )
			sum = sum + prime[j];
		if(sum > n)
			break;
		if(isPrime(sum))
			count++;
	}
	cout<<count<<endl;
}