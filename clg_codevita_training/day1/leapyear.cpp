#include "iostream"

using namespace std;

int main(){

	int n;
	cin>>n;
	n%100 != 0 && n%4 == 0 || n%400 == 0 ? (cout<<"l"<<endl) : (cout<<"nl"<<endl);
	return 0;
}