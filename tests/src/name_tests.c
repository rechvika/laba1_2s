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

TEST(test_get_first_name_normal){
    person person;
    strcpy(person.first_name, "Иван");
    array_errors error;
    
    char* first_name = get_first_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(first_name, "Иван") == 0);
}

TEST(test_get_first_name_empty){
    person person;
    strcpy(person.first_name, "");
    array_errors error;
    
    char* first_name = get_first_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(first_name, "") == 0);
}

TEST(test_get_first_name_long){
    person person;
    char long_name[MAX_LINE_NAME];
    memset(long_name, 'A', MAX_LINE_NAME - 2);
    long_name[MAX_LINE_NAME - 2] = '\0';
    strcpy(person.first_name, long_name);
    array_errors error;
    
    char* first_name = get_first_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(first_name, long_name) == 0);
}

TEST(test_get_first_name_special_chars){
    person person;
    strcpy(person.first_name, "Анна-Мария");
    array_errors error;
    
    char* first_name = get_first_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(first_name, "Анна-Мария") == 0);
}

TEST(test_get_first_name_numbers){
    person person;
    strcpy(person.first_name, "Иван123");
    array_errors error;
    
    char* first_name = get_first_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(first_name, "Иван123") == 0);
}

TEST(test_get_first_name_null_pointer){
    array_errors error;
    
    char* first_name = get_first_name(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(first_name == NULL);
}

TEST(test_get_middle_name_normal){
    person person;
    strcpy(person.middle_name, "Иванович");
    array_errors error;
    
    char* middle_name = get_middle_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(middle_name, "Иванович") == 0);
}

TEST(test_get_middle_name_empty){
    person person;
    strcpy(person.middle_name, "");
    array_errors error;
    
    char* middle_name = get_middle_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(middle_name, "") == 0);
}

TEST(test_get_middle_name_long){
    person person;
    char long_name[MAX_LINE_NAME];
    memset(long_name, 'B', MAX_LINE_NAME - 2);
    long_name[MAX_LINE_NAME - 2] = '\0';
    strcpy(person.middle_name, long_name);
    array_errors error;
    
    char* middle_name = get_middle_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(middle_name, long_name) == 0);
}

TEST(test_get_middle_name_null_pointer){
    array_errors error;
    
    char* middle_name = get_middle_name(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(middle_name == NULL);
}

TEST(test_get_last_name_normal){
    person person;
    strcpy(person.last_name, "Петров");
    array_errors error;
    
    char* last_name = get_last_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(last_name, "Петров") == 0);
}

TEST(test_get_last_name_empty){
    person person;
    strcpy(person.last_name, "");
    array_errors error;
    
    char* last_name = get_last_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(last_name, "") == 0);
}

TEST(test_get_last_name_long){
    person person;
    char long_name[MAX_LINE_NAME];
    memset(long_name, 'C', MAX_LINE_NAME - 2);
    long_name[MAX_LINE_NAME - 2] = '\0';
    strcpy(person.last_name, long_name);
    array_errors error;
    
    char* last_name = get_last_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(last_name, long_name) == 0);
}

TEST(test_get_last_name_null_pointer){
    array_errors error;
    
    char* last_name = get_last_name(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(last_name == NULL);
}

TEST(test_get_full_name_all_parts){
    person person;
    strcpy(person.first_name, "Иван");
    strcpy(person.middle_name, "Иванович");
    strcpy(person.last_name, "Петров");
    array_errors error;

    char* full_name = get_full_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_name != NULL);
    assert(strcmp(full_name, "Иван Иванович Петров") == 0);
    free(full_name);
}

TEST(test_get_full_name_no_middle){
    person person;
    strcpy(person.first_name, "Иван");
    strcpy(person.middle_name, "");
    strcpy(person.last_name, "Петров");
    array_errors error;

    char* full_name = get_full_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_name != NULL);
    assert(strcmp(full_name, "Иван  Петров") == 0);
    free(full_name);
}

TEST(test_get_full_name_no_first){
    person person;
    strcpy(person.first_name, "");
    strcpy(person.middle_name, "Иванович");
    strcpy(person.last_name, "Петров");
    array_errors error;

    char* full_name = get_full_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_name != NULL);
    assert(strcmp(full_name, " Иванович Петров") == 0);
    free(full_name);
}

TEST(test_get_full_name_no_last){
    person person;
    strcpy(person.first_name, "Иван");
    strcpy(person.middle_name, "Иванович");
    strcpy(person.last_name, "");
    array_errors error;

    char* full_name = get_full_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_name != NULL);
    assert(strcmp(full_name, "Иван Иванович ") == 0);
    free(full_name);
}

TEST(test_get_full_name_only_first){
    person person;
    strcpy(person.first_name, "Иван");
    strcpy(person.middle_name, "");
    strcpy(person.last_name, "");
    array_errors error;

    char* full_name = get_full_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_name != NULL);
    assert(strcmp(full_name, "Иван  ") == 0);
    free(full_name);
}

TEST(test_get_full_name_all_empty){
    person person;
    strcpy(person.first_name, "");
    strcpy(person.middle_name, "");
    strcpy(person.last_name, "");
    array_errors error;

    char* full_name = get_full_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_name != NULL);
    assert(strcmp(full_name, "  ") == 0);
    free(full_name);
}

TEST(test_get_full_name_long_names){
    person person;
    char long_first[MAX_LINE_NAME];
    char long_middle[MAX_LINE_NAME];
    char long_last[MAX_LINE_NAME];
    
    memset(long_first, 'A', MAX_LINE_NAME - 2);
    long_first[MAX_LINE_NAME - 2] = '\0';
    memset(long_middle, 'B', MAX_LINE_NAME - 2);
    long_middle[MAX_LINE_NAME - 2] = '\0';
    memset(long_last, 'C', MAX_LINE_NAME - 2);
    long_last[MAX_LINE_NAME - 2] = '\0';
    
    strcpy(person.first_name, long_first);
    strcpy(person.middle_name, long_middle);
    strcpy(person.last_name, long_last);
    array_errors error;

    char* full_name = get_full_name(&person, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_name != NULL);
    
    char expected[FULL_NAME];
    sprintf(expected, "%s %s %s", long_first, long_middle, long_last);
    assert(strcmp(full_name, expected) == 0);
    
    free(full_name);
}

TEST(test_get_full_name_null_pointer){
    array_errors error;
    
    char* full_name = get_full_name(NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    assert(full_name == NULL);
}

TEST(test_get_full_name_memory_allocation){
    person person;
    strcpy(person.first_name, "Иван");
    strcpy(person.middle_name, "Иванович");
    strcpy(person.last_name, "Петров");
    array_errors error;

    char* full_name = get_full_name(&person, &error);
    
    assert(full_name != NULL);
    assert(error == ARRAY_OPERATION_OK);
    
    free(full_name);
}