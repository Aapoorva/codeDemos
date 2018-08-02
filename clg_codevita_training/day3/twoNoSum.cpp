#include "iostream"

using namespace std;

int main(){
	int n,sum,l,r,flag = 0;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cin>>sum;

	l = 0;
	r = n - 1;
	while(l<r){
		if(a[l] + a[r] == sum){
			flag = 1;
			cout<<a[l]<<" "<<a[r]<<endl;
			break;
		}
		else if(a[l] + a[r] > sum)
			r--;
		else
			l++;
	}
	if(flag==0)
		cout<<"Not Possible";
	return 0;
}