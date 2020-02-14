#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_ALPHA 26

int gcd (int num1, int num2);

int main(void)
{
	char p_text[20], c_text[20], d_text[20];
	int key;

	//Get the Plaintext
	printf("Plaintext: ");
	fgets(p_text, 20, stdin);

	//Get the Key
	printf("Key:");
	scanf("%i", &key);

	//Check if key is valid(if it's co-prime or not)
	if (gcd(key, NUM_ALPHA) != 1)
	{
		printf("Invalid Key\n");
		return 1;
	}


	//Creating the ciphertext
	int i, n;
	//iterate over the plaintext
	for (i = 0, n = strlen(p_text); i < n; i++)
	{
		//Implementing Multiplicative Encryption
		if (islower(p_text[i]))
		{
			c_text[i] = ((p_text[i] - 'a' + 1) * key) % 26 + 'a' - 1;
		}

		else if (isupper(p_text[i]))
		{
			c_text[i] = ((p_text[i] - 'A' + 1) * key) % 26 + 'A' - 1;
		}

		else
		{
			c_text[i] = p_text[i];
		}
	}
	c_text[i] = '\0';

	//Print the Ciphertext
	printf("Cipher Text : ");
	fputs(c_text, stdout);

	//Find inverse of the key
	int inverse = 0;
	do
	{
		inverse++;

	} while((key * inverse) % 26 != 1);

	printf("Inverse of the Key : %d\n", inverse);

	char temp;

	//Decrypt the text
	for (i = 0, n = strlen(c_text); i < n; i++)
	{
		if (islower(c_text[i]))
		{
			temp = ((c_text[i] - 'a' + 1) * inverse) % 26;
			if (temp < 0){
				temp += NUM_ALPHA;
			}
			d_text[i] = temp+ 'a' - 1;
		}

		else if (isupper(c_text[i]))
		{
			temp = ((c_text[i] - 'a' + 1) * inverse) % 26;
			if (temp < 0){
				temp += NUM_ALPHA;
			}
			d_text[i] = temp+ 'a' - 1;
		}

		else
		{
			d_text[i] = c_text[i];
		}
	}
	d_text[i] = '\0';

	//Print the Deciphered Text
	printf("Decrypted Text: ");
	fputs(d_text, stdout);




}
//Returns GCD of 2 numbers
int gcd (int num1, int num2)
{
	if (num2 == 0)
		return num1;

	else
	{
		gcd (num2, num1 % num2);
	}
}
