#include<iostream>
#include<string>
#include<fstream>

#include<algorithm>
#include<array>
#include<string.h>
#include<bits/stdc++.h>
#include<vector>

using namespace std;


void genRotations(string source, string s[] ){
    s[0] = source;
	for (int i = 1; i < source.length(); i++)
		{
			s[i] = s[i-1].substr(1) + s[i-1].at(0);}
	for (int i = 0; i < source.length(); i++){
        cout << s[i] <<endl;
	}
}

string lastchar(vector<string> s, int size)
	{
		string result = "";
		for (int i=0; i < size; i++)
		{
			result = result + s[i].at(size-1);
		}
		return result;
	}


bool mycomp(string a, string b){
	return a<b;}
//////

void findkey (string source, vector<string> v){
	int key;
	for (int i=0; i <source.length(); i++){
		string match = v[i];
		while (match == source) {
			key = i;
			cout << "key = " << key << endl;
			return;
		}
	}
}

int main(){
	int starttest;
	cout << "Encrypt(Press 1) or Decrypt(Press 2): ";
	cin >> starttest;
	if (starttest == 1) {
		cout << "Your text is: ";
		string text;
		cin >>text;
		int size = text.length();
		string rotations[size];
		string result = "";
		genRotations(text, rotations);

        cout << endl;
		vector<string> v;
		for (int i=0; i < size; i++){
		    v.push_back(rotations[i]);
		}

		sort(v.begin(), v.end(), mycomp);
		for (int i=0; i < size; i++){
		    cout << v[i] <<endl;
		}
		result = lastchar(v,size);
		cout << endl << "bwt = " << result << endl;
		findkey(text, v);

    }

}
