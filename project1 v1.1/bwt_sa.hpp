#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct rotation {
	int index;
	char* suffix;
};

int cmpfunc(const void* x, const void* y)
{
	struct rotation* rx = (struct rotation*)x;
	struct rotation* ry = (struct rotation*)y;
	return strcmp(rx->suffix, ry->suffix);
}

int* computeSuffixArray(char* input_text,int* suffix_arr, int len_text,unsigned long long int &k)
{
	struct rotation suff[len_text];
	for (int i = 0; i < len_text; i++) {
		suff[i].index = i;
		suff[i].suffix = (input_text + i);
	}
	qsort(suff, len_text, sizeof(struct rotation),cmpfunc);
	for (int i = 0; i < len_text; i++){
		suffix_arr[i] = suff[i].index;
        if(suffix_arr[i] == 0) k = i;}
	return suffix_arr;
}

char* findLastChar(char* input_text,char* bwt_arr,int* suffix_arr, int n){
	int i;
	for (i = 0; i < n; i++) {
		int j = suffix_arr[i] - 1;
		if (j < 0)
			j = j + n;
		bwt_arr[i] = input_text[j];
	}
	bwt_arr[i] = '\0';
	return bwt_arr;
}
