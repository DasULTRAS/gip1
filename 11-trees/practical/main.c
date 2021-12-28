#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "src/modul.h"


int modul_cmp(struct modul first, struct modul second){
    return strcmp(first.abkuerzung, second.abkuerzung);
}

int main(){
    struct modul gip1 = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};


    print_modul(gip1);
}
