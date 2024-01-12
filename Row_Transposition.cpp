#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain;
    cout << "Enter the Plain Text: ";
    getline(cin, plain);

    cout << "Enter the Key: ";
    int key;
    cin >> key;

    int temp=key;
    int n=0;
    stack<int> keys;
    while(temp)
    {
        keys.push(temp%10);
        temp/=10;
        n++;
    }

    vector<vector<string>> data(n),ans;
    int index=0;
    for(int i=0; i<plain.size() ; i++)
    {
        std::string temp(1,plain[i]);
        if(temp!=" ")
        {
            int pos = index%n;
            data[pos].push_back(temp);
            index++;
        }
    }

    while(!keys.empty())
    {
        int index = keys.top();
        keys.pop();

        ans.push_back(data[(index-1)]);
    }

    string text="";
    for(int i=0 ; i<data[0].size() ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(i<ans[j].size())
            {
                text+=ans[j][i];
            }
            else
            {
                text+="x";
            }
        }
    }
    cout << "Cipher Text: " << text <<endl;
}
