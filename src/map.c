#include "operation.h"

array* map(array* arr, char* (*function)(array*, unsigned int, array_errors*), array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (function == NULL) {
        *error = OPERATION_NOT_DEFINED;
        return NULL;
    }

    array_errors temp_error;
    typeinfo* string_typeinfo = (typeinfo*)malloc(sizeof(typeinfo));
    if (string_typeinfo == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    string_typeinfo->size = sizeof(char*);
    string_typeinfo->type_name = "string";

    array* map_array = create_array(arr->size, string_typeinfo, &temp_error);
    if (temp_error != ARRAY_OPERATION_OK) {
        free(string_typeinfo);
        *error = temp_error;
        return NULL;
    }
    
    for(unsigned int i = 0; i < arr->size; i++){
        char* result = function(arr, i, &temp_error);
        
        if (temp_error != ARRAY_OPERATION_OK) {
            free_array(map_array);
            free(string_typeinfo);
            *error = temp_error;
            return NULL;
        }
        
        char** str_storage = (char**)malloc(sizeof(char*));
        if (str_storage == NULL) {
            free(result);
            free_array(map_array);
            free(string_typeinfo);
            *error = MEMORY_ALLOCATION_FAILED;
            return NULL;
        }
        
        *str_storage = result;
        array_add(map_array, (person*)str_storage, &temp_error);
        
        if (temp_error != ARRAY_OPERATION_OK) {
            free(result);
            free(str_storage);
            free_array(map_array);
            free(string_typeinfo);
            *error = temp_error;
            return NULL;
        }
    }

    *error = ARRAY_OPERATION_OK;
    return map_array;
}

