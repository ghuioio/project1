#ifndef MTF_HPP_INCLUDED
#define MTF_HPP_INCLUDED
#include<iostream>

using namespace std;
string ascii() {
	string ascii;
	for(int i = 32; i < 128; i++) {
		ascii += char(i);
	}

	return ascii;
}

char* mtf(char* arr, int n) {
    string ascii = ascii();
	char* encode = new char[n];
	for(int i = 0; i < n; i++) {
		int loc = ascii.find(arr[i]);
		encode[i] = char(loc);
		if (loc != 0) {
			ascii = ascii[loc] + ascii.substr(0, loc) + ascii.substr(loc + 1);
		}
	}
	encode[n] = '\0';
	return encode;
}
char* rev_mtf(char* arr, int n) {
    string ascii = ascii();
	char* decode = new char[n];
	for(int i = 0; i < n; i++) {
		decode[i] = ascii[arr[i]];
		ascii = ascii[arr[i]] + ascii.substr(0, arr[i]) + ascii.substr(arr[i] + 1);
	}
	decode[n] = '\0';
	return decode;
}


#endif // MTF_HPP_INCLUDED
