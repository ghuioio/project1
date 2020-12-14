#pragma once
#include"bwt_sa.hpp"
#include"mtf.hpp"
#include"rle.hpp"
#include"huffman.hpp"
#include"open.hpp"
static string c;
void nen(){
    c = open_file("a.txt");
    c = BWT(c);
    c = mtf(c);
    c = buildhuffman(c);
    c = enzip(c); 
}

void giai_nen(){
    c =dezip(c); 
    c = return_huffman(c); 
    c = rev_mtf(c);
    Rev_BWT(c);
}
int main(){
    nen();
    giai_nen();
    return 0;
}
