#include "array_of_person.h"

unsigned short get_series(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((person*)((char*)arr->element + i * arr->typeinfo->size))->id.series;
}

unsigned short get_number(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((person*)((char*)arr->element + i * arr->typeinfo->size))->id.number;
}

char* get_full_id (array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    char* full_id = (char*)malloc(FULL_ID);
    if (full_id == NULL) {
        if (error != NULL) *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_id, "%hu %hu", ((person*)((char*)arr->element + i * arr->typeinfo->size))->id.series, ((person*)((char*)arr->element + i * arr->typeinfo->size))->id.number);
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return full_id;
}

char* get_first_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((person*)((char*)arr->element + i * arr->typeinfo->size))->first_name;
}

char* get_middle_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((person*)((char*)arr->element + i * arr->typeinfo->size))->middle_name; 
}

char* get_last_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((person*)((char*)arr->element + i * arr->typeinfo->size))->last_name;
}

char* get_full_name (array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    char* full_name = (char*)malloc(FULL_NAME);
    if (full_name == NULL) {
        if (error != NULL) *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_name, "%s %s %s", ((person*)((char*)arr->element + i * arr->typeinfo->size))->first_name, ((person*)((char*)arr->element + i * arr->typeinfo->size))->middle_name, ((person*)((char*)arr->element + i * arr->typeinfo->size))->last_name);
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return full_name;
}

unsigned short get_birth_year(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((person*)((char*)arr->element + i * arr->typeinfo->size))->birth.year;
}

char* get_birth_month(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((person*)((char*)arr->element + i * arr->typeinfo->size))->birth.month;
}

unsigned short get_birth_date(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((person*)((char*)arr->element + i * arr->typeinfo->size))->birth.date;
}

char* get_full_birth (array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    char* full_birth = (char*)malloc(FULL_BIRTH);
    if (full_birth == NULL) {
        if (error != NULL) *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_birth, "%hu %s %hu", ((person*)((char*)arr->element + i * arr->typeinfo->size))->birth.year, ((person*)((char*)arr->element + i * arr->typeinfo->size))->birth.month, ((person*)((char*)arr->element + i * arr->typeinfo->size))->birth.date);
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return full_birth;
}

array* create_array(unsigned int capacity, typeinfo* type_info, array_errors* error) {
    if (type_info == NULL) {
        if (error != NULL) {
            *error = OPERATION_NOT_DEFINED;
        }
        return NULL;
    }
    
    array* array_new = (array*)malloc(sizeof(array));
    if (array_new == NULL) {
        if (error != NULL) {
            *error = MEMORY_ALLOCATION_FAILED;
        }
        return NULL;
    }
    
    array_new->element = malloc(type_info->size * capacity);
    if (array_new->element == NULL && capacity > 0) {
        free(array_new);
        if (error != NULL) {
            *error = MEMORY_ALLOCATION_FAILED;
        }
        return NULL;
    }

    array_new->capacity = capacity;
    array_new->size = 0;
    array_new->typeinfo = type_info;

    if (error != NULL) {
        *error = ARRAY_OPERATION_OK;
    }
    return array_new;
}

void array_add(array* arr, person* p, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return;
    }
    if (p == NULL) {
        if (error != NULL) *error = PERSON_NOT_DEFINED;
        return;
    }

    if (arr->size >= arr->capacity){
        unsigned int new_capacity = (arr->capacity == 0) ? 1 : arr->capacity * 2;
        void* new_element = realloc(arr->element, arr->typeinfo->size * new_capacity);
        if (new_element == NULL) {
            if (error != NULL) *error = MEMORY_ALLOCATION_FAILED;
            return;
        }
        arr->element = new_element;
        arr->capacity = new_capacity;
    }

    memcpy((char*)arr->element + (arr->size * arr->typeinfo->size), p, arr->typeinfo->size);
    arr->size++;
    if (error != NULL) *error = ARRAY_OPERATION_OK;
}

void free_array(array* arr){
    if (arr != NULL) {
        free(arr->element);
        free(arr);
    }
}

char* map_function(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    char* result = (char*)malloc(MAP_CONST);
    if (result == NULL) {
        if (error != NULL) *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(result, "mapped_%s", ((person*)((char*)arr->element + i * arr->typeinfo->size))->first_name);
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return result;
}

char* get_teacher_subject(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((teacher*)((char*)arr->element + i * arr->typeinfo->size))->data.subject;
}

char* get_student_direction(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        if (error != NULL) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        if (error != NULL) *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    
    if (error != NULL) *error = ARRAY_OPERATION_OK;
    return ((student*)((char*)arr->element + i * arr->typeinfo->size))->data.direction;
}



