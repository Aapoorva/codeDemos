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
	int n,concNo,mul=10,count=0;
    vector<int> prime;
	cin>>n;
	for(int i = 2; i < n; i++)
		if (isPrime(i))
			prime.push_back(i);

	for(int i=0; i<prime.size(); i++){
		for(int j=0; j<prime.size(); j++){
			if(i!=j){

				mul = prime[j] > mul ? mul*10 : mul;

				if(isPrime(prime[i]*mul + prime[j]))
					count++;
				// mul = prime[j]*10 < mul ? mul/10 : mul;
				// cout<<prime[j]*mul + prime[i]<<" ";
				// if(isPrime(prime[j]*mul + prime[i]))
				// 	count++;
				}
		}
		mul = 10;
	}
	cout<<count;
}