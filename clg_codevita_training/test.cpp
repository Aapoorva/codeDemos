#include "iostream"
#include "string"

using namespace std;

int main(){
	string str;
	string str2 = "Steve jobs";
	string str3 = "He founded apple";
	str.append(str2);
	str.append(str3,6,3);
	str.append(str3.begin() + 6, str3.end());
	str.append(5,0x2E);
	cout<<str<<'\n';
	return 0;
}