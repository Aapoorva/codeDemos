// https://www.codenirvana.in/2014/09/tcs-codevita-2014-problems-round-1.html
#include "iostream"

using namespace std;

int main(){

	string str;
	int freq[26], flag = 1;

	getline(cin,str);

	for (int i = 0; i < 26; ++i){
		freq[i] = 0;
	}

	// calculating freq of letters
	for(int i = 0; i < str.length(); i++){
		freq[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; ++i){
		if(freq[i] != 0 && freq[i] != i + 1 ){
			flag = 0;
			break;
		}
	}
	flag == 1 ? cout<<"YES" : cout<<"NO";
	return 0;
}