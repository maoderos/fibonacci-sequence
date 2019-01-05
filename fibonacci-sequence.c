#include <stdio.h>
#include <math.h>

int main() {
  // Ask the user the number of terms in the sequence
  float terms;
  printf("Fibonacci's numbers program\n Choose the number of terms of the sequence: ");
  scanf("%f",&terms);

  // boolean to make sure that the user has chosen an integer
  if (terms > 0) {
    if ((terms - (int)terms) == 0) {
      //Fibonacci's sequence
      FILE *file = fopen("data.txt", "w");
      unsigned long long int sequence[(int)terms];
      int i;
      for (i = 0; i < (int)terms; i++) {
        if (i == 0) {
          sequence[i] = 0;
          fprintf(file, "%llu ", sequence[i]);
        } else if (i == 1) {
          sequence[i] = 1;
          fprintf(file, "%llu ", sequence[i]);
        } else {
          unsigned long long int num1 = sequence[(i - 1)];
          unsigned long long int num2 = sequence[(i - 2)];
          unsigned long long int result = num1 + num2;
          sequence[i] = result;
          fprintf(file, "%lli ", sequence[i]);
        }
      }
      fclose(file);
      // 'for' to print the sequence on the screen
      for (i = 0; i < (int)terms; i++) {
        printf("%llu, ", sequence[i]);
      }

    } else {
      printf("Please, choose a naturnal number\n");
    }
  } else {
    printf("choose a positive number\n");
  }

  return 0;
}
