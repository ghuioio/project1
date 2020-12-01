#include <bits/stdc++.h>

using namespace std;
// mở file
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
		file_contents += s + "\n";
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
//nén xâu nhị phân thành xâu ký tự trong file encode
void enzip(string str){

    ofstream fileOutput;
	fileOutput.open("Encode.txt");


	if (fileOutput.fail())
	{
		cout << "Failed to open this file!" << endl;
	}


	//chuyển dãy nhị phân thành chuỗi và lưu vào file nén
	while ((unsigned int)str.length() >= 8)
	{
		string byte = str.substr(0, 8);
		bitset<8> set(byte);
		const char toWrite = (unsigned char)((unsigned int)set.to_ulong());
		fileOutput.write(&toWrite, sizeof(unsigned char));
		str = str.substr(8, str.length() - 8);
	}
	int n;
	n = str.size();
	//lưu dãy còn dư vào file (xử lý đuôi)
	for (int i = 0; i < n; i++)
	{
		fileOutput.write(&str[i], sizeof(unsigned char));
	}
    fileOutput << str << endl;
	fileOutput.close();




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
		bitStream += s + "\n";
	}

    //int n = bitStream.length();
	bitStream.pop_back();
	fileInput2.close();

	string str3 = "";
	for (int i = 0; i < bitStream.size() - n; i++)
	{
		str3 += charToBin(bitStream[i]);
	}

	for (int i = bitStream.size() - n; i < bitStream.size(); i++)
	{
		str3 += bitStream[i];
	}
	str = str3;
	cout << str;
}
// biến xâu ký tự thành xâu nhị phân


// đưa ra xâu nhị phân
