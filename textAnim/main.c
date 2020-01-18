#include <stdio.h>

#include <string.h>

#include <unistd.h>


char upperCaseAnim(char string[], int repeat, float speed) {
  char res[20]; // Strings of 20 in length
  strcpy(res, string);

  // Get string length
  int len = 0;
  while (res[len] != '\0') {
    len++;
  }

  for (int j = 0; j < repeat; j++) {
    // First show message normally
    printf("\r%s", string);
    fflush(stdout);

    char temp[20];
    for (int i = 0; i < len; i++) {
      int a;
      for (a = 0; a < i; a++) {
        // First part of string normal
        res[a] = string[a];
      }
      if (string[a] > 96 && string[a] < 123) {
        // If the address points to a lowercase character
        res[a] = string[a] - 32; // Lower case at [i] change to upper
      }
      for (int b = a + 1; b < len; b++) {
        // Second part of string normal
        res[b] = string[b];
      }

      if (string[a] != 32) {
        // Skip over spaces
        usleep(speed * 1000000); // Wait half a second
        printf("\r%s", res);
        fflush(stdout);
      }
    }
    usleep(speed * 1000000);
    printf("\r%s", string);
  }
  printf("\n");

}

int main() {
  char usrIn[20];
  printf("Enter a sentence: ");
  scanf("%[^\n]", usrIn);
  upperCaseAnim(usrIn, 2, 0.2);
}
