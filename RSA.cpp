#include <bits/stdc++.h>
using namespace std;

long int prime1, prime2, product, totient, flag, publicKeys[100], privateKeys[100], temp[100], message[100], encryptedMessage[100];
string plain;


int isPrime(long int pr)
{
    int i;
    long int j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

long int computeD(long int x)
{
    long int k = 1;
    while (true)
    {
        k = k + totient;
        if (k % x == 0)
            return (k / x);
    }
}

void generateKeys()
{
    int k;
    k = 0;
    for (long int i = 2; i < totient; i++)
    {
        if (totient % i == 0)
            continue;
        flag = isPrime(i);
        if (flag == 1 && i != prime1 && i != prime2)
        {
            publicKeys[k] = i;
            flag = computeD(publicKeys[k]);
            if (flag > 0)
            {
                privateKeys[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}

void performEncryption()
{
    long int plaintext, ciphertext, key = publicKeys[0], k, len;
    long int i = 0;
    len = plain.length();
    while (i != len)
    {
        plaintext = message[i];
        plaintext = plaintext - 96;
        k = 1;

            k = k * plaintext;
            k = k % product;

        temp[i] = k;
        ciphertext = k + 96;
        encryptedMessage[i] = ciphertext;
        i++;
    }

    encryptedMessage[i] = -1;
    cout << "\nThe encrypted message is: ";
    for (i = 0; encryptedMessage[i] != -1; i++)
        cout << (encryptedMessage[i] + product) % product << " ";
    cout << endl;
}

void performDecryption()
{
    long int plaintext, ciphertext, key = privateKeys[0], k;
    long int i = 0;
    while (encryptedMessage[i] != -1)
    {
        ciphertext = temp[i];
        k = 1;
        for (long int j = 0; j < key; j++)
        {
            k = k * ciphertext;
            k = k % product;
        }
        plaintext = k + 96;
        message[i] = plaintext;
        i++;
    }
    message[i] = -1;
    cout << "\nThe decrypted message is: ";
    for (i = 0; message[i] != -1; i++)
        cout << (char)message[i];
    cout << "\n";
}


int main()
{
    cout << "Enter p: ";
    cin >> prime1;

    cout << "Enter q: ";
    cin >> prime2;

    cout << "Enter the message: ";
    fflush(stdin);
    getline(cin, plain);

    for (long int  i = 0; plain[i] != NULL; i++)
        message[i] = plain[i];

    product = prime1 * prime2;
    totient = (prime1 - 1) * (prime2 - 1);
    generateKeys();

    cout << "\npublic key is: " << publicKeys[0]<<"  "<<product<<endl;
    cout << "private key is: " << privateKeys[0] <<"  "<<product<<endl;
    cout << "Message is: " << plain << endl;

    performEncryption();
    performDecryption();

    return 0;
}

