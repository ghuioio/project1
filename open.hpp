#include <bits/stdc++.h>

using namespace std;

string open_file(string F){
    ifstream fileInput;
	fileInput.open(F);

	string file_contents;

	if (fileInput.fail())
	{
		cout << "Failed to open this file!" << endl;
		return 0;
	}

	while (!fileInput.eof())
	{
		string s;
		getline(fileInput, s);
		file_contents += s ;
	}

	//file_contents.pop_back();
	fileInput.close();
	return file_contents;
}
string charToBin(unsigned char c)
{
	string ch = "";
	for (int i = 7; i >= 0; --i)
	{
		unsigned char s = ((c & (1 << i)) ? '1' : '0');
		ch += s;
	}

	return ch;
}

string enzip(string str){

    ofstream fileOutput;
	fileOutput.open("Encode.txt");


	if (fileOutput.fail())
	{
		cout << "Failed to open this file!" << endl;
	}


	while ((unsigned int)str.length() >= 8)
	{
		string byte = str.substr(0, 8);
		bitset<8> set(byte);
		const char toWrite = (unsigned char)((unsigned int)set.to_ulong());
		fileOutput.write(&toWrite, sizeof(unsigned char));
		str = str.substr(8, str.length() - 8);
	}
  
	fileOutput.close();
	return str;
}
string dezip(string str){
    ifstream fileInput2;
	fileInput2.open("Encode.txt");


	if (fileInput2.fail())
	{
		cout << "Failed to open this file!" << endl;
	}
	string bitStream = "";
	while (!fileInput2.eof())
	{
		string s;
		getline(fileInput2, s);
		bitStream += s ;
	}
	//bitStream.pop_back();
	fileInput2.close();
 
	string str3 = "";
	for (int i = 0; i < bitStream.size(); i++)
	{
		str3 += charToBin(bitStream[i]);
	}

	str3 += str;
	str = str3;
	return str;
}
