#include "array_of_person.h"

unsigned short get_series(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return p->id.series;
}

unsigned short get_number(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return p->id.number;
}

char* get_full_id (person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return NULL;
    }
    char* full_id = (char*)malloc(FULL_ID);// сделать побольше макровсвм
    if (full_id == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_id, "%hu %hu", p->id.series, p->id.number);
    *error = ARRAY_OPERATION_OK;
    return full_id;
}



char* get_first_name(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return NULL;
    }
    *error = ARRAY_OPERATION_OK;
    return p->first_name;
}

char* get_middle_name(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return NULL;
    }
    *error = ARRAY_OPERATION_OK;
    return p->middle_name;
}

char* get_last_name(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return NULL;
    }
    *error = ARRAY_OPERATION_OK;
    return p->last_name;
}

char* get_full_name (person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return NULL;
    }
    char* full_name = (char*)malloc(FULL_NAME);
    if (full_name == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_name, "%s %s %s", p->first_name, p->middle_name, p->last_name);
    *error = ARRAY_OPERATION_OK;
    return full_name;
}

unsigned short get_birth_year(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return p->birth.year;
}

char* get_birth_month(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return NULL;
    }
    *error = ARRAY_OPERATION_OK;
    return p->birth.month;
}

unsigned short get_birth_date(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return p->birth.date;
}

char* get_full_birth (person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return NULL;
    }
    char* full_birth = (char*)malloc(FULL_BIRTH);
    if (full_birth == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_birth, "%hu %s %hu", p->birth.year, p->birth.month, p->birth.date);
    *error = ARRAY_OPERATION_OK;
    return full_birth;
}



array* create_array(unsigned int capacity, typeinfo* type_info, array_errors* error){
    if (type_info == NULL) {
        *error = OPERATION_NOT_DEFINED;
        return NULL;
    }
    array* array_new = (array*)malloc(sizeof(array));
    if (array_new == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    array_new->element = (person*)malloc(type_info->size * array_new->capacity);
    if (array_new->element == NULL && capacity > 0) {
        free(array_new);
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }


    array_new->capacity = capacity;
    array_new->size = 0;
    array_new->typeinfo = type_info;

    *error = ARRAY_OPERATION_OK;
    return array_new;
}

void array_add(array* arr, person* p, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return;
    }
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return;
    }

    if (arr->size >= arr->capacity){
        unsigned int new_capacity = (arr->capacity == 0) ? 1 : arr->capacity * 2;
        person* new_element = (person*)realloc(arr->element, arr->typeinfo->size * new_capacity);
        if (new_element == NULL) {
            *error = MEMORY_ALLOCATION_FAILED;
            return;
        }
        arr->element = new_element;
        arr->capacity = new_capacity;
    }

    memcpy((char*)arr->element +(arr->size * arr->typeinfo->size), p, arr->typeinfo->size);
    arr->size++;
    *error = ARRAY_OPERATION_OK;
}

void free_array(array* arr){
    if (arr != NULL) {
        free(arr->element);
        free(arr);
    }
}



char* map_function(person* p, array_errors* error){
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return NULL;
    }
    char* result = (char*)malloc(MAP_CONST);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    sprintf(result, "mapped_%s", p->first_name);
    *error = ARRAY_OPERATION_OK;
    return result;
}


//это для математических функций
//винда