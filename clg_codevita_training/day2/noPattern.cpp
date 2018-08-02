#include "iostream"
#include "math.h"
#include "vector"

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n>0){
		cout<<n<<endl;
		n/=10;
	}
}