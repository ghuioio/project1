#include <iostream>
#include <string>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
#include<array>
#include<string.h>
#include <bits/stdc++.h>

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

string lastchar(string s[], int size)
	{
		string result = "";
		for (int i=0; i < size; i++)
		{
			result = result + s[i].at(size-1);
		}
		return result;
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
		sort(rotations[0],rotations[size]);
		result = lastchar(rotations,size);
		cout << result;

    }

	return 0;
}
