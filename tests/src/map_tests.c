#include "assertions.h"
#include "testing.h"
#include "array_of_person.h"
#include "where.h"
#include "map.h"
#include "concatenation.h"
#include "test_person.h"
#include "typeinfo.h"
#include "person_typeinfo.h"
#include "array_errors.h"

TEST(test_map_single_element){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(1, person_type, &error);
    
    person p;
    strcpy(p.first_name, "Иван");
    array_add(arr, &p, &error);
    
    array* mapped = map(arr, map_function, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(mapped != NULL);
    assert(mapped->size == 1);
    
    free_array(arr);
    free_array(mapped);
}

TEST(test_map_null_array){
    array_errors error;
    
    array* mapped = map(NULL, map_function, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(mapped == NULL);
}

TEST(test_map_null_function){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, person_type, &error);
    
    array* mapped = map(arr, NULL, &error);
    
    assert(error == OPERATION_NOT_DEFINED);
    assert(mapped == NULL);
    
    free_array(arr);
}

TEST(test_map_both_null){
    array_errors error;
    
    array* mapped = map(NULL, NULL, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(mapped == NULL);
}

TEST(test_map_empty_array){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, person_type, &error);
    
    array* mapped = map(arr, map_function, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(mapped != NULL);
    assert(mapped->size == 0);
    
    free_array(arr);
    free_array(mapped);
}

TEST(test_map_function_normal){
    person p;
    strcpy(p.first_name, "Иван");
    array_errors error;
    
    char* result = map_function(&p, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "mapped_Иван") == 0);
    
    free(result);
}

TEST(test_map_function_empty_name){
    person p;
    strcpy(p.first_name, "");
    array_errors error;
    
    char* result = map_function(&p, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "mapped_") == 0);
    
    free(result);
}

TEST(test_map_function_long_name){
    person p;
    char long_name[MAX_LINE_NAME];
    memset(long_name, 'A', MAX_LINE_NAME - 2);
    long_name[MAX_LINE_NAME - 2] = '\0';
    strcpy(p.first_name, long_name);
    array_errors error;
    
    char* result = map_function(&p, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    
    char expected[MAP_CONST];
    sprintf(expected, "mapped_%s", long_name);
    assert(strcmp(result, expected) == 0);
    
    free(result);
}

TEST(test_map_function_special_chars){
    person p;
    strcpy(p.first_name, "Анна-Мария");
    array_errors error;
    
    char* result = map_function(&p, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "mapped_Анна-Мария") == 0);
    
    free(result);
}

TEST(test_map_function_null_pointer){
    array_errors error;
    
    char* result = map_function(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_map_function_memory_allocation){
    person p;
    strcpy(p.first_name, "Иван");
    array_errors error;
    
    char* result = map_function(&p, &error);
    
    assert(result != NULL);
    assert(error == ARRAY_OPERATION_OK);
    
    free(result);
}

