#pragma once
#include"bwt_sa.hpp"
#include"mtf.hpp"
#include"rle.hpp"
#include"huffman.hpp"
#include"open.hpp"
int main(){ //string c = "phamminhkhoi";
    string c = open_file("a.txt"); cout << c;
    //c = BWT(c);
    //c = mtf(c); cout << "mtf:" << c << endl ;
    //int w; int *weigth = new int[w]; string d ="";
    //rle(c, weigth, d); //cout <<"rle:"<< c <<endl << endl;
    string str = buildhuffman(c);
    enzip(str);
    c = return_huffman(str);
    //rev_rle(c, weigth, d);
   // c = rev_mtf(c); cout <<"rev_mtf:" << c << endl;
    //c = Rev_BWT(c);
    return 0;
}
