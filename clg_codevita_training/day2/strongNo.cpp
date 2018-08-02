#include "iostream"

using namespace std;

int fact(int n){
	if(n==1 || n==0)
		return 1;
	return n*fact(n-1);
}

int main(){
	int n,temp,digit,sum = 0;
	cin>>n;
	temp = n;
	while(n!=0){
		digit = n%10;
		sum = sum + fact(digit);
		n/=10;
	}
	temp == sum ? cout<<"yes" : cout<<"no";
}