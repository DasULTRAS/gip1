#include <stdio.h>

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
  printf("%s\nKürzel  : %-5s     Workload: %-5u     Credits : %u\nSemester: %-5u     Dauer   : %u\n", modul.titel, modul.abkuerzung, modul.workload, modul.credits, modul.semester, modul.dauer);
}

int main(){
  struct modul modulinfos = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};

  print_format(6);
  print_modul(modulinfos);

  return 0;
}
