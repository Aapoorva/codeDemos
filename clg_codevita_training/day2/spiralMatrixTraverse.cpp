#include "iostream"

using namespace std;

int main(){
	int n,i,j,count = 0;
	cin>>n;

	int a[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];

	while(count < n/2.0){
		i = count;
		for(j = count ; j <= n-1-count; j++)
			cout<<a[i][j]<<" ";

		j--;
		for(i = i+1; i <= n-1-count; i++)
			cout<<a[i][j]<<" ";

		i--;
		for(j = j-1; j >= count; j--)
			cout<<a[i][j]<<" ";

		j++;
		for(i = i-1; i >= count+1; i--)
			cout<<a[i][j]<<" ";

		count++;
	}
}