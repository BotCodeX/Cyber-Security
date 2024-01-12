
#include<bits/stdc++.h>
using namespace std;

string inivector = "1100110011001100110011001100110011001100110011001100110011001100";
string data;
vector<string>key48;

int substitutionBoxes[8][4][16] =
{
    {
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    },
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    },
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    },
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    },
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    },
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    },
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    },
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    }
};

string initialPermutation(string block)
{
    vector<int> permutationMatrix =
    {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7
    };
    string ans = "";
    for (int i = 0; i < 64; i++)
    {
        ans += block[permutationMatrix[i] - 1];
    }
    return ans;
}
string PC1(string result)
{
    vector<int> pc1Matrix =
    {
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4
    };
    string ans = "";
    for (int i = 0; i < 56; i++)
    {
        ans += result[pc1Matrix[i] - 1];
    }
    return ans;
}

string PC2(string rev)
{
    vector<int> pc2Matrix =
    {
        14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
    };

    string pc2Block;
    for (int i = 0; i < 48; i++)
    {
        pc2Block += rev[pc2Matrix[i] - 1];

    }
    return pc2Block;
}

string EBitSelection(string ro)
{

    vector<int> eBitMatrix =
    {
        32, 1, 2, 3, 4, 5, 4, 5,
        6, 7, 8, 9, 8, 9, 10, 11,
        12, 13, 12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21, 20, 21,
        22, 23, 24, 25, 24, 25, 26, 27,
        28, 29, 28, 29, 30, 31, 32, 1
    };

    string eBitBlock;
    for (int i = 0; i < 48; i++)
    {
        eBitBlock += ro[eBitMatrix[i] - 1];
    }
    return eBitBlock;
}

string permutation(string per)
{
    vector<int> permutationMatrix =
    {
        16, 7, 20, 21, 29, 12, 28, 17,
        1, 15, 23, 26, 5, 18, 31, 10,
        2, 8, 24, 14, 32, 27, 3, 9,
        19, 13, 30, 6, 22, 11, 4, 25
    };

    string result;
    for (int i = 0; i < 32; i++)
    {
        result += per[permutationMatrix[i] - 1];
    }
    return result;
}


string inverseInitialPermutation(string block)
{
    vector<int> permutationMatrix =
    {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41, 9, 49, 17, 57, 25
    };

    string permutedBlock="";
    for (int i = 0; i < 64; i++)
    {
        permutedBlock += block[permutationMatrix[i] - 1];
    }
    return permutedBlock;
}

string leftCircularShift(string data)
{
    string temp (1,data.front());
    data.erase(data.begin());
    data+=temp;
    return data;
}

string xorString(string a, string b)
{
    if(a.size()!=b.size())
    {
        cout <<"ERROR in XOR";
        return "0";
    }

    string result="";
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == '0' && b[i] == '0' || a[i] == '1' && b[i] == '1')
        {
            result += '0';
        }
        else
        {
            result += '1';
        }
    }
    return result;
}

string SBoxSubs(string exor)
{
    vector<string> temp;
    int i=0,j=6;
    while(i<48)
    {
        string t=exor.substr(i,j);
        temp.push_back(t);
        i+=6;
        j+=6;
    }

    string per="";
    for(int i = 0 ; i<  temp.size(); i++)
    {
        string a(1,temp[i][0]);
        string b(1,temp[i][5]);
        string row = a + b;
        string col = temp[i].substr(1,4);
        int r = stoi(row, nullptr, 2);
        int c = stoi(col, nullptr, 2);
        bitset<4> bin(substitutionBoxes[i][r][c]);
        per += (bin.to_string());
    }
    return per;
}


string toBinary(string plain)
{
    string ans = "";
    for(int i=0 ; i<plain.size(); i++)
    {
        int c = plain[i];
        bitset<8> bin(c);
        ans+=(bin.to_string());
    }
    while(ans.size() % 64 !=0 )
    {
        ans+="00100000";
    }
    return ans;
}

char binaryToAscii(const std::string& binary)
{
    return static_cast<char>(std::bitset<8>(binary).to_ulong());
}

string binaryToHex(string& binary) {
    bitset<4> bits(binary);
    stringstream hexStream;
     hexStream << uppercase << std::hex << bits.to_ulong();
    return hexStream.str();
}

void keyGenerate(string keyf)
{
    string percho1= PC1(keyf);
    string c = percho1.substr(0,28);
    string d = percho1.substr(28);

    for(int shift=1 ; shift<=16 ; shift++)
    {
        if(shift == 1 || shift == 2 || shift == 9 || shift == 16)
        {
            c = leftCircularShift(c);
            d = leftCircularShift(d);
        }
        else
        {
            c = leftCircularShift(c);
            c = leftCircularShift(c);
            d = leftCircularShift(d);
            d = leftCircularShift(d);
        }
        string percho2 = PC2(c+d);
        key48.push_back(percho2);
    }
}

string DES(string plain)
{
    string iniper = initialPermutation(plain);
    string lo = iniper.substr(0,32), ro = iniper.substr(32);
    //cout <<plain <<endl<< iniper <<endl<<lo <<endl<<ro<<endl;

    for(int shift=1 ; shift<=16 ; shift++)
    {
        string ebit = EBitSelection(ro);
        string xori = xorString(ebit,key48[shift-1]);
        string sboxed = SBoxSubs(xori);
        string permuted = permutation(sboxed);
        string exor2 = xorString(lo,permuted);
        lo=exor2;
        if(shift!=16)
        {
            lo=ro;
            ro = exor2;
        }
        //cout << shift <<" " << lo << "  " <<ro <<endl;
    }
    string cypher = inverseInitialPermutation(lo + ro);
    return cypher;
}

vector<string> Encryption(string plain)
{
    data = toBinary(plain);

    vector<string>cipherTexts;
    vector<string>blocks;
    for (int i = 0; i < data.length(); i += 64)
    {
        string block = data.substr(i,64);
        blocks.push_back(block);
    }


    for(int i=0 ; i<blocks.size() ; i++)
    {
        string cipher = DES(blocks[i]);
        cipherTexts.push_back(cipher);

        string resultHex;
        for (int i = 0; i < cipher.size(); i += 4)
        {
            string binaryChunk = cipher.substr(i, 4);
            string hexDigit = binaryToHex(binaryChunk);
            resultHex += hexDigit;
        }
        cout << "Cipher Text: Block : "<< i <<" : " <<resultHex<<endl;
    }
    return cipherTexts;
}

string Decryption(vector<string> cipher)
{
    reverse(key48.begin(),key48.end());
    vector<string> text;

    for(int i=0; i<cipher.size() ; i++)
    {
        string decrypt = DES(cipher[i]);
        text.push_back(decrypt);
    }

    string result ="";
    for(int j=0 ; j<text.size(); j++)
    {
        string asciiResult;
        for (int i = 0; i < 64; i += 8)
        {
            string block = text[j].substr(i, 8);
            asciiResult += binaryToAscii(block);
        }
        result += asciiResult;
    }
    return result;
}

int main()
{
    string plain ;
    cout << "Enter the plain text: ";
    getline(cin,plain);

    string key;
    cout << "Enter the Key (8 character): ";
    cin >> key;
    key = toBinary(key);
    //string key = "0011010000101101101101011010100000011101110110111001000000000100";
    keyGenerate(key);

    vector<string> cipher = Encryption(plain);
    string retrive = Decryption(cipher);
    cout <<endl<< "The text was: " << retrive<<endl;
    return 0;
}
