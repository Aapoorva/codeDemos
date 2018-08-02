#include "iostream"

using namespace std;

int main(){

	int n,temp,rev_n=0,max_digit=0,min_digit=9,digit;
	cin>>n;
	temp = n;
	while(n>0){
		digit = n%10;
		rev_n = rev_n*10 + digit;
		max_digit = max_digit < digit ? digit : max_digit;
		min_digit = min_digit > digit ? digit : min_digit; 
		n=n/10;  
	}
	rev_n == temp ? (cout<<max_digit<<endl) : (cout<<min_digit<<endl);
	return 0;
}


// (n%100 != 0 && n%4 == 0) || n%400 == 0  