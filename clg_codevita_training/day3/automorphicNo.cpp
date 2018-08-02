#include "iostream"

using namespace std;

int main()
{
	int n;
	cin>>n;
	for (int i = 1; i < n; ++i){
		if(i<10){
			if((i*i)%10 == i)
				cout<<i<<endl;
		}
		else if(i<100){
			if((i*i)%100 == i)
				cout<<i<<endl;
		}
		else if(i<1000){
			if((i*i)%1000 == i)
				cout<<i<<endl;
		}
	}
	return 0;
}