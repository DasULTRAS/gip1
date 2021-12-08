#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dynamic_array.h"

struct Dynamic_modul_array construct_dynamic_modules_array(unsigned int size) {
    struct Dynamic_modul_array array = {malloc(sizeof(struct Modul) * size), 0, size};
    return array;
}

void destruct_dynamic_modules_array(struct Dynamic_modul_array *array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->data = 0;
}

void extend_dynamic_modules_array(struct Dynamic_modul_array *array, unsigned int new_capacity) {
    struct Modul *new_data = malloc(sizeof(struct Modul) * new_capacity);
    for (unsigned i = 0; i < new_capacity && i < array->size; ++i) {
        *(new_data + i) = *(array->data + i);
    }
    free(array->data);
    array->data = new_data;
    array->capacity = new_capacity;
}

void push_back_module(struct Dynamic_modul_array *array, struct Modul *modul) {
    if (array->size >= array->capacity) {
        extend_dynamic_modules_array(array, array->size * 2);
    }
    *(array->data + array->size) = *modul;
    ++array->size;
}

bool is_equal(char *str1, char *str2) {
    for (; *str1 != '\0' && *str2 != '\0'; ++str1, ++str2)
        if (*str1 != *str2)
            return false;
    if (*str1 == *str2)
        return true;
    return false;
}

/**
 * Diese Funktion sucht das Modul im Array,
 * dessen Abkürzung identisch zu der in abbreviation angegebenen Abkürzung ist.
 * Dazu iteriert die Funktion über die Arrayelemente und gibt bei einem Treffer den Index des gefundenen Elements zurück.
 * Wird kein passendes Element gefunden, wird der Füllstand des Arrays zurückgegeben.
 * @param array der durchsucht wird
 * @param abbreviation die gesuchte Abkürzung
 * @return der index der gesuchten Abkürung oder wenn nicht gefunden = size
 */
unsigned int find_module_index(struct Dynamic_modul_array *array, char *abbreviation) {
    for (unsigned int i = 0; i < array->size; ++i)
        if (is_equal((array->data + i)->abkuerzung, abbreviation))
            return i;
    return array->size;
}

/**
 * Diese Funktion löscht das Element im Array, das durch index bezeichnet wird.
 * @param array der bearbeitet wird
 * @param index der gelöscht wird
 */
void erase_module(struct Dynamic_modul_array *array, unsigned int index) {
    if (index >= 0 && index < array->size - 1) // Wenn der index nicht der letzte ist
        for (unsigned int i = index + 1; i < array->size; ++i)
            *(array->data + i - 1) = *(array->data + i);
    --array->size;
}

/**
 * Diese Funktion fügt das durch module referenzierte Element vor dem Element ein,
 * das durch index bezeichnet wird.
 * @param array wird bearbeiter
 * @param index des neuen modul
 * @param module das hinzugefügte modul
 */
void insert_module(struct Dynamic_modul_array *array, unsigned int index, struct Modul *module) {
    if (array->size >= array->capacity)
        extend_dynamic_modules_array(array, array->capacity * 2);

    for (int i = array->size; i > index; --i)
        *(array->data + i) = *(array->data + i - 1);
    *(array->data + index) = *module;
    ++array->size;
}

void print_modul(struct Modul modul) {
    printf("%s\nKuerzel : %-5s     Workload: %-5u     Credits : %u\nSemester: %-5u     Dauer   : %u\n", modul.titel,
           modul.abkuerzung, modul.workload, modul.credits, modul.semester, modul.dauer);
}

void print_modul_array(struct Dynamic_modul_array *array) {
    for (int i = 0; i < array->size; ++i)
        print_modul(*(array->data + i));
}