#include <stdio.h>
#include <string.h>

//Size of the Key Matrix
#define SIZE 5

void insert_bogus_char(char str[]);
void insert (char str[], int index);
void search(char key_matrix[][SIZE], char c, int *row1, int *col1);

int main(void)
{
  char key_matrix[SIZE][SIZE] = {{'l', 'g', 'd', 'b', 'a'},
                                  {'q', 'm', 'h', 'e', 'c'},
                                  {'u', 'r', 'n', 'i', 'f'},
                                  {'x', 'v', 's', 'o', 'k'},
                                  {'z', 'y', 'w', 't', 'p'}};

  char p_text[40];

  //Prompt for Plaintext
  printf("Plaintext(max.20 chars)\n");
  scanf("%[^\n]%*c", p_text);

  if (strlen(p_text) > 20){
    printf("Size of P_text Exceeded!\n");
    return 1;
  }

  //Insert Bogus Chars. Wherever Reqd.
  insert_bogus_char(p_text);

  printf("Updated Plaintext : %s\n", p_text);

  int row1, row2, col1, col2;
  //Encryption Time
  char c_text[40];
  //Iterating over the P_text 2 chars at a time
  for (int i = 0, n = strlen(p_text); i < n - 1; i += 2){
      search(key_matrix, p_text[i], &row1, &col1);
      search(key_matrix, p_text[i + 1], &row2, &col2);

      //if the chars were in the same row
      if (row1 == row2){
        c_text[i] = key_matrix[row1][(++col1 % SIZE)];
        c_text[i + 1] = key_matrix[row2][(++col2 % SIZE)];
      }
      //if the chars are in the same column
      else if (col1 == col2){
        c_text[i] = key_matrix[(++row1) % SIZE][col1];
        c_text[i + 1] = key_matrix[(++row2) % SIZE][col2];
      }
      else{
        c_text[i] = key_matrix[row1][col2];
        c_text[i + 1] = key_matrix[row2][col1];
      }
  }
  c_text[strlen(p_text)] = '\0';
  //Print Cipher-Text
  printf("Ciphertext : %s\n", c_text);
}

void insert_bogus_char(char str[]){
  for (int i = 0; i < strlen(str) - 1; i++){
    //Inserting Bogus Char. when 2 adjacent chars are same
    if (str[i] == str[i + 1]){
      //Insert a bogus character
      insert(str, i + 1);
    }
  }
  //if length of plaintext is odd , add a bogus char at end
  if (strlen(str) % 2 == 1){
    int n = strlen(str);
    str[n + 1] = '\0';
    str[n] = 'x';
  }
}

void insert (char str[], int index){
  for (int i = strlen(str); i >= index; i--){
    str[i + 1] = str[i];
  }
  str[index] = 'x';
}

void search(char key_matrix[][SIZE], char c, int *row1, int *col1){
  char to_search = c;
  if (to_search == 'j'){
    to_search = 'i';
  }
  for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
      if (key_matrix[i][j] == to_search){
        *row1 = i;
        *col1 = j;
        return;
      }
    } } }
