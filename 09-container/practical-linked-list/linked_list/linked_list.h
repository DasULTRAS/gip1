#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct Modul{
    char titel[64];
    char abkuerzung[5];
    unsigned int workload, credits, semester, dauer;
};

struct Linked_modules_list_element{
    struct Modul data;
    struct Linked_modules_list_element *next, *previous;
};

struct Linked_modules_list{
    struct Linked_modules_list_element *first, *last;
};

void print_modul(struct Modul *modul);

struct Linked_modules_list_element* construct_linked_modules_list_element(struct Modul *modul);
void destruct_linked_modules_list_element(struct Linked_modules_list_element* element);

#endif // _LINKED_LIST_H_