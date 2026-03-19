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

TEST(test_get_birth_year_normal){
    person person;
    person.birth.year = 2000;
    array_errors error;
    
    unsigned short year = get_birth_year(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(year == 2000);
}

TEST(test_get_birth_year_min){
    person person;
    person.birth.year = 0;
    array_errors error;
    
    unsigned short year = get_birth_year(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(year == 0);
}

TEST(test_get_birth_year_max){
    person person;
    person.birth.year = 65535;
    array_errors error;
    
    unsigned short year = get_birth_year(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(year == 65535);
}

TEST(test_get_birth_year_1900){
    person person;
    person.birth.year = 1900;
    array_errors error;
    
    unsigned short year = get_birth_year(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(year == 1900);
}

TEST(test_get_birth_year_2025){
    person person;
    person.birth.year = 2025;
    array_errors error;
    
    unsigned short year = get_birth_year(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(year == 2025);
}

TEST(test_get_birth_year_null_pointer){
    array_errors error;
    
    unsigned short year = get_birth_year(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(year == 0);
}

TEST(test_get_birth_month_january){
    person person;
    strcpy(person.birth.month, "Январь");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Январь") == 0);
}

TEST(test_get_birth_month_february){
    person person;
    strcpy(person.birth.month, "Февраль");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Февраль") == 0);
}

TEST(test_get_birth_month_march){
    person person;
    strcpy(person.birth.month, "Март");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Март") == 0);
}

TEST(test_get_birth_month_april){
    person person;
    strcpy(person.birth.month, "Апрель");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Апрель") == 0);
}

TEST(test_get_birth_month_may){
    person person;
    strcpy(person.birth.month, "Май");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Май") == 0);
}

TEST(test_get_birth_month_june){
    person person;
    strcpy(person.birth.month, "Июнь");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Июнь") == 0);
}

TEST(test_get_birth_month_july){
    person person;
    strcpy(person.birth.month, "Июль");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Июль") == 0);
}

TEST(test_get_birth_month_august){
    person person;
    strcpy(person.birth.month, "Август");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Август") == 0);
}

TEST(test_get_birth_month_september){
    person person;
    strcpy(person.birth.month, "Сентябрь");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Сентябрь") == 0);
}

TEST(test_get_birth_month_october){
    person person;
    strcpy(person.birth.month, "Октябрь");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Октябрь") == 0);
}

TEST(test_get_birth_month_november){
    person person;
    strcpy(person.birth.month, "Ноябрь");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Ноябрь") == 0);
}

TEST(test_get_birth_month_december){
    person person;
    strcpy(person.birth.month, "Декабрь");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Декабрь") == 0);
}

TEST(test_get_birth_month_empty){
    person person;
    strcpy(person.birth.month, "");
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "") == 0);
}

TEST(test_get_birth_month_long){
    person person;
    char long_month[MAX_LINE_MONTH];
    memset(long_month, 'M', MAX_LINE_MONTH - 2);
    long_month[MAX_LINE_MONTH - 2] = '\0';
    strcpy(person.birth.month, long_month);
    array_errors error;
    
    char* month = get_birth_month(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, long_month) == 0);
}

TEST(test_get_birth_month_null_pointer){
    array_errors error;
    
    char* month = get_birth_month(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(month == NULL);
}

TEST(test_get_birth_date_normal){
    person person;
    person.birth.date = 15;
    array_errors error;
    
    unsigned short date = get_birth_date(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(date == 15);
}

TEST(test_get_birth_date_min){
    person person;
    person.birth.date = 1;
    array_errors error;
    
    unsigned short date = get_birth_date(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(date == 1);
}

TEST(test_get_birth_date_max){
    person person;
    person.birth.date = 31;
    array_errors error;
    
    unsigned short date = get_birth_date(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(date == 31);
}

TEST(test_get_birth_date_zero){
    person person;
    person.birth.date = 0;
    array_errors error;
    
    unsigned short date = get_birth_date(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(date == 0);
}

TEST(test_get_birth_date_mid){
    person person;
    person.birth.date = 16;
    array_errors error;
    
    unsigned short date = get_birth_date(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(date == 16);
}

TEST(test_get_birth_date_29){
    person person;
    person.birth.date = 29;
    array_errors error;
    
    unsigned short date = get_birth_date(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(date == 29);
}

TEST(test_get_birth_date_30){
    person person;
    person.birth.date = 30;
    array_errors error;
    
    unsigned short date = get_birth_date(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(date == 30);
}

TEST(test_get_birth_date_null_pointer){
    array_errors error;
    
    unsigned short date = get_birth_date(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(date == 0);
}

TEST(test_get_full_birth_normal){
    person person;
    person.birth.year = 2000;
    strcpy(person.birth.month, "Январь");
    person.birth.date = 15;
    array_errors error;
    
    char* full_birth = get_full_birth(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_birth != NULL);
    assert(strcmp(full_birth, "2000 Январь 15") == 0);
    free(full_birth);
}

TEST(test_get_full_birth_year_zero){
    person person;
    person.birth.year = 0;
    strcpy(person.birth.month, "Январь");
    person.birth.date = 15;
    array_errors error;
    
    char* full_birth = get_full_birth(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_birth != NULL);
    assert(strcmp(full_birth, "0 Январь 15") == 0);
    free(full_birth);
}

TEST(test_get_full_birth_month_empty){
    person person;
    person.birth.year = 2000;
    strcpy(person.birth.month, "");
    person.birth.date = 15;
    array_errors error;
    
    char* full_birth = get_full_birth(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_birth != NULL);
    assert(strcmp(full_birth, "2000  15") == 0);
    free(full_birth);
}

TEST(test_get_full_birth_date_zero){
    person person;
    person.birth.year = 2000;
    strcpy(person.birth.month, "Январь");
    person.birth.date = 0;
    array_errors error;
    
    char* full_birth = get_full_birth(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_birth != NULL);
    assert(strcmp(full_birth, "2000 Январь 0") == 0);
    free(full_birth);
}

TEST(test_get_full_birth_all_zero){
    person person;
    person.birth.year = 0;
    strcpy(person.birth.month, "");
    person.birth.date = 0;
    array_errors error;
    
    char* full_birth = get_full_birth(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_birth != NULL);
    assert(strcmp(full_birth, "0  0") == 0);
    free(full_birth);
}

TEST(test_get_full_birth_max_values){
    person person;
    person.birth.year = 65535;
    strcpy(person.birth.month, "Декабрь");
    person.birth.date = 31;
    array_errors error;
    
    char* full_birth = get_full_birth(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_birth != NULL);
    assert(strcmp(full_birth, "65535 Декабрь 31") == 0);
    free(full_birth);
}

TEST(test_get_full_birth_long_month){
    person person;
    person.birth.year = 2000;
    char long_month[MAX_LINE_MONTH];
    memset(long_month, 'M', MAX_LINE_MONTH - 2);
    long_month[MAX_LINE_MONTH - 2] = '\0';
    strcpy(person.birth.month, long_month);
    person.birth.date = 15;
    array_errors error;
    
    char* full_birth = get_full_birth(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_birth != NULL);
    
    char expected[FULL_BIRTH];
    sprintf(expected, "%hu %s %hu", person.birth.year, long_month, person.birth.date);
    assert(strcmp(full_birth, expected) == 0);
    free(full_birth);
}

TEST(test_get_full_birth_null_pointer){
    array_errors error;
    
    char* full_birth = get_full_birth(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(full_birth == NULL);
}

TEST(test_get_full_birth_memory_allocation){
    person person;
    person.birth.year = 2000;
    strcpy(person.birth.month, "Январь");
    person.birth.date = 15;
    array_errors error;
    
    char* full_birth = get_full_birth(&person, &error);
    
    assert(full_birth != NULL);
    assert(error == ARRAY_OPERATION_OK);
    
    free(full_birth);
}