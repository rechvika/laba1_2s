#include "where.h"

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