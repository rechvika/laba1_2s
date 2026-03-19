#include "concatenation.h"

array* concatenation(array* arr_1, array* arr_2, array_errors* error){
    if (arr_1 == NULL || arr_2 == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (arr_1->typeinfo != arr_2->typeinfo) {
        *error = INCOMPATIBLE_TYPES;
        return NULL;
    }
    
    array_errors temp_error;
    array* arr_new = create_array(arr_1->size + arr_2->size, &temp_error);
    if (temp_error != ARRAY_OPERATION_OK) {
        *error = temp_error;
        return NULL;
    }

    for(unsigned int i = 0; i < arr_1->size; i++){
        person* elem = (person*)((char*)arr_1->element + (i * arr_1->typeinfo->size));
        array_add(arr_new, elem, &temp_error);
        if (temp_error != ARRAY_OPERATION_OK) {
            free_array(arr_new);
            *error = temp_error;
            return NULL;
        }
    }

    for(unsigned int i = 0; i < arr_2->size; i++){
        person* elem = (person*)((char*)arr_2->element + (i * arr_2->typeinfo->size));
        array_add(arr_new, elem, &temp_error);
        if (temp_error != ARRAY_OPERATION_OK) {
            free_array(arr_new);
            *error = temp_error;
            return NULL;
        }
    }
    *error = ARRAY_OPERATION_OK;
    return arr_new;
}