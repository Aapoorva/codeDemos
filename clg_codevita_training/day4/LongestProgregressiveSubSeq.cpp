#include "iostream"

using namespace std;

int main(){
	int n,i,length,maxLength,l,r;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i];

	length = maxLength = 1;

	for (i = 1; i < n; ++i){
		if(a[i-1] > a[i]){
			if (maxLength < length){
				maxLength = length;
				l = i - maxLength;
				r = i - 1;
			}
			length = 1;
		}
		else
			length++;
	}

	if (maxLength < length){
		maxLength = length;
		l = i - maxLength;
		r = i - 1;
	}

	for (i = l; i <= r ; ++i)
		cout<<a[i]<<" ";

	return 0;
}