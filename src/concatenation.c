#include "concatenation.h"

array* concatenation(array* arr_1, array* arr_2){
    array* arr_new = create_array(arr_1->size + arr_2->size);

    for(unsigned int i = 0; i < arr_1->size; i++){
        array_add(arr_new, arr_1->element[i]);
    }

    for(unsigned int i = 0; i < arr_2->size; i++){
        array_add(arr_new, arr_2->element[i]);
    }

    return arr_new;
}