#include "iostream"
#include "math.h"

using namespace std;

int isPrime(int n){
	for (int i = 2; i <= sqrt(n); ++i)
		if(n%i==0)
			return 0;
	return 1;
}

int main(){
	string n;
	int digit,flag = 1 ,digit_Pos = 0, noPrime[10];

	getline(cin,n);

	noPrime[0] = 2;
	noPrime[1] = 2;

	for (int i = 2; i < 10; ++i){
		if(isPrime(i))
			noPrime[i] = 1;
		else
			noPrime[i] = 0;
	}

	while(digit_Pos < n.length()){
		digit = n[digit_Pos] - '0';
		// even position
		if(digit<2){
			cout<<"Invalid input";
			break;
		}
		else if((digit_Pos+1)%2 == 0 && noPrime[digit] != 0){
			flag = 0;
			break;
		}
		// odd position
		else if((digit_Pos+1)%2 == 1 && noPrime[digit] != 1){
			flag = 0;
			break;
		}
		digit_Pos++;
	}
	flag==0 ? cout<<"No" : cout<<"Yes";

	return 0;
}

// my logic - add extra loop to count the no. of digits
// my logic has more complexity store no in string