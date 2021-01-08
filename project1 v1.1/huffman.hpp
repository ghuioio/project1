#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;


map<char, string> codes;


map<char, int> freq;


struct Node
{
    char data;             // One of the input characters
    int freq;             // Frequency of the character
    Node *left, *right; // Left and right child

    Node(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};


struct compare
{
    bool operator()(Node* l, Node* r)
    {
        return (l->freq > r->freq);
    }
};

void encode(struct Node* root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    encode(root->left, str + "0");
    encode(root->right, str + "1");
}

void storeCodes(struct Node* root, string str)
{
    if (root==NULL)
        return;
    if (root->data != '$')
        codes[root->data]=str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}
priority_queue<Node*, vector<Node*>, compare> minHeap;

void HuffmanCodes(int size)
{
    struct Node *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new Node(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

void calcFreq(string str, int n)
{
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}

string decode_file(struct Node* root, string s)
{
    string ans = "";
    struct Node* curr = root;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0')
           curr = curr->left;
        else
           curr = curr->right;
        if (curr->left==NULL and curr->right==NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    // cout<<ans<<endl;
    return ans+'\0';
}
string buildhuffman(string str){
    string encodedString, decodedString;
    calcFreq(str, str.length());
    HuffmanCodes(str.length());
    //cout << "Character With there Frequencies:\n";
    //for (auto v=codes.begin(); v!=codes.end(); v++)
    //cout << v->first <<' ' << v->second << endl;

    for (auto i: str)
        encodedString+=codes[i];


    //cout << "\nEncoded Huffman data:\n" << encodedString << endl;
    str = encodedString;
    return encodedString;

}
string return_huffman(string encodedString){
    string decodedString = decode_file(minHeap.top(), encodedString) ;
    decodedString = decodedString.substr(0,decodedString.size()-1);
    //cout << "\nDecoded Huffman Data:\n" << decodedString << endl;
    return decodedString;
}

