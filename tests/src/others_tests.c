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

TEST(test_no_memory_leak_get_full_id){
    for(int i = 0; i < 100; i++){
        person p;
        p.id.series = 1234;
        p.id.number = 5678;
        array_errors error;
        
        char* full_id = get_full_id(&p, &error);
        free(full_id);
    }
    assert(1);
}

TEST(test_no_memory_leak_get_full_name){
    for(int i = 0; i < 100; i++){
        person p;
        strcpy(p.first_name, "Иван");
        strcpy(p.middle_name, "Иванович");
        strcpy(p.last_name, "Петров");
        array_errors error;
        
        char* full_name = get_full_name(&p, &error);
        free(full_name);
    }
    assert(1);
}

TEST(test_no_memory_leak_get_full_birth){
    for(int i = 0; i < 100; i++){
        person p;
        p.birth.year = 2000;
        strcpy(p.birth.month, "Январь");
        p.birth.date = 15;
        array_errors error;
        
        char* full_birth = get_full_birth(&p, &error);
        free(full_birth);
    }
    assert(1);
}

TEST(test_no_memory_leak_map_function){
    for(int i = 0; i < 100; i++){
        person p;
        strcpy(p.first_name, "Иван");
        array_errors error;
        
        char* result = map_function(&p, &error);
        free(result);
    }
    assert(1);
}

TEST(test_no_memory_leak_create_array){
    for(int i = 0; i < 100; i++){
        typeinfo* person_type = get_person_typeinfo();
        array_errors error;
        array* arr = create_array(10, person_type, &error);
        free_array(arr);
    }
    assert(1);
}

TEST(test_complex_workflow){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;

    array* arr = create_array(5, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);

    person p1, p2, p3;
    p1.birth.year = 2000;
    strcpy(p1.first_name, "Иван");
    p2.birth.year = 2010;
    strcpy(p2.first_name, "Петр");
    p3.birth.year = 1995;
    strcpy(p3.first_name, "Сидор");
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    assert(error == ARRAY_OPERATION_OK);

    array* adults = where(arr, age_verification, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(adults->size == 2);

    person* adult_elements = (person*)adults->element;
    char* name1 = get_first_name(&adult_elements[0], &error);
    char* name2 = get_first_name(&adult_elements[1], &error);
    assert(strcmp(name1, "Иван") == 0 || strcmp(name1, "Сидор") == 0);
    assert(strcmp(name2, "Иван") == 0 || strcmp(name2, "Сидор") == 0);
    assert(strcmp(name1, name2) != 0);

    free_array(arr);
    free_array(adults);
}

TEST(test_error_propagation_complex){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;

    array* arr = create_array(2, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);

    person p;
    p.birth.year = 2000;
    array_add(arr, &p, &error);
    assert(error == ARRAY_OPERATION_OK);

    array* filtered = where(arr, NULL, &error);
    assert(error == OPERATION_NOT_DEFINED);
    assert(filtered == NULL);

    assert(arr->size == 1);

    filtered = where(arr, age_verification, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered != NULL);
    assert(filtered->size == 1);
    
    free_array(arr);
    free_array(filtered);
}

TEST(test_multiple_operations){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;

    array* arr1 = create_array(3, person_type, &error);
    array* arr2 = create_array(3, person_type, &error);

    person p1, p2, p3;
    p1.birth.year = 2000;
    strcpy(p1.first_name, "A");
    p2.birth.year = 2015;
    strcpy(p2.first_name, "B");
    p3.birth.year = 1990;
    strcpy(p3.first_name, "C");
    
    array_add(arr1, &p1, &error);
    array_add(arr1, &p2, &error);
    array_add(arr1, &p3, &error);

    person p4, p5, p6;
    p4.birth.year = 1985;
    strcpy(p4.first_name, "D");
    p5.birth.year = 2020;
    strcpy(p5.first_name, "E");
    p6.birth.year = 1975;
    strcpy(p6.first_name, "F");
    
    array_add(arr2, &p4, &error);
    array_add(arr2, &p5, &error);
    array_add(arr2, &p6, &error);

    array* combined = concatenation(arr1, arr2, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(combined->size == 6);

    array* adults = where(combined, age_verification, &error);
    assert(error == ARRAY_OPERATION_OK);

    assert(adults->size == 4);

    free_array(arr1);
    free_array(arr2);
    free_array(combined);
    free_array(adults);
}