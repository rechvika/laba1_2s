#include "testing.h"
#include "array_of_person.h"
#include "operation.h"
#include "serialize.h"
#include "typeinfo.h"
#include "array_errors.h"
#include <string.h>
#include <stdio.h>
#include "assertions.h"

TEST(test_get_special_field_polymorph_person) {
    typeinfo* info = create_person_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = get_special_field_polymorph(arr, 0, &error);
    
    assert(error == OPERATION_NOT_DEFINED);
    assert(result == NULL);
    
    free_array(arr);
    free(info);
}

TEST(test_get_special_field_polymorph_teacher) {
    typeinfo* info = create_teacher_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1111, 111111};
    birth_date birth = {1980, "Январь", 17};
    teacher* t = create_teacher(id, "Иван", "Иванович", "Петров", birth, "Математика");
    
    array_add(arr, (person*)t, NULL);
    
    char* result = get_special_field_polymorph(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "Математика") == 0);
    
    free_array(arr);
    free(info);
    free(t);
}

TEST(test_get_special_field_polymorph_student) {
    typeinfo* info = create_student_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1234, 567890};
    birth_date birth = {2005, "Февраль", 10};
    student* s = create_student(id, "Иван", "Иванович", "Петров", birth, "Информатика");
    
    array_add(arr, (person*)s, NULL);
    
    char* result = get_special_field_polymorph(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "Информатика") == 0);
    
    free_array(arr);
    free(info);
    free(s);
}

TEST(test_get_special_field_polymorph_null_array) {
    array_errors error;
    
    char* result = get_special_field_polymorph(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_get_special_field_polymorph_index_out_of_bounds) {
    typeinfo* info = create_teacher_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1111, 111111};
    birth_date birth = {1980, "Январь", 17};
    teacher* t = create_teacher(id, "Иван", "Иванович", "Петров", birth, "Математика");
    
    array_add(arr, (person*)t, NULL);
    
    char* result = get_special_field_polymorph(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
    free(info);
    free(t);
}

TEST(test_get_special_field_polymorph_teacher_multiple) {
    typeinfo* info = create_teacher_typeinfo();
    array* arr = create_array(3, info, NULL);
    array_errors error;
    
    person_id id1 = {1111, 111111};
    person_id id2 = {2222, 222222};
    person_id id3 = {3333, 333333};
    birth_date birth = {1980, "Январь", 17};
    
    teacher* t1 = create_teacher(id1, "Иван", "Иванович", "Петров", birth, "Математика");
    teacher* t2 = create_teacher(id2, "Петр", "Петрович", "Сидоров", birth, "Физика");
    teacher* t3 = create_teacher(id3, "Сидор", "Сидорович", "Иванов", birth, "Информатика");
    
    array_add(arr, (person*)t1, NULL);
    array_add(arr, (person*)t2, NULL);
    array_add(arr, (person*)t3, NULL);
    
    char* result1 = get_special_field_polymorph(arr, 0, &error);
    assert(strcmp(result1, "Математика") == 0);
    free(result1);
    
    char* result2 = get_special_field_polymorph(arr, 1, &error);
    assert(strcmp(result2, "Физика") == 0);
    free(result2);
    
    char* result3 = get_special_field_polymorph(arr, 2, &error);
    assert(strcmp(result3, "Информатика") == 0);
    free(result3);
    
    free_array(arr);
    free(info);
    free(t1);
    free(t2);
    free(t3);
}


TEST(test_print_person_polymorph_person) {
    typeinfo* info = create_person_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person p;
    strcpy(p.first_name, "Иван");
    strcpy(p.middle_name, "Иванович");
    strcpy(p.last_name, "Петров");
    array_add(arr, &p, NULL);
    
    print_person_polymorph(arr, 0, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    free_array(arr);
    free(info);
}

TEST(test_print_person_polymorph_teacher) {
    typeinfo* info = create_teacher_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1111, 111111};
    birth_date birth = {1980, "Январь", 17};
    teacher* t = create_teacher(id, "Иван", "Иванович", "Петров", birth, "Математика");
    
    array_add(arr, (person*)t, NULL);
    
    print_person_polymorph(arr, 0, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    free_array(arr);
    free(info);
    free(t);
}

TEST(test_print_person_polymorph_student) {
    typeinfo* info = create_student_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1234, 567890};
    birth_date birth = {2005, "Февраль", 10};
    student* s = create_student(id, "Иван", "Иванович", "Петров", birth, "Информатика");
    
    array_add(arr, (person*)s, NULL);
    
    print_person_polymorph(arr, 0, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    free_array(arr);
    free(info);
    free(s);
}

TEST(test_print_person_polymorph_null_array) {
    array_errors error;
    
    print_person_polymorph(NULL, 0, &error);
    assert(error == ARRAY_NOT_DEFINED);
}

TEST(test_print_person_polymorph_index_out_of_bounds) {
    typeinfo* info = create_person_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    print_person_polymorph(arr, 5, &error);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    free_array(arr);
    free(info);
}

TEST_ENTRY_POINT