#include "iostream"
#include "string"

using namespace std;

int main(){
	string str1,str2;
	int freq1[26],freq2[26];

	getline(cin,str1);
	getline(cin,str2);

	for (int i = 0; i < 26; ++i)
		freq1[i] = freq2[i] = 0;

	for (int i = 0; i < str1.length(); ++i)
		freq1[str1[i]-'a']++;

	for (int i = 0; i < str2.length(); ++i)
		freq2[str2[i]-'a']++;

	for (int i = 0; i < 26; ++i){
		if(freq1[i] != freq2[i]){
			cout<<"Not Anagram"<<endl;
			return 0;
		}
	}
	cout<<"Anagram"<<endl;
	return 0;
}