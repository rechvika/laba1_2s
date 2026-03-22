#include "typeinfo.h"

static char* person_get_full_name(array* arr, unsigned int i, array_errors* error){
    return get_full_name(arr, i, error);
}

static char* person_get_special_field(array* arr, unsigned int i, array_errors* error){
    *error = OPERATION_NOT_DEFINED;
    return NULL;
}

static void person_print(array* arr, unsigned int i, array_errors* error){
    char* full_name = get_full_name(arr, i, error);
    if (*error == ARRAY_OPERATION_OK && full_name != NULL) {
        printf("Персона: %s\n", full_name);
        free(full_name);
    }
}

static char* teacher_get_full_name(array* arr, unsigned int i, array_errors* error){
    return get_full_name(arr, i, error);
}

static char* teacher_get_special_field(array* arr, unsigned int i, array_errors* error){
    return get_teacher_subject(arr, i, error);
}

static void teacher_print(array* arr, unsigned int i, array_errors* error){
    char* full_name = get_full_name(arr, i, error);
    char* subject = get_teacher_subject(arr, i, error);
    if (*error == ARRAY_OPERATION_OK && full_name != NULL && subject != NULL) {
        printf("Преподаватель: %s, Предмет: %s\n", full_name, subject);
        free(full_name);
    }
}

static char* student_get_full_name(array* arr, unsigned int i, array_errors* error){
    return get_full_name(arr, i, error);
}

static char* student_get_special_field(array* arr, unsigned int i, array_errors* error){
    return get_student_direction(arr, i, error);
}

static void student_print(array* arr, unsigned int i, array_errors* error){
    char* full_name = get_full_name(arr, i, error);
    char* direction = get_student_direction(arr, i, error);
    if (*error == ARRAY_OPERATION_OK && full_name != NULL && direction != NULL) {
        printf("Студент: %s, Направление: %s\n", full_name, direction);
        free(full_name);
    }
}


char* get_special_field_polymorph(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    if (arr->typeinfo->get_special_field == NULL) {
        *error = OPERATION_NOT_DEFINED;
        return NULL;
    }
    
    return arr->typeinfo->get_special_field(arr, i, error);
}

void print_person_polymorph(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return;
    }
    if (arr->typeinfo->print == NULL) {
        *error = OPERATION_NOT_DEFINED;
        return;
    }
    
    arr->typeinfo->print(arr, i, error);
}



typeinfo* create_person_typeinfo(){
    typeinfo* info = (typeinfo*)malloc(sizeof(typeinfo));
    if (info == NULL) return NULL;
    
    info->size = sizeof(person);
    info->type_name = "person";
    info->get_full_name = person_get_full_name;
    info->get_special_field = person_get_special_field;
    info->print = person_print;
    return info;
}

typeinfo* create_teacher_typeinfo(){
    typeinfo* info = (typeinfo*)malloc(sizeof(typeinfo));
    if (info == NULL) return NULL;
    
    info->size = sizeof(teacher);
    info->type_name = "teacher";
    info->get_full_name = teacher_get_full_name;
    info->get_special_field = teacher_get_special_field;
    info->print = teacher_print;
    return info;
}

typeinfo* create_student_typeinfo(){
    typeinfo* info = (typeinfo*)malloc(sizeof(typeinfo));
    if (info == NULL) return NULL;
    
    info->size = sizeof(student);
    info->type_name = "student";
    info->get_full_name = student_get_full_name;
    info->get_special_field = student_get_special_field;
    info->print = student_print;
    return info;
}


person* create_person(person_id id, char* first_name, char* middle_name, char* last_name, birth_date birth){
    person* p = (person*)malloc(sizeof(person));
    if (p == NULL) return NULL;
    
    p->vtable = create_person_typeinfo();
    p->id = id;
    strcpy(p->first_name, first_name);
    strcpy(p->middle_name, middle_name);
    strcpy(p->last_name, last_name);
    p->birth = birth;
    
    return p;
}

teacher* create_teacher(person_id id, char* first_name, char* middle_name, char* last_name, birth_date birth, char* subject){
    teacher* t = (teacher*)malloc(sizeof(teacher));
    if (t == NULL) return NULL;
    
    t->base.vtable = create_teacher_typeinfo();
    t->base.id = id;
    strcpy(t->base.first_name, first_name);
    strcpy(t->base.middle_name, middle_name);
    strcpy(t->base.last_name, last_name);
    t->base.birth = birth;
    strcpy(t->data.subject, subject);
    
    return t;
}

student* create_student(person_id id, char* first_name, char* middle_name, char* last_name, birth_date birth, char* direction){
    student* s = (student*)malloc(sizeof(student));
    if (s == NULL) return NULL;
    
    s->base.vtable = create_student_typeinfo();
    s->base.id = id;
    strcpy(s->base.first_name, first_name);
    strcpy(s->base.middle_name, middle_name);
    strcpy(s->base.last_name, last_name);
    s->base.birth = birth;
    strcpy(s->data.direction, direction);
    
    return s;
}