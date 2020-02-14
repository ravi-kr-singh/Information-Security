#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_ALPHA 26

int gcd (int num1, int num2);

int main(void)
{
	char p_text[20], c_text[20], d_text[20];
	int mult_key, add_key;


	//Get the Plaintext
	printf("Plaintext: ");
	fgets(p_text, 20, stdin);

	//Get the 2 Keys
	printf("Multiplicative Key:");
	scanf("%i", &mult_key);

  printf("Additive Key:");
  scanf("%i", &add_key);

	//Check if key is valid
	if (gcd(mult_key, NUM_ALPHA) != 1)
	{
		printf("Multiplicative Key Invalid\n");
		return 1;
	}


	//Creating the ciphertext
	int i, n;
	//Iterate over the plaintext
	for (i = 0, n = strlen(p_text); i < n; i++)
	{
		//Where Encryption Takes Place
		if (islower(p_text[i]))
		{
			c_text[i] = ((p_text[i] - 'a' ) * mult_key + add_key) % 26 + 'a' ;
		}

		else if (isupper(p_text[i]))
		{
			c_text[i] = ((p_text[i] - 'A') * mult_key + add_key) % 26 + 'A';
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
	int inverse_key = 0;
	do
	{
		inverse_key++;

	} while((mult_key * inverse_key) % 26 != 1);

	printf("Inverse of the Key : %d\n", inverse_key);

	char temp;

	//Decrypt the text
	for (i = 0, n = strlen(c_text); i < n; i++)
	{
		if (islower(c_text[i]))
		{
			temp = (((c_text[i] - 'a') - add_key) * inverse_key) % 26;
			if (temp < 0){
				temp += 26;
			}
			d_text[i] = temp  + 'a';
		}

		else if (isupper(c_text[i]))
		{
			char temp = (((c_text[i] - 'A') - add_key) * inverse_key) % 26;
		  if (temp < 0){
				temp += 26;
			}
			d_text[i] = temp + 'A';
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
