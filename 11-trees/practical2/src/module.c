#include "module.h"

#include <stdio.h>

void print_format(int lines) {
  for (int i = 0; i < lines; ++i) {
    printf("%d", i);
    for (int j = 0; j < 9; ++j) printf(" ");
  }
  printf("\n");

  for (int i = 0; i < lines; ++i) {
    for (int j = 0; j < 10; ++j) printf("%d", j);
  }
  printf("\n");
}

void print_module(struct module module) {
  printf(
      "%s\n"
      "abbreviation : %-5s     workload : %-5u     credits : %u\n"
      "semester     : %-5u     duration : %u\n",
      module.title, module.abbreviation, module.workload, module.credits,
      module.semester, module.duration);
}
