#include "modul.h"

#include <stdio.h>

void print_format(int zeilen) {
  for (int i = 0; i < zeilen; ++i) {
    printf("%d", i);
    for (int j = 0; j < 9; ++j) printf(" ");
  }
  printf("\n");

  for (int i = 0; i < zeilen; ++i) {
    for (int j = 0; j < 10; ++j) printf("%d", j);
  }
  printf("\n");
}

void print_modul(struct modul modul) {
  printf(
      "%s\nKuerzel : %-5s     Workload: %-5u     Credits : %u\nSemester: %-5u  "
      "   Dauer   : %u\n",
      modul.titel, modul.abkuerzung, modul.workload, modul.credits,
      modul.semester, modul.dauer);
}
