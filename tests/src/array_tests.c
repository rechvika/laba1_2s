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

TEST(test_create_array_normal){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(5, person_type, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr != NULL);
    assert(arr->capacity == 5);
    assert(arr->size == 0);
    assert(arr->element != NULL);
    assert(arr->typeinfo == person_type);
    
    free_array(arr);
}

TEST(test_create_array_capacity_1){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(1, person_type, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr != NULL);
    assert(arr->capacity == 1);
    assert(arr->size == 0);
    assert(arr->element != NULL);
    
    free_array(arr);
}

TEST(test_create_array_capacity_10){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(10, person_type, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr != NULL);
    assert(arr->capacity == 10);
    assert(arr->size == 0);
    
    free_array(arr);
}

TEST(test_create_array_capacity_100){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(100, person_type, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr != NULL);
    assert(arr->capacity == 100);
    assert(arr->size == 0);
    
    free_array(arr);
}

TEST(test_create_array_zero_capacity){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(0, person_type, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr != NULL);
    assert(arr->capacity == 0);
    
    free_array(arr);
}

TEST(test_create_array_null_typeinfo){
    array_errors error;
    
    array* arr = create_array(5, NULL, &error);
    
    assert(error == OPERATION_NOT_DEFINED);
    assert(arr == NULL);
}

TEST(test_create_array_negative_capacity){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(-1, person_type, &error);

    if (arr != NULL) {
        assert(arr->capacity > 1000000);
        free_array(arr);
    } else {
        assert(error == MEMORY_ALLOCATION_FAILED);
    }
}

TEST(test_array_add_one_element){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p;
    p.id.series = 1234;
    
    array_add(arr, &p, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr->size == 1);
    assert(arr->capacity == 2);
    
    person* first = (person*)arr->element;
    assert(first->id.series == 1234);
    
    free_array(arr);
}

TEST(test_array_add_two_elements){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2;
    p1.id.series = 111;
    p2.id.series = 222;
    
    array_add(arr, &p1, &error);
    assert(error == ARRAY_OPERATION_OK);
    array_add(arr, &p2, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    assert(arr->size == 2);
    assert(arr->capacity == 2);
    
    person* elements = (person*)arr->element;
    assert(elements[0].id.series == 111);
    assert(elements[1].id.series == 222);
    
    free_array(arr);
}

TEST(test_array_add_exceed_capacity){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3;
    p1.id.series = 111;
    p2.id.series = 222;
    p3.id.series = 333;
    
    array_add(arr, &p1, &error);
    assert(error == ARRAY_OPERATION_OK);
    array_add(arr, &p2, &error);
    assert(error == ARRAY_OPERATION_OK);
    array_add(arr, &p3, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    assert(arr->size == 3);
    assert(arr->capacity == 4);
    
    person* elements = (person*)arr->element;
    assert(elements[0].id.series == 111);
    assert(elements[1].id.series == 222);
    assert(elements[2].id.series == 333);
    
    free_array(arr);
}

TEST(test_array_add_multiple_expansions){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(1, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p;

    for(int i = 0; i < 10; i++){
        p.id.series = i;
        array_add(arr, &p, &error);
        assert(error == ARRAY_OPERATION_OK);
    }
    
    assert(arr->size == 10);
    assert(arr->capacity >= 10);
    
    person* elements = (person*)arr->element;
    for(int i = 0; i < 10; i++){
        assert(elements[i].id.series == i);
    }
    
    free_array(arr);
}

TEST(test_array_add_100_elements){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(10, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p;
    for(int i = 0; i < 100; i++){
        p.id.series = i;
        array_add(arr, &p, &error);
        assert(error == ARRAY_OPERATION_OK);
    }
    
    assert(arr->size == 100);
    assert(arr->capacity >= 100);
    
    free_array(arr);
}

TEST(test_array_add_preserve_data){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3;
    p1.id.series = 111;
    p1.id.number = 1111;
    strcpy(p1.first_name, "Иван");
    
    p2.id.series = 222;
    p2.id.number = 2222;
    strcpy(p2.first_name, "Петр");
    
    p3.id.series = 333;
    p3.id.number = 3333;
    strcpy(p3.first_name, "Сидор");
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error); 
    
    person* elements = (person*)arr->element;

    assert(elements[0].id.series == 111);
    assert(elements[0].id.number == 1111);
    assert(strcmp(elements[0].first_name, "Иван") == 0);
    
    assert(elements[1].id.series == 222);
    assert(elements[1].id.number == 2222);
    assert(strcmp(elements[1].first_name, "Петр") == 0);
    
    assert(elements[2].id.series == 333);
    assert(elements[2].id.number == 3333);
    assert(strcmp(elements[2].first_name, "Сидор") == 0);
    
    free_array(arr);
}

TEST(test_array_add_null_array){
    person p;
    array_errors error;
    
    array_add(NULL, &p, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
}

TEST(test_array_add_null_person){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    array_add(arr, NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(arr->size == 0);
    
    free_array(arr);
}

TEST(test_array_add_both_null){
    array_errors error;
    
    array_add(NULL, NULL, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
}

TEST(test_free_array_normal){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, person_type, &error);

    person p;
    array_add(arr, &p, &error);

    free_array(arr);

    assert(1);
}

TEST(test_free_array_empty){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, person_type, &error);
    
    free_array(arr);
    
    assert(1);
}

TEST(test_free_array_null){
    free_array(NULL);
    assert(1);
}

TEST(test_free_array_zero_capacity){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(0, person_type, &error);
    
    free_array(arr);
    
    assert(1);
}

TEST(test_free_array_large){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(1000, person_type, &error);
    
    person p;
    for(int i = 0; i < 500; i++){
        array_add(arr, &p, &error);
    }
    
    free_array(arr);
    
    assert(1);
}