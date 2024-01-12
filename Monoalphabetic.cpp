#include<bits/stdc++.h>
using namespace std;
map<string,string> cipher ;

void CipherData()
{
    cipher["a"]="Q";
    cipher["b"]="W";
    cipher["c"]="E";
    cipher["d"]="R";
    cipher["e"]="T";
    cipher["f"]="Y";
    cipher["g"]="U";
    cipher["h"]="I";
    cipher["i"]="O";
    cipher["j"]="P";
    cipher["k"]="A";
    cipher["l"]="S";
    cipher["m"]="D";
    cipher["n"]="F";
    cipher["o"]="G";
    cipher["p"]="H";
    cipher["q"]="J";
    cipher["r"]="K";
    cipher["s"]="L";
    cipher["t"]="Z";
    cipher["u"]="X";
    cipher["v"]="C";
    cipher["w"]="V";
    cipher["x"]="B";
    cipher["y"]="N";
    cipher["z"]="M";
}

int main()
{
    CipherData();
    string plain;
    cout << "Enter the Plain Text: ";
    getline(cin, plain);

    string text = "";
    for(int i=0 ; i<plain.size() ; i++)
    {
        std::string temp(1,plain[i]);
        if(cipher.find(temp) != cipher.end())
        {
            text+=cipher[temp];
        }
    }
    cout << "Cipher Text: " << text <<endl;
}
