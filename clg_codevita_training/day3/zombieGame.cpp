// https://www.codenirvana.in/2014/09/tcs-codevita-2014-problems-round-1.html
#include "iostream"
#define MAX_NO 1000
using namespace std;

int main(int argc, char const *argv[]){
	
	int t,n,ZLeft,Time,EminReq,ZEmin=MAX_NO,ZLoc,PE;
	cin>>t;
	for (int i = 0; i < t; ++i){
		// input No.of Zombie & Max Time
		cin>>n>>Time;
		int E[n];

		if(n>Time){
			cout<<"No";
			break;
		}

		// input energy of n zombies
		for (int j = 0; j < n; ++j)
			cin>>E[j];
		// input Player Energy and Min Energy Required
		cin>>PE>>EminReq;
		ZLeft = n;
		while(Time!=0){
			// finding zombie with min energy
			for (int k = 0; k < n; ++k){
				if(ZEmin > E[k]){
					ZEmin = E[k];
					ZLoc = k;
				}
			}
			// test if player energy is more than selected zombie which has min energy
			if(PE < ZEmin)
				break;
			// updating player energy
			PE += PE - ZEmin;
			// putting MAX_NO for zombie who is dead
			E[ZLoc] = ZEmin = MAX_NO;
			// reducing time and no. of zombies
			Time--;ZLeft--;
		}
		PE >= EminReq && ZLeft==0 ? cout<<"YES" : cout<<"NO";
	}
	return 0;
}