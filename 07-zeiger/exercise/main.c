#include <stdio.h>
#include <stdlib.h>
#include "my_string/my_string.h"

int main(){
  while (1) {
    int length = 100;
    char* c = calloc(length +1, sizeof(int));
    char* cpy = calloc(length +1, sizeof(int));
    char input = scanf("%100s", c);

    if(input == EOF)
      break;

    my_strcpy_std(c, cpy);
    printf("my_strcpy_std: %s\n", cpy);

    my_strtolower_std(c, cpy);
    printf("my_strtolower_std: %s\n", cpy);

    my_strtoupper_std(c, cpy);
    printf("my_strtoupper_std: %s\n", cpy);

    printf("my_strlen: %u\n", my_strlen(c));

    // Speicher freigeben
    free(cpy);
    free(c);
  }

  return 0;
}
