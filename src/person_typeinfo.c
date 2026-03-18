#include "person_typeinfo.h"

static typeinfo* PERSON_TYPEINFO = NULL;

char* person_map_function(const void* data){
    const person* p = (const person*)data;
    return map_function((person*)p);
}

unsigned short person_where_function(const void* data){
    const person* p = (const person*)data;
    return age_verification((person*)p);
}

void person_print(const void* data){
    const person* p = (const person*)data;
    char* full_name = get_full_name((person*)p);

    printf("ФИО: %s", full_name);

    free(full_name);
}

typeinfo* get_person_typeinfo(){
    if (PERSON_TYPEINFO == NULL){
        PERSON_TYPEINFO = (typeinfo*)malloc(sizeof(typeinfo));
        PERSON_TYPEINFO->size = sizeof(person);
        PERSON_TYPEINFO->map = person_map_function;
        PERSON_TYPEINFO->where = person_where_function;
        PERSON_TYPEINFO->print = person_print;
    }
    return PERSON_TYPEINFO;
}