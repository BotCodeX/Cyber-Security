#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain;
    cout << "Enter the Plain Text: ";
    getline(cin, plain);

    cout << "Enter the Key: ";
    string key;
    cin >> key;

    vector<vector<string>> data(key.size()),ans;
    int index=0;
    for(int i=0; i<plain.size() ; i++)
    {
        std::string temp(1,plain[i]);
        if(temp!=" ")
        {
            int pos = index%(key.size());
            data[pos].push_back(temp);
            index++;
        }
    }

    string keyN = key;
    sort(keyN.begin(),keyN.end());

    string text = "";
    for(int i=0 ; i<keyN.size() ; i++)
    {
        int pos;
        for(int j=0 ; j<key.size() ;j++)
        {
            if(keyN[i]==key[j])
            {
                pos=j;
                break;
            }
        }
        for(int j=0 ; j<data[pos].size() ; j++)
        {
            text+=data[pos][j];
        }
        if(data[pos].size() < data[0].size())
        {
            text+="x";
        }
    }
    cout << "Cipher Text: " << text <<endl;
}
