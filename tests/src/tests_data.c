#include "testing.h"
#include "array_of_person.h"
#include "operation.h"
#include "serialize.h"
#include "typeinfo.h"
#include "array_errors.h"
#include <string.h>
#include <stdio.h>
#include "assertions.h"

TEST(test_get_teacher_subject_correct) {
    typeinfo* info = create_teacher_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1111, 111111};
    birth_date birth = {1980, "Январь", 17};
    teacher* t = create_teacher(id, "Иван", "Иванович", "Петров", birth, "Математика");
    
    array_add(arr, (person*)t, NULL);
    
    char* subject = get_teacher_subject(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(subject != NULL);
    assert(strcmp(subject, "Математика") == 0);
    
    free_array(arr);
    free(info);
    free(t);
}

TEST(test_get_teacher_subject_null_array) {
    array_errors error;
    
    char* subject = get_teacher_subject(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(subject == NULL);
}

TEST(test_get_teacher_subject_index_out_of_bounds) {
    typeinfo* info = create_teacher_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1111, 111111};
    birth_date birth = {1980, "Январь", 17};
    teacher* t = create_teacher(id, "Иван", "Иванович", "Петров", birth, "Математика");
    
    array_add(arr, (person*)t, NULL);
    
    char* subject = get_teacher_subject(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(subject == NULL);
    
    free_array(arr);
    free(info);
    free(t);
}

TEST(test_get_student_direction_correct) {
    typeinfo* info = create_student_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1234, 567890};
    birth_date birth = {2005, "Февраль", 10};
    student* s = create_student(id, "Иван", "Иванович", "Петров", birth, "Информатика");
    
    array_add(arr, (person*)s, NULL);
    
    char* direction = get_student_direction(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(direction != NULL);
    assert(strcmp(direction, "Информатика") == 0);
    
    free_array(arr);
    free(info);
    free(s);
}

TEST(test_get_student_direction_null_array) {
    array_errors error;
    
    char* direction = get_student_direction(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(direction == NULL);
}

TEST(test_get_student_direction_index_out_of_bounds) {
    typeinfo* info = create_student_typeinfo();
    array* arr = create_array(1, info, NULL);
    array_errors error;
    
    person_id id = {1234, 567890};
    birth_date birth = {2005, "Февраль", 10};
    student* s = create_student(id, "Иван", "Иванович", "Петров", birth, "Информатика");
    
    array_add(arr, (person*)s, NULL);
    
    char* direction = get_student_direction(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(direction == NULL);
    
    free_array(arr);
    free(info);
    free(s);
}

TEST_ENTRY_POINT