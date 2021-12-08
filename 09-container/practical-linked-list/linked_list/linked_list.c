#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

void print_modul(struct Modul modul) {
    printf("%s\nKuerzel : %-5s     Workload: %-5u     Credits : %u\nSemester: %-5u     Dauer   : %u\n", modul.titel,
           modul.abkuerzung, modul.workload, modul.credits, modul.semester, modul.dauer);
}