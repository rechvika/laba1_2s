#include "person_typeinfo.h"

static typeinfo* PERSON_TYPEINFO = NULL;

char* person_map_function(const void* data){
    const person* p = (const person*)data;
    array_errors error;
    return map_function((person*)p, &error);
}

unsigned short person_where_function(const void* data){
    const person* p = (const person*)data;
    array_errors error;
    return age_verification((person*)p, &error);
}

void person_print(const void* data){
    const person* p = (const person*)data;
    array_errors error;
    char* full_name = get_full_name((person*)p, &error);

    if (error == ARRAY_OPERATION_OK && full_name != NULL) {
        printf("ФИО: %s", full_name);
        free(full_name);
    } else {
        printf("Ошибка вывода");
    }
}

typeinfo* get_person_typeinfo(){
    if (PERSON_TYPEINFO == NULL){
        PERSON_TYPEINFO = (typeinfo*)malloc(sizeof(typeinfo));
        if (PERSON_TYPEINFO != NULL){
            PERSON_TYPEINFO->size = sizeof(person);
            PERSON_TYPEINFO->map = person_map_function;
            PERSON_TYPEINFO->where = person_where_function;
            PERSON_TYPEINFO->print = person_print;
        }
    }
    return PERSON_TYPEINFO;
}