#include <bits/stdc++.h>
#include"bwt_sa.hpp"
#include"bwt_inv.hpp"
#include"mtf.hpp"
#include"huffman.hpp"
#include"open.hpp"
#pragma once
using namespace std;
const int N = 9e5+1;

static string s;
void nen(){
    char* source = "a.txt";
    FILE* fileopen = fopen(source, "r");;

    char* text = (char*) malloc(N*sizeof(char));
    char* bwt_arr = (char*) malloc((N+1)*sizeof(char));
    int* sa = (int*) malloc(N*sizeof(int));
    struct rotation* suff = (struct rotation*) malloc(N*sizeof(struct rotation));
    int len;
    while(fgets(text, N, fileopen) != NULL){
 //Burrow-Wheeler Transform
        len = strlen(text);unsigned long long int k;
        sa= computeSuffixArray(text,sa, len, k);
        bwt_arr= findLastChar(text,bwt_arr, sa, len); cout << bwt_arr << endl ;
//Move-to-front transform
        //bwt_arr = mtf(bwt_arr, len);//cout << bwt_arr << endl ;
//Huffman
        //s = bwt_arr; //cout << s << endl;
        //s = buildhuffman(s);
        //s = enzip(s); //cout << s  << endl;

// Decode
        //s = dezip(s);
        //s = return_huffman(s);
        //bwt_arr = rev_mtf(bwt_arr, len);cout << bwt_arr << endl ;
        //invert(bwt_arr, k);
        }
        free(text);free(bwt_arr); free(suff); free(sa);
    fclose(fileopen);
}

int main(){
    nen();
}
