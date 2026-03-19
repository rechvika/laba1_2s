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

TEST(test_get_person_typeinfo){
    typeinfo* person_type = get_person_typeinfo();
    
    assert(person_type != NULL);
    assert(person_type->size == sizeof(person));
}

TEST(test_person_typeinfo_map_function){
    typeinfo* person_type = get_person_typeinfo();
    
    assert(person_type->map != NULL);
}

TEST(test_person_typeinfo_where_function){
    typeinfo* person_type = get_person_typeinfo();
    
    assert(person_type->where != NULL);
}

TEST(test_person_typeinfo_print_function){
    typeinfo* person_type = get_person_typeinfo();
    
    assert(person_type->print != NULL);
}

TEST(test_person_typeinfo_singleton){
    typeinfo* person_type1 = get_person_typeinfo();
    typeinfo* person_type2 = get_person_typeinfo();
    
    assert(person_type1 == person_type2);
}

TEST(test_person_map_function_wrapper){
    person p;
    strcpy(p.first_name, "Тест");
    
    char* result = person_map_function(&p);
    
    assert(result != NULL);
    assert(strcmp(result, "mapped_Тест") == 0);
    
    free(result);
}

TEST(test_person_where_function_wrapper){
    person p;
    p.birth.year = 2000;
    array_errors error;
    
    unsigned short result = person_where_function(&p);
    unsigned short expected = age_verification(&p, &error);
    
    assert(result == expected);
}

TEST(test_person_print_function){

    person p;
    strcpy(p.first_name, "Иван");
    strcpy(p.middle_name, "Иванович");
    strcpy(p.last_name, "Петров");
    
    person_print(&p);

    assert(1);
}

TEST(test_person_print_null){
    person_print(NULL);
    assert(1);
}