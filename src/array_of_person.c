#include "array_of_person.h"

unsigned short get_series(person* person){
    return person->id.series;
}

unsigned short get_number(person* person){
    return person->id.number;
}

char* get_full_id (person* person){
    char* full_id = (char*)malloc(FULL_ID);

    sprintf(full_id, "%hu %hu", person->id.series, person->id.number);

    return full_id;
    
    free(full_id);
}



char* get_first_name(person* person){
    return person->first_name;
}

char* get_middle_name(person* person){
    return person->middle_name;
}

char* get_last_name(person* person){
    return person->last_name;
}

char* get_full_name (person* person){
    char* full_name = (char*)malloc(FULL_NAME);

    sprintf(full_name, "%c %c %c", person->first_name, person->middle_name, person->last_name);

    return full_name;
    
    free(full_name);
}



unsigned short get_birth_year(person* person){
    return person->birth.year;
}

char* get_birth_month(person* person){
    return person->birth.month;
}

unsigned short get_birth_date(person* person){
    return person->birth.date;
}

char* get_full_birth (person* person){
    char* full_birth = (char*)malloc(FULL_BIRTH);

    sprintf(full_birth, "%hu %c %hu", person->birth.year, person->birth.month, person->birth.date);

    return full_birth;
    
    free(full_birth);
}



array* create_array(){
    array* arrary_new = (array*)malloc(sizeof(array));

    array_new->capacity = array->capacity;
    array_new->size = 0;
    array_new->element = (person**)malloc(sizeof(person*) * array_new->capacity);

    return array_new;
}

void array_add(array* array, person* person){
    if (array->size >= array->capacity){
        array *= 2;
        array->element = (person**)realloc(array->element, sizeof(person*) * array->capacity);
    }
    array->size++;
    array->element[array->size] = person;
}

void free_array(array* array){
    free(array->element);
    free(array);
}



char* map_function(person* person){
    char* result = (char*)malloc(20);
    sprintf(result, "mapped_%s", person->first_name);
    return result;
}

char* map_function_2(person* person){
    char* result = (char*)malloc(20);
    sprintf(result, "mapped_%s", person->middle_name);
    return result;
}
