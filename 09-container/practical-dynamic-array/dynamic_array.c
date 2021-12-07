#include <stdio.h>

struct modul {
    char titel[64];
    char abkuerzung[5];
    unsigned int workload, credits, semester, dauer;
};

void print_modul(struct modul modul){
    printf("%s\nKuerzel : %-5s     Workload: %-5u     Credits : %u\nSemester: %-5u     Dauer   : %u\n", modul.titel, modul.abkuerzung, modul.workload, modul.credits, modul.semester, modul.dauer);
}

int main(){
    struct modul modulinfos = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};

    printf("Hello World");
}