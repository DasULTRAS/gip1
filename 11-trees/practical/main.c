#include <stdlib.h>
#include <stdio.h>

#include "src/modul.h"

int main(){
    struct modul gip1 = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};

    print_modul(gip1);
}
