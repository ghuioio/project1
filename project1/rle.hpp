#ifndef RLE_HPP_INCLUDED
#define RLE_HPP_INCLUDED
#include<bits/stdc++.h>

using namespace std;
void rle(string s, int *weight, string c){
    string encode = ""; int count = 1; int w = 0;

    for(int i = 0; i< s.length(); i++){
        if (s[i] == s[i+1]) count +=1;
        else{
            encode += to_string(count); weight[w] = count;
            encode += s[i]; c += s[i]; w += 1;
            count = 1;
        }
    }
    s = encode; //cout << s << "  " << c <<endl;
}

void rev_rle(string s, int *weight, string c){
    string decode =""; int n = c.length();
    for (int i = 0; i < n; i++){
        for (int j = 0; j< weight[i]; j++ ){
            decode += c[i];
        }
    }
    s = decode; //cout << decode << endl;
}


#endif // RLE_HPP_INCLUDED
