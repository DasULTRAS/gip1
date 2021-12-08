#include <stdio.h>

#include "dynamic_array/dynamic_array.h."


int main() {
    // struct Modul gip1 = {"Grundlagen der Informatik und Programmierung 1", "GIP1", 210, 7, 1, 1};

    struct Dynamic_modul_array modules = construct_dynamic_modules_array(2);

    while (1) {
        struct Modul temp;
        int input = scanf("%64[^,],%6[^,],%u,%u,%u,%u ", temp.titel, temp.abkuerzung, &temp.workload, &temp.credits,
                          &temp.semester, &temp.dauer);
        if (input == EOF)
            break;

        insert_module(&modules, modules.size, &temp);
    }

    printf("Capacity: %d/%d\n", modules.size, modules.capacity);
    print_modul_array(&modules);

    char gip2[] = "GIP2";
    printf("%s liegt im index: %u:10\n", gip2, find_module_index(&modules, gip2));

    char alg[] = "ALG";
    printf("Erstes Modul (%s) gelöscht\n", alg);
    erase_module(&modules, find_module_index(&modules, alg));

    char te[] = "TE";
    printf("Letztes Modul (%s) gelöscht\n", te);
    erase_module(&modules, find_module_index(&modules, te));

    struct Modul mid = {"The Middle", "MID", 187, 100, 0, 1};
    insert_module(&modules, 0, &mid);

    print_modul_array(&modules);

    destruct_dynamic_modules_array(&modules);
}