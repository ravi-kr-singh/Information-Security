#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char p_text[20], c_text[20];
	int key;

	//Prompt for Plaintext
	printf("Plaintext: ");
	fgets(p_text, 20, stdin);

	//Prompt for key
	printf("Key:");
	scanf("%i", &key);
	int i, n;

	//Iterate over the Plaintext
	for (i = 0, n = strlen(p_text); i < n; i++)
	{
		//encrypting lowercase chars.
		if (islower(p_text[i]))
		{
			c_text[i] = (p_text[i] - 'a' + key) % 26 + 'a';
		}

		//encrypting uppercase chars.
		else if (isupper(p_text[i]))
		{
			c_text[i] = (p_text[i] - 'A' + key) % 26 + 'A';
		}

		else
		{
			c_text[i] = p_text[i];
		}
	}
	c_text[i] = '\0';

	//print Cipher Text
	printf("Cipher Text : ");
	fputs(c_text, stdout);

	char temp;

	//Decrypting the Ciphertext
	for (i = 0, n = strlen(c_text); i < n; i++)
	{
		if (islower(c_text[i]))
		{
			temp = (c_text[i] - 'a' - key) % 26;
			if (temp < 0){
				temp += 26;
			}
			c_text[i] = temp + 'a';
		}

		else if (isupper(p_text[i]))
		{
			temp = (c_text[i] - 'A' - key) % 26;
			if (temp < 0){
				temp += 26;
			}
			c_text[i] = temp + 'A';
		}

	}

	printf("Decryption: ");
printf("Cipher Text : ");
	fputs(c_text, stdout);

}
