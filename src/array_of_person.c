#include "array_of_person.h"

unsigned short get_series(person* p){
    return p->id.series;
}

unsigned short get_number(person* p){
    return p->id.number;
}

char* get_full_id (person* p){
    char* full_id = (char*)malloc(FULL_ID);// сделать побольше макровсвм

    sprintf(full_id, "%hu %hu", p->id.series, p->id.number);

    return full_id;
}



char* get_first_name(person* p){
    return p->first_name;
}

char* get_middle_name(person* p){
    return p->middle_name;
}

char* get_last_name(person* p){
    return p->last_name;
}

char* get_full_name (person* p){
    char* full_name = (char*)malloc(FULL_NAME);

    sprintf(full_name, "%s %s %s", p->first_name, p->middle_name, p->last_name);

    return full_name;
}

unsigned short get_birth_year(person* p){
    return p->birth.year;
}

char* get_birth_month(person* p){
    return p->birth.month;
}

unsigned short get_birth_date(person* p){
    return p->birth.date;
}

char* get_full_birth (person* p){
    char* full_birth = (char*)malloc(FULL_BIRTH);

    sprintf(full_birth, "%hu %s %hu", p->birth.year, p->birth.month, p->birth.date);

    return full_birth;
}



array* create_array(unsigned int capacity, typeinfo* type_info){
    array* array_new = (array*)malloc(sizeof(array));

    array_new->capacity = capacity;
    array_new->size = 0;
    array_new->element = (person*)malloc(type_info->size * array_new->capacity);

    return array_new;
}

void array_add(array* arr, person* p){
    if (arr->size >= arr->capacity){
        arr->capacity *= 2; // учитывать размер (если например персона состоит только из id и фамилии)
        arr->element = (person*)realloc(arr->element, arr->typeinfo->size * arr->capacity); //не ** а *, одна персона четко лежит за другой
    }
    memcpy((char*)arr->element +(arr->size * arr->typeinfo->size), p, arr->typeinfo->size);
    arr->size++;
}

void free_array(array* arr){
    free(arr->element);
    free(arr);
}



char* map_function(person* p){
    char* result = (char*)malloc(MAP_CONST);
    sprintf(result, "mapped_%s", p->first_name);
    return result;
}


