#include "iostream"

using namespace std;

int main(){

	int m,n,row,col;
	cout<<"row,col = ";
	cin>>m>>n;
	int a[m][n], b[m][n];
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			cin>>a[i][j];
			b[i][j] = a[i][j];		
			if(a[i][j] == 0){
				row = i; col = j;
				for (int k = 0; k < m; ++k)
					b[row][k] = 0;
				
				for (int k = 0; k < n; ++k)
					b[k][col] = 0;
			}
		}
	}
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}