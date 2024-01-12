#include<bits/stdc++.h>
using namespace std;
map<string, string> cipher1 ;
map<string, string> cipher2 ;
map<string, string> cipher3 ;

void CipherData1()
{
    cipher1["a"] = "Q";
    cipher1["b"] = "W";
    cipher1["c"] = "E";
    cipher1["d"] = "R";
    cipher1["e"] = "T";
    cipher1["f"] = "Y";
    cipher1["g"] = "U";
    cipher1["h"] = "I";
    cipher1["i"] = "O";
    cipher1["j"] = "P";
    cipher1["k"] = "A";
    cipher1["l"] = "S";
    cipher1["m"] = "D";
    cipher1["n"] = "F";
    cipher1["o"] = "G";
    cipher1["p"] = "H";
    cipher1["q"] = "J";
    cipher1["r"] = "K";
    cipher1["s"] = "L";
    cipher1["t"] = "Z";
    cipher1["u"] = "X";
    cipher1["v"] = "C";
    cipher1["w"] = "V";
    cipher1["x"] = "B";
    cipher1["y"] = "N";
    cipher1["z"] = "M";
}
void CipherData2()
{
    cipher2["a"] = "U";
    cipher2["b"] = "S";
    cipher2["c"] = "D";
    cipher2["d"] = "F";
    cipher2["e"] = "G";
    cipher2["f"] = "H";
    cipher2["g"] = "J";
    cipher2["h"] = "K";
    cipher2["i"] = "L";
    cipher2["j"] = "Z";
    cipher2["k"] = "X";
    cipher2["l"] = "C";
    cipher2["m"] = "V";
    cipher2["n"] = "B";
    cipher2["o"] = "N";
    cipher2["p"] = "M";
    cipher2["q"] = "P";
    cipher2["r"] = "A";
    cipher2["s"] = "T";
    cipher2["t"] = "Y";
    cipher2["u"] = "I";
    cipher2["v"] = "O";
    cipher2["w"] = "Q";
    cipher2["x"] = "R";
    cipher2["y"] = "W";
    cipher2["z"] = "E";
}
void CipherData3()
{
    cipher3["a"] = "F";
    cipher3["b"] = "T";
    cipher3["c"] = "J";
    cipher3["d"] = "S";
    cipher3["e"] = "K";
    cipher3["f"] = "P";
    cipher3["g"] = "Q";
    cipher3["h"] = "A";
    cipher3["i"] = "W";
    cipher3["j"] = "X";
    cipher3["k"] = "G";
    cipher3["l"] = "Y";
    cipher3["m"] = "U";
    cipher3["n"] = "H";
    cipher3["o"] = "M";
    cipher3["p"] = "C";
    cipher3["q"] = "R";
    cipher3["r"] = "D";
    cipher3["s"] = "E";
    cipher3["t"] = "L";
    cipher3["u"] = "Z";
    cipher3["v"] = "V";
    cipher3["w"] = "B";
    cipher3["x"] = "N";
    cipher3["y"] = "O";
    cipher3["z"] = "I";
}
int main()
{
    CipherData1();
    CipherData2();
    CipherData3();

    string plain;
    cout << "Enter the Plain Text: ";
    getline(cin, plain);

    int divi =  static_cast<int>(round((plain.size())/3));
    string text = "";

    int pos = 0;
    for(pos ; pos<divi ; pos++)
    {
        std::string temp(1,plain[pos]);
        if(cipher1.find(temp) != cipher1.end())
        {
            text+=cipher1[temp];
        }
    }
    for(pos ; pos<divi*2 ; pos++)
    {
        std::string temp(1,plain[pos]);
        if(cipher2.find(temp) != cipher2.end())
        {
            text+=cipher2[temp];
        }
    }
    for(pos ; pos<plain.size() ; pos++)
    {
        std::string temp(1,plain[pos]);
        if(cipher3.find(temp) != cipher3.end())
        {
            text+=cipher3[temp];
        }
    }
    cout << "Cipher Text: " << text <<endl;
}
