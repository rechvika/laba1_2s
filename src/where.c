#include "where.h"

unsigned short age_verification(person* p) {
    unsigned short age = 2026 - p->birth.year;
    return age >= 18;
}

array* where(array* arr, unsigned short (*function)(person*)){
    array* where_array = create_array(arr->size);

    for(unsigned int i = 0; i < arr->size; i++){
        if(function(arr->element[i])){
            array_add(where_array, arr->element[i]);
        }
    }
    return where_array;
}