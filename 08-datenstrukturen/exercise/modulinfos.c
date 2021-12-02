#include <stdio.h>
#include <stdlib.h>

struct modul {
  char titel[64];
  char abkuerzung[5];
  unsigned int workload, credits, semester, dauer;
};

void print_format(int zeilen){
  for(int i = 0;  i < zeilen; ++i){
    printf("%d", i);
    for(int j = 0; j < 9; ++j)
      printf(" ");
  }
  printf("\n");

  for(int i = 0;  i < zeilen; ++i){
    for(int j = 0; j < 10; ++j)
      printf("%d", j);
  }
  printf("\n");
}

void print_modul(struct modul modul){
  printf("%s\nKuerzel : %-5s     Workload: %-5u     Credits : %u\nSemester: %-5u     Dauer   : %u\n", modul.titel, modul.abkuerzung, modul.workload, modul.credits, modul.semester, modul.dauer);
}

int main(){
  struct modul modulinfos = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};

  struct modul *module = calloc(64, sizeof(struct modul));

  print_format(6);
  print_modul(modulinfos);

  int input;
  struct modul *temp = module;
  while (1) {
    input = scanf("%64[^,],%6[^,],%u,%u,%u,%u ", (*temp).titel, (*temp).abkuerzung, &(*temp).workload, &(*temp).credits, &(*temp).semester, &(*temp).dauer);
    if(input == EOF)
      break;
    print_modul(*temp);
    ++temp;
    if(temp == module+63)
      break;
  }

  free(module);

  return 0;
}
