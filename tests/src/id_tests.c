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

TEST(test_get_series_normal_value){
    person person;
    person.id.series = 1234;
    array_errors error;
    
    unsigned short series = get_series(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(series == 1234);
}

TEST(test_get_series_min_value){
    person person;
    person.id.series = 0;
    array_errors error;
    
    unsigned short series = get_series(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(series == 0);
}

TEST(test_get_series_max_value){
    person person;
    person.id.series = 65535;
    array_errors error;
    
    unsigned short series = get_series(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(series == 65535);
}

TEST(test_get_series_mid_value){
    person person;
    person.id.series = 32768;
    array_errors error;
    
    unsigned short series = get_series(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(series == 32768);
}


TEST(test_get_series_null_pointer){
    array_errors error;
    
    unsigned short series = get_series(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(series == 0);
}

TEST(test_get_number_normal_value){
    person person;
    person.id.number = 567890;
    array_errors error;
    
    unsigned short number = get_number(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(number == 567890);
}

TEST(test_get_number_min_value){
    person person;
    person.id.number = 0;
    array_errors error;
    
    unsigned short number = get_number(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(number == 0);
}

TEST(test_get_number_max_value){
    person person;
    person.id.number = 65535;
    array_errors error;
    
    unsigned short number = get_number(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(number == 65535);
}

TEST(test_get_number_null_pointer){
    array_errors error;
    
    unsigned short number = get_number(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(number == 0);
}

TEST(test_get_full_id_normal_values){
    person person;
    person.id.series = 1234;
    person.id.number = 5678;
    array_errors error;
    
    char* full_id = get_full_id(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_id != NULL);
    assert(strcmp(full_id, "1234 5678") == 0);
    free(full_id);
}

TEST(test_get_full_id_zero_series){
    person person;
    person.id.series = 0;
    person.id.number = 5678;
    array_errors error;
    
    char* full_id = get_full_id(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_id != NULL);
    assert(strcmp(full_id, "0 5678") == 0);
    free(full_id);
}

TEST(test_get_full_id_zero_number){
    person person;
    person.id.series = 1234;
    person.id.number = 0;
    array_errors error;
    
    char* full_id = get_full_id(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_id != NULL);
    assert(strcmp(full_id, "1234 0") == 0);
    free(full_id);
}

TEST(test_get_full_id_both_zero){
    person person;
    person.id.series = 0;
    person.id.number = 0;
    array_errors error;
    
    char* full_id = get_full_id(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_id != NULL);
    assert(strcmp(full_id, "0 0") == 0);
    free(full_id);
}

TEST(test_get_full_id_max_values){
    person person;
    person.id.series = 65535;
    person.id.number = 65535;
    array_errors error;
    
    char* full_id = get_full_id(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_id != NULL);
    assert(strcmp(full_id, "65535 65535") == 0);
    free(full_id);
}

TEST(test_get_full_id_min_max){
    person person;
    person.id.series = 0;
    person.id.number = 65535;
    array_errors error;
    
    char* full_id = get_full_id(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_id != NULL);
    assert(strcmp(full_id, "0 65535") == 0);
    free(full_id);
}

TEST(test_get_full_id_null_pointer){
    array_errors error;
    
    char* full_id = get_full_id(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(full_id == NULL);
}

TEST(test_get_full_id_memory_allocation){
    person person;
    person.id.series = 1234;
    person.id.number = 5678;
    array_errors error;
    
    char* full_id = get_full_id(&person, &error);
    
    assert(full_id != NULL);
    assert(error == ARRAY_OPERATION_OK);
    
    free(full_id);
}

