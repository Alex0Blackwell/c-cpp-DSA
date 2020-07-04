#include <stdio.h>


int main() {
  char string[100];
  printf("Enter a sentence below\n");
  scanf("%[^\n]", string); // accept anything except return

  char res[100];

  int len = 0;
  while (string[len] != '\0') {
    len++;
  }

  int c = 0;
  for (int j = len; j > -1; j--) {
    // Iterate backwards
    res[c] = string[j - 1];
    c++;
  }
  printf("The reverse of \"%s\"\nis: \"%s\".\n", string, res);
}
