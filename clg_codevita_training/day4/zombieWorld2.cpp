// https://www.codenirvana.in/2014/09/tcs-codevita-2014-problems-round-1.html
#include "iostream"
#define MAX_NO 1000
using namespace std;

int main(){
	
	int n,Zi,BE;

	// input No.of Zombie & Max Time
	cin>>BE>>n;
	int E[n];

	// input energy of n zombies
	for (int j = 0; j < n; ++j){
		cin>>E[j];
		if (E[j] < 1){
			cout<<"Invalid  Input";
			break;
		}
	}
	// input Player Energy and Min Energy Required
	Zi = 0;
	while(Zi!=n){

		// test if player energy is less than zombie
		if(BE < E[Zi])
			break;
		// updating player energy
		BE -= (E[Zi]%2)+(E[Zi]/2);
		Zi++;
	}
	Zi==n ? cout<<"YES" : cout<<"NO";
	return 0;
}