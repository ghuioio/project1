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
			s[i] = s[i-1].substr(1);
			}
}

string lastchar(string v[], string s[], int size)
	{
		string result = "";
		for (int i=0; i < size; i++)
		{   string bwt1 = v[i];
			for (int j = 0; j< size; j++){
                string bwt2 = s[j]    ;
				if (bwt2 == bwt1){
				if (j!=0){result += s[0].at(j-1);}
				else {result += "$";}}
			}
		}
		return result;
	}


bool mycomp(string a, string b){
	return a<b;}
//////
void movefront(string s, string a[]){
	for  (int i=0; i < s.length(); i++){
		a[i] = s.at(i) + a[i];
	}
}

int find(string text, string a[],int size){
    char v = '$';
    for (int i = 0; i< size ;i++){
        if(a[i].at(size-1) == v){
            size = i; break;
    }
} return size;
}

string BWT(string text){
		//cout << "Your text is: ";
		//string text;
		//cin >>text;
		text = text + "$";
		int size = text.length();
		string rotations[size];
		string x[size];
		string result = "";
		genRotations(text, rotations);

        cout << endl;
		vector<string> v;
		for (int i=0; i < size; i++){
		    v.push_back(rotations[i]);
		}

		sort(v.begin(), v.end(), mycomp);
		for (int i=0; i < size; i++){
            x[i] = v[i] ;
		}
		result = lastchar(x, rotations, size);
		cout << endl << "bwt = " << result << endl;
		return result;
}

string Rev_BWT(string text){
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
				//cout << revrotations[i] << endl;
			}
			v.clear();

		}
		cout << endl << "RevBWT success !" << endl;
        int s = find(text, revrotations, size);
        revrotations[s] = revrotations[s].substr(0, size-1);
        cout << "RevBWT  = " << revrotations[s] <<endl ;
}


