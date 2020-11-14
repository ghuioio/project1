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
void movefront(string s, string a[]){
	for  (int i=0; i < s.length(); i++){
		a[i] = s.at(i) + a[i];
	}
}
string BWT(){
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

		result = lastchar(v,size);
		cout << endl << "BWT success !" << endl;
		cout << endl << "bwt = " << result << endl;
		findkey(text, v);
		return result;
    }


string Rev_BWT(string text) {
    	cout << "Your text is: " << text << endl;
    	cout << "Key is : "; int key; cin >> key;
    	while ( key < 0 ) {
    		cout << "Your key must be greater or equal to 0." << endl;
    		cout << "Key is : "; cin >> key;
    	}
        int size = text.length();
		string revrotations[size];
		vector<string> v;
		for (int cycles = 0; cycles < size; cycles++){
			movefront(text, revrotations );
			for (int i=0; i < size; i++){
				v.push_back(revrotations[i]);
			}
			sort(v.begin(), v.end(), mycomp);

			for (int i=0; i < size; i++){
				revrotations[i] = v[i];

			}
			v.clear();

		}
		cout << endl << "RevBWT success !" << endl;
		cout << "Your key is " << key << endl;
		cout << "RevBWT  = "<< revrotations[key];
		//return  revrotations[key];
    }

