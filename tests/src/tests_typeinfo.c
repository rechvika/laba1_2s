#include "testing.h"
#include "array_of_person.h"
#include "operation.h"
#include "serialize.h"
#include "typeinfo.h"
#include "array_errors.h"
#include <string.h>
#include <stdio.h>
#include "assertions.h"

TEST(test_create_person_typeinfo) {
    typeinfo* info = create_person_typeinfo();
    
    assert(info != NULL);
    assert(info->size == sizeof(person));
    assert(info->type_name != NULL);
    assert(strcmp(info->type_name, "person") == 0);
    assert(info->get_full_name != NULL);
    assert(info->get_special_field != NULL);
    assert(info->print != NULL);
    
    free(info);
}

TEST(test_create_teacher_typeinfo) {
    typeinfo* info = create_teacher_typeinfo();
    
    assert(info != NULL);
    assert(info->size == sizeof(teacher));
    assert(strcmp(info->type_name, "teacher") == 0);
    
    free(info);
}

TEST(test_create_student_typeinfo) {
    typeinfo* info = create_student_typeinfo();
    
    assert(info != NULL);
    assert(info->size == sizeof(student));
    assert(strcmp(info->type_name, "student") == 0);
    
    free(info);
}


TEST(test_create_person) {
    person_id id = {1234, 5678};
    birth_date birth = {2000, "Январь", 15};
    
    person* p = create_person(id, "Иван", "Иванович", "Петров", birth);
    
    assert(p != NULL);
    assert(p->vtable != NULL);
    assert(p->id.series == 1234);
    assert(p->id.number == 5678);
    assert(strcmp(p->first_name, "Иван") == 0);
    assert(strcmp(p->middle_name, "Иванович") == 0);
    assert(strcmp(p->last_name, "Петров") == 0);
    assert(p->birth.year == 2000);
    assert(strcmp(p->birth.month, "Январь") == 0);
    assert(p->birth.date == 15);
    
    free(p);
}

TEST(test_create_teacher) {
    person_id id = {1111, 2222};
    birth_date birth = {1980, "Январь", 17};
    
    teacher* t = create_teacher(id, "Иван", "Иванович", "Петров", birth, "Математика");
    
    assert(t != NULL);
    assert(t->base.vtable != NULL);
    assert(t->base.id.series == 1111);
    assert(strcmp(t->data.subject, "Математика") == 0);
    
    free(t);
}

TEST(test_create_student) {
    person_id id = {1234, 5678};
    birth_date birth = {2005, "Февраль", 10};
    
    student* s = create_student(id, "Иван", "Иванович", "Петров", birth, "Информатика");
    
    assert(s != NULL);
    assert(s->base.vtable != NULL);
    assert(s->base.id.series == 1234);
    assert(strcmp(s->data.direction, "Информатика") == 0);
    
    free(s);
}
