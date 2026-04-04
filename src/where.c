#include "operation.h"

unsigned short age_verification(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    unsigned short age = 2026 - ((person*)((char*)arr->element + i * arr->typeinfo->size))->birth.year;
    *error = ARRAY_OPERATION_OK;
    return age >= 18;
}

array* where(array* arr, unsigned short (*function)(array*, unsigned int, array_errors*), array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (function == NULL) {
        *error = OPERATION_NOT_DEFINED;
        return NULL;
    }

    array_errors temp_error;
    array* where_array = create_array(arr->size, arr->typeinfo, &temp_error);
    if (temp_error != ARRAY_OPERATION_OK) {
        *error = temp_error;
        return NULL;
    }

    for(unsigned int i = 0; i < arr->size; i++){
        unsigned short condition = function(arr, i, &temp_error);
        if (temp_error != ARRAY_OPERATION_OK) {
            free_array(where_array);
            *error = temp_error;
            return NULL;
        }

        if(condition){
            array_add(where_array, (person*)((char*)arr->element + (i * arr->typeinfo->size)), &temp_error);
            if (temp_error != ARRAY_OPERATION_OK) {
                free_array(where_array);
                *error = temp_error;
                return NULL;
            }
        }
    }
    *error = ARRAY_OPERATION_OK;
    return where_array;
}