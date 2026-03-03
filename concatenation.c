#include "concatenation.h"

array* concatenation(array* array_1, array* array_2){
    array array_new = create_array();

    for(unsigned int i = 0; i <= array_1->size; i++){
        array_add(array_new, array_1->element[i]);
    }

    for(unsigned int i = 0; i <= array_2->size; i++){
        array_add(array_new, array_2->element[i]);
    }

    return array_new;
}