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

TEST(test_concatenation_both_non_empty){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, person_type, &error);
    array* arr2 = create_array(2, person_type, &error);
    
    person p1, p2, p3, p4;
    p1.id.series = 1;
    p2.id.series = 2;
    p3.id.series = 3;
    p4.id.series = 4;
    
    array_add(arr1, &p1, &error);
    array_add(arr1, &p2, &error);
    array_add(arr2, &p3, &error);
    array_add(arr2, &p4, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(result->size == 4);
    assert(result->capacity >= 4);
    
    person* elements = (person*)result->element;
    assert(elements[0].id.series == 1);
    assert(elements[1].id.series == 2);
    assert(elements[2].id.series == 3);
    assert(elements[3].id.series == 4);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
}

TEST(test_concatenation_first_empty){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, person_type, &error);
    array* arr2 = create_array(2, person_type, &error);
    
    person p3, p4;
    p3.id.series = 3;
    p4.id.series = 4;
    
    array_add(arr2, &p3, &error);
    array_add(arr2, &p4, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(result->size == 2);
    
    person* elements = (person*)result->element;
    assert(elements[0].id.series == 3);
    assert(elements[1].id.series == 4);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
}

TEST(test_concatenation_second_empty){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, person_type, &error);
    array* arr2 = create_array(2, person_type, &error);
    
    person p1, p2;
    p1.id.series = 1;
    p2.id.series = 2;
    
    array_add(arr1, &p1, &error);
    array_add(arr1, &p2, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(result->size == 2);
    
    person* elements = (person*)result->element;
    assert(elements[0].id.series == 1);
    assert(elements[1].id.series == 2);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
}

TEST(test_concatenation_both_empty){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, person_type, &error);
    array* arr2 = create_array(2, person_type, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(result->size == 0);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
}

TEST(test_concatenation_large_arrays){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(50, person_type, &error);
    array* arr2 = create_array(50, person_type, &error);
    
    person p;
    for(int i = 0; i < 50; i++){
        p.id.series = i;
        array_add(arr1, &p, &error);
    }
    for(int i = 50; i < 100; i++){
        p.id.series = i;
        array_add(arr2, &p, &error);
    }
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result->size == 100);
    
    person* elements = (person*)result->element;
    for(int i = 0; i < 100; i++){
        assert(elements[i].id.series == i);
    }
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
}

TEST(test_concatenation_preserve_order){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(3, person_type, &error);
    array* arr2 = create_array(3, person_type, &error);
    
    person p1, p2, p3, p4, p5, p6;
    p1.id.series = 1;
    p2.id.series = 2;
    p3.id.series = 3;
    p4.id.series = 4;
    p5.id.series = 5;
    p6.id.series = 6;
    
    array_add(arr1, &p1, &error);
    array_add(arr1, &p2, &error);
    array_add(arr1, &p3, &error);
    array_add(arr2, &p4, &error);
    array_add(arr2, &p5, &error);
    array_add(arr2, &p6, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result->size == 6);
    
    person* elements = (person*)result->element;
    assert(elements[0].id.series == 1);
    assert(elements[1].id.series == 2);
    assert(elements[2].id.series == 3);
    assert(elements[3].id.series == 4);
    assert(elements[4].id.series == 5);
    assert(elements[5].id.series == 6);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
}

TEST(test_concatenation_null_first){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr2 = create_array(2, person_type, &error);
    
    array* result = concatenation(NULL, arr2, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
    
    free_array(arr2);
}

TEST(test_concatenation_null_second){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, person_type, &error);
    
    array* result = concatenation(arr1, NULL, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
    
    free_array(arr1);
}

TEST(test_concatenation_both_null){
    array_errors error;
    
    array* result = concatenation(NULL, NULL, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_concatenation_incompatible_types){
    typeinfo* person_type = get_person_typeinfo();
    typeinfo* different_type = (typeinfo*)malloc(sizeof(typeinfo));
    different_type->size = sizeof(int);
    different_type->map = NULL;
    different_type->where = NULL;
    different_type->print = NULL;
    
    array_errors error;
    array* arr1 = create_array(2, person_type, &error);
    array* arr2 = create_array(2, different_type, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == INCOMPATIBLE_TYPES);
    assert(result == NULL);
    
    free_array(arr1);
    free_array(arr2);
    free(different_type);
}