#include "iostream"

using namespace std;

int main(){
	
	int n,count = 0,rem = 0;
	cin>>n;

	if (n<11){
		count = 2 * n - 1;
		cout<<"1s = "<<n<<endl;
		cout<<"symbols = "<<n-1<<endl;
	}
	else if (n == 11){
		count = 1;
		cout<<"11s = "<<1<<endl;
		cout<<"symbols = "<<n-1<<endl;
	}

	else if (n<121){
		count = 2*(n/11) + (n%11);
		count += count - n/11 - 1;
		cout<<"1s = "<<(n%11)<<endl;
		cout<<"11s = "<<(n/11)<<endl;
		cout<<"symbols = "<<2*(n/11) + (n%11) - n/11 - 1<<endl;
	}
	else{
		while(n!=1){
			n/=11;
			count++;
		}
		cout<<"11s = "<<count<<endl;
		cout<<"symbols = "<<count-1<<endl;
		count = 3*count-1;
	} 

	cout<<count;
	
	return 0;
}