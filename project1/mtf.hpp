#ifndef MTF_HPP_INCLUDED
#define MTF_HPP_INCLUDED
#include<iostream>

using namespace std;
string get_ascii() {
	string ascii;

	for(int i = 32; i < 128; i++) {
		ascii += char(i);
	}

	return ascii;
}
string mtf(string s) {
	string encode; string ascii = get_ascii(); int n = s.length();
	for(int i = 0; i < n; i++) {
		int flag = ascii.find(s[i]);
		encode += char(flag);
		if (flag != 0) {
			ascii = ascii[flag] + ascii.substr(0, flag) + ascii.substr(flag + 1);
		}
	}
	return encode;
}
string rev_mtf(string s) {
    string decode; string ascii = get_ascii(); int n = s.length();
	for(int i = 0; i < n; i++) {
		decode += ascii[s[i]];
		ascii = ascii[s[i]] + ascii.substr(0, s[i]) + ascii.substr(s[i] + 1);
	}
	return decode;
}


#endif // MTF_HPP_INCLUDED
