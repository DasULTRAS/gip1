#include <stdio.h>

#include "linked_list/linked_list.h"

int main(){
    // scanf("%64[^,],%6[^,],%u,%u,%u,%u ", temp.titel, temp.abkuerzung, &temp.workload, &temp.credits,
    // &temp.semester, &temp.dauer);
    struct Modul gip1 = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};

    struct Linked_modules_list_element *gip1_e = construct_linked_modules_list_element(&gip1);

    print_modul(&gip1_e->data);

    destruct_linked_modules_list_element(&gip1_e);
}