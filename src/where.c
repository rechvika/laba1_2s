#include "where.h"

unsigned short age_verification(person* p) {
    unsigned short age = 2026 - p->birth.year;
    return age >= 18;
}

array* where(array* arr, unsigned short (*function)(person*)){
    array* where_array = create_array(arr->size, arr->typeinfo);

    for(unsigned int i = 0; i < arr->size; i++){
        void* elem = (char*)arr->element +(i * arr->typeinfo->size);
        if(function(elem)){
            array_add(where_array, elem);
        }
    }
    return where_array;
}