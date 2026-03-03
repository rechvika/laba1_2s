#include "where.h"

array* create_array(){
    array* arrary_new = (array*)malloc(sizeof(array));

    array_new->capacity = array->capacity;
    array_new->size = 0;
    array_new->element = (person**)malloc(sizeof(person*) * array_new->capacity);

    return array_new;
}

void array_add(array* array, person* person){
    if (array->size >= array->capacity){
        array *= 2;
        array->element = (person**)realloc(array->element, sizeof(person*) * array->capacity);
    }
    array->size++;
    array->element[array->size] = person;
}

unsigned short age_verification(person* person) {
    unsigned short age = 2026 - person->birth.year[0];
    return age >= 18;
}

array* where(array* array, unsigned short (*function)(person*)){
    array* where_array = create_array();

    for(unsigned int i = 0; i < array->size; i++){
        if(function(array->element[i])){
            array_add(where_array, array->element[i]);
        }
    }
    return where_array;
}