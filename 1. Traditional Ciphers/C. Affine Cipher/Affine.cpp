#include<iostream>
using namespace std;

string encrypt(string plainText, int K1, int K2){
    string cipherText = "";
    for(auto ch : plainText){
        cipherText.push_back(((ch -'A') * K1 + K2)%26 + 'A');
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
string decrypt(string cipherText, int K1, int K2){
    string decryptedText = "";
    int x,y,K1_inverse;
    int gcd = inverseEuclideanGCD(K1, 26, &x, &y);
    if(gcd == 1){
        K1_inverse = (x%26 + 26) % 26;
    }

    for(auto ch : cipherText){
        decryptedText.push_back(((26 + ch - 'A' - K2) * K1_inverse)%26 + 'A');
    }
    return decryptedText;
}
int main(){
    string plainText = "HELLOWORLD";
    int K1 = 5, K2 = 10;
    cout<<" Plain Text = "<<plainText<<"\tK1 = "<<K1<<"  K2 = "<<K2<<endl;
    string cipherText = encrypt(plainText,K1, K2);
    cout<<" Cipher Text = "<<cipherText<<endl;
    string decryptedText = decrypt(cipherText,K1, K2);
    cout<<" Decrypted Text = "<<decryptedText<<endl;
}

