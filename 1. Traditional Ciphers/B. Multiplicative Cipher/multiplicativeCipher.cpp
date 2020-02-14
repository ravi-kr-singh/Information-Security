#include<iostream>
using namespace std;

string encrypt(string plainText, int k){
    string cipherText = "";
    for(auto ch : plainText){
        cipherText.push_back((k * (ch -'A'))%26 + 'A');
    }
    return cipherText;
}

int inverseEuclideanGCD(int a, int b, int *x, int *y) 
{ 
    if (a == 0) { 
        *x = 0, *y = 1; 
        return b; 
    } 

    int x1, y1; // To store results of recursive call 
    int gcd = inverseEuclideanGCD(b%a, a, &x1, &y1); 

    // Update x and y using results of recursive 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    
    return gcd; 
} 
string decrypt(string cipherText, int K){
    string decryptedText = "";
    int x,y,K_inverse;
    int gcd = inverseEuclideanGCD(K, 26, &x, &y);
    if(gcd == 1){
        K_inverse = (x%26 + 26) % 26;
    }

    for(auto ch : cipherText){
        decryptedText.push_back((K_inverse * (ch - 'A'))%26 + 'A');
    }
    return decryptedText;
}
int main(){
    string plainText = "HELLOWORLD";
    int key = 5;
    cout<<" Plain Text = "<<plainText<<"\tkey = "<<key<<endl;
    string cipherText = encrypt(plainText,key);
    cout<<" Cipher Text = "<<cipherText<<endl;
    string decryptedText = decrypt(cipherText,key);
    cout<<" Decrypted Text = "<<decryptedText<<endl;
}

