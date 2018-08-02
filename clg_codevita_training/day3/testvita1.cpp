#include "iostream"

using namespace std;

int main(){
	int t,m,addHr,sumHrs,temp;
	cin>>t;

	for (int i = 0; i < t; ++i){
		cin>>m;
		int modHrDep[m][3];
		for (int j = 0; j < m; ++j){
			cin>>modHrDep[j][0];
			cin>>modHrDep[j][1];
			cin>>modHrDep[j][2];
		}
		for (int j = 0; j < m; j++){
			for (int k = 0; k < m-1-j; k++){
				if(modHrDep[k][2] > modHrDep[k+1][2]){
					temp = modHrDep[0][k];
					modHrDep[k][0] = modHrDep[k+1][0];
					modHrDep[k+1][0] = temp;

					temp = modHrDep[k][1];
					modHrDep[k][1] = modHrDep[k+1][1];
					modHrDep[k+1][1] = temp;

					temp = modHrDep[k][2];
					modHrDep[k][2] = modHrDep[k+1][2];
					modHrDep[k+1][2] = temp;
				}
			}
		}
		sumHrs = 0;
		addHr = modHrDep[0][1];
		for (int j = 0; j < m-1; ++j){
			if(modHrDep[j][2] == modHrDep[j+1][2]){
				if(addHr < modHrDep[j][1])
					addHr = modHrDep[j][1];
			}
			else{ //no equal to previous module
				sumHrs += addHr + mod;
				cout<<"Adding - "<<addHr<<endl;
				addHr = 0;
			}
		}
		sumHrs += addHr;
		cout<<sumHrs;

	}

	return 0;
}