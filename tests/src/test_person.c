#include "assertions.h"
#include "testing.h"
#include "array_of_person.h"
#include "where.h"
#include "map.h"
#include "concatenation.h"

TEST(test_get_series){
    person person;
    person.id.series = 1234;
    person.id.number = 567890;
    
    unsigned short series = get_series(&person);

    assert(series == 1234);

    free(series);
}

TEST(test_get_number){
    person person;
    person.id.series = 1234;
    person.id.number = 567890;

    unsigned short number = get_number(&person);

    assert(number == 567890);

    free(number);
}

TEST(test_get_full_name){
    person person;
    strcpy(person.first.name, "Карабас");
    strcpy(person.middle.name, "Барабас");
    strcpy(person.last.name, "Спанчбобович");

    char* full_name = get_full_name(&person);

    assert(strcmp(full_name, "Карабас Барабас Спанчбобович") == 0);
    free(full_name);
}

//клаааааасс
TEST(test_get_birth){
    person person;
    person.birth.yar = 2007;
    strcpy(person.birth.month, "Июнь");
    person.birth.date = 13;

    char* full_birth = get_full_berth(&person);

    assert(get_birth_year(&person) == 2007);
    assert(strcmp(get_birth_month(&person), "Июнь") == 0);
    assert(get_birth_date(&person) == 13);

    assert(strcmp(full_birth, "2007 Июнь 13") == 0);

    free(full_birth);
}

TEST(test_create_array){
    array* array = create_array(5);

    assert(array != NULL);
    assert(array->capacity == 5);
    assert(array->size == 0);
    assert(array->element != NULL);

    free_array(arr)
}

TEST(test_array_add){
    array* array = create_array(2);
    person person_1, person_2, person_3;
    
    array_add(array, &person_1);
    array_add(array, &person_2);
    array_add(array, &person_3);
    
    assert(array->size == 3);
    assert(array->capacity == 4);
    assert(array->element[0] == &person_1);
    assert(array->element[1] == &person_2);
    assert(array->element[2] == &person_3);

    free_array(array);
}

TEST(test_age_verification){
    person person;
    person.birth.year = 2007;

    unsigned short age = age_verification(&person);

    assert(age == 1);

    free(age);
}

TEST(test_where){
    array* array = create_array(3);
    person person_1, person_2, person_3;
    person_1.birth.year = 2007;
    person_2.birth.year = 2014;
    person_3.birth.year = 1999;

    array(array, &person_1);
    array(array, &person_2);
    array(array, &person_3);

    array* t_where = where(array, age_verification);

    assert(t_where->size == 2);
    assert(t_where->element[0] == &person_1);
    assert(t_where->element[1] == &person_2);
    assert(t_where->element[2] == &person_3);

    free_array(array);
    free_array(t_where);
}

TEST(test_map){
    array* array = create_array(2);
    peson person_1, person_2;
    strcpy(person_1.first_name, "Патрик");
    strcpy(person_2.first.name, "Сквидварт");

    array_add(array, &person_1);
    array_add(array, &person_2);

    array* mapped = map(array, map_function);

    assert(mapped->size == 2);
    assert(strcmp(mapped->element[0], "mapped_Патрик") == 0);
    assert(strcmp(mapped->element[1], "mapped_Сквидварт") == 0);

    for(int = 0; i < mapped->size; i++){
        free(mapped->element[i]);
    }
    free_array(array);
    free_array(mapped);
}

TEST(test_concatenation){
    array* array_1 = create_array(2);
    array* array_2 = create_array(2);
    person person_1, person_2, person_3, person_4;

    array_add(array_1, &person_1);
    array_add(array_1, &person_2);
    array_add(array_2, &person_3);
    array_add(array_2, &person_4);

    array* result = concatenation(array_1, array_2);

    assert(result->size == 4);
    assert(result->element[0] == &person_1);
    assert(result->element[1] == &person_2);
    assert(result->element[2] == &person_3);
    assert(result->element[3] == &person_4);

    free_array(array_1);
    free_array(array_2);
    free_array(result);
}

TEST_ENTRY_POINT