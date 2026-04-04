#include "operation.h"

array* concatenation(array* arr_1, array* arr_2, array_errors* error){
    if (arr_1 == NULL || arr_2 == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    if (strcmp(arr_1->typeinfo->type_name, arr_2->typeinfo->type_name) != 0) {
        *error = INCOMPATIBLE_TYPES;
        return NULL;
    }
    
    array_errors temp_error;
    array* arr_new = create_array(arr_1->size + arr_2->size, arr_1->typeinfo, &temp_error);
    if (temp_error != ARRAY_OPERATION_OK) {
        *error = temp_error;
        return NULL;
    }

    memcpy(arr_new->element, arr_1->element, arr_1->size * arr_1->typeinfo->size);
    arr_new->size += arr_1->size;

    memcpy((char*)arr_new->element + (arr_1->size * arr_1->typeinfo->size), arr_2->element, arr_2->size * arr_2->typeinfo->size);
    arr_new->size += arr_2->size;
    
    *error = ARRAY_OPERATION_OK;
    return arr_new;
}