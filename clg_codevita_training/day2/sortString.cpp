#include "iostream"
#include "string"

using namespace std;

int main(){
	string str;
	int freq[26], max_loc = 0;

	getline(cin,str);

	for (int i = 0; i < 26; ++i)
		freq[i] = 0;

	for (int i = 0; i < str.length(); ++i)
		freq[str[i]-'a']++;

	for (int i = 0; i < 26; ++i)
		while(freq[i]>0){
			cout<<(char)(i + 'a');
			freq[i]
		}
}