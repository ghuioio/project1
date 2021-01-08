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

char* mtf(char* arr, int n) {
    string ascii = get_ascii();
	char* mtfe = new char[n];
	for(int i = 0; i < n; i++) {
		int loc = ascii.find(arr[i]);
		mtfe[i] = char(loc);
		if (loc != 0) {
			ascii = ascii[loc] + ascii.substr(0, loc) + ascii.substr(loc + 1);
		}
	}
	mtfe[n] = '\0';
	return mtfe;
}
char* rev_mtf(char* arr, int n) {
    string ascii = get_ascii();
	char* mtfd = new char[n];

	for(int i = 0; i < n; i++) {
		mtfd[i] = ascii[arr[i]];
		ascii = ascii[arr[i]] + ascii.substr(0, arr[i]) + ascii.substr(arr[i] + 1);
	}
	mtfd[n] = '\0';
	return mtfd;
}


#endif // MTF_HPP_INCLUDED
