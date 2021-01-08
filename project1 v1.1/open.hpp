#include <bits/stdc++.h>
typedef std::int32_t index_type;
static index_type block_size = 9e5+1;
using namespace std;

string charToBin(unsigned char c)
{
	string ch = "";
	for (int i = 6; i >= 0; --i)
	{
		unsigned char s = ((c & (1 << i)) ? '1' : '0');
		ch += s;
	}

	return ch;
}
//nén xâu nhị phân thành xâu ký tự trong file encode
string enzip(string str){
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
		//cout << toWrite;
		fileOutput.write(&toWrite, sizeof(unsigned char));
		str = str.substr(8, str.length() - 8);

	}
	int n = str.size();
    //cout << n << " " << str << endl;
	//lưu dãy còn dư vào file (xử lý đuôi)
	for (int i = 0; i < n; i++)
	{
		fileOutput.write(&str[i], sizeof(unsigned char));
	}
    fileOutput << str << endl;
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
	string bitStream;
	while (!fileInput2.eof())
	{
		string s;
		getline(fileInput2, s);
		bitStream += s + "\n";
	}
	bitStream.pop_back();

	//getline(fileInput2, bitStream);
	fileInput2.close();
    //cout << bitStream << endl;

    //cout << bitStream.size() << endl;
	string str3 = "";
	for (int i = 0; i < bitStream.size(); i++)
	{
		str3 += charToBin(bitStream[i]);
	}

	str3 += str;
	//cout << str3 << endl;
	return str3;
}

