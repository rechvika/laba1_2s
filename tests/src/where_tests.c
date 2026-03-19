#include "assertions.h"
#include "testing.h"
#include "array_of_person.h"
#include "where.h"
#include "map.h"
#include "concatenation.h"

TEST(test_age_verification_18_years){
    person person;
    person.birth.year = 2008; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 1);
}

TEST(test_age_verification_19_years){
    person person;
    person.birth.year = 2007;
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 1);
}

TEST(test_age_verification_30_years){
    person person;
    person.birth.year = 1996; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 1);
}

TEST(test_age_verification_50_years){
    person person;
    person.birth.year = 1976; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 1);
}

TEST(test_age_verification_100_years){
    person person;
    person.birth.year = 1926;
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 1);
}

TEST(test_age_verification_17_years){
    person person;
    person.birth.year = 2009; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 0);
}

TEST(test_age_verification_10_years){
    person person;
    person.birth.year = 2016; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 0);
}

TEST(test_age_verification_1_year){
    person person;
    person.birth.year = 2025;
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 0);
}

TEST(test_age_verification_0_years){
    person person;
    person.birth.year = 2026; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 0);
}

TEST(test_age_verification_future_birth){
    person person;
    person.birth.year = 2030; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 0);
}

TEST(test_age_verification_min_year){
    person person;
    person.birth.year = 0; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 1);
}

TEST(test_age_verification_max_year){
    person person;
    person.birth.year = 65535; 
    array_errors error;
    
    unsigned short result = age_verification(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);

    assert(result == 0);
}

TEST(test_age_verification_null_pointer){
    array_errors error;
    
    unsigned short result = age_verification(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(result == 0);
}

TEST(test_where_all_adults){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(3, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3;
    p1.birth.year = 2000;
    p2.birth.year = 1995;
    p3.birth.year = 1990;
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered != NULL);
    assert(filtered->size == 3);
    
    free_array(arr);
    free_array(filtered);
}

TEST(test_where_no_adults){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(3, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3;
    p1.birth.year = 2015;
    p2.birth.year = 2016;
    p3.birth.year = 2017;
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered != NULL);
    assert(filtered->size == 0);
    
    free_array(arr);
    free_array(filtered);
}

TEST(test_where_mixed_adults){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3, p4, p5;
    p1.birth.year = 2000; 
    p2.birth.year = 2015; 
    p3.birth.year = 1995; 
    p4.birth.year = 2010; 
    p5.birth.year = 1980; 
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    array_add(arr, &p4, &error);
    array_add(arr, &p5, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered->size == 3);
    
    person* elements = (person*)filtered->element;
    assert(elements[0].birth.year == 2000);
    assert(elements[1].birth.year == 1995);
    assert(elements[2].birth.year == 1980);
    
    free_array(arr);
    free_array(filtered);
}

TEST(test_where_one_adult){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(3, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3;
    p1.birth.year = 2015; 
    p2.birth.year = 2000; 
    p3.birth.year = 2016; 
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered->size == 1);
    
    person* elements = (person*)filtered->element;
    assert(elements[0].birth.year == 2000);
    
    free_array(arr);
    free_array(filtered);
}

TEST(test_where_empty_array){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(3, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered != NULL);
    assert(filtered->size == 0);
    
    free_array(arr);
    free_array(filtered);
}

TEST(test_where_preserve_order){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3, p4;
    p1.birth.year = 2000;
    p2.birth.year = 2015;
    p3.birth.year = 1995;
    p4.birth.year = 1980; 
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    array_add(arr, &p4, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered->size == 3);

    person* elements = (person*)filtered->element;
    assert(elements[0].birth.year == 2000);
    assert(elements[1].birth.year == 1995);
    assert(elements[2].birth.year == 1980);
    
    free_array(arr);
    free_array(filtered);
}

TEST(test_where_null_array){
    array_errors error;
    
    array* filtered = where(NULL, age_verification, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(filtered == NULL);
}

TEST(test_where_null_function){
    typeinfo* person_type = get_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, person_type, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    array* filtered = where(arr, NULL, &error);
    
    assert(error == OPERATION_NOT_DEFINED);
    assert(filtered == NULL);
    
    free_array(arr);
}

TEST(test_where_both_null){
    array_errors error;
    
    array* filtered = where(NULL, NULL, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(filtered == NULL);
}