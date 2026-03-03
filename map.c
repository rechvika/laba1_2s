#include "map.h"

array* map(array* array, char* (*function)(person*)){
    array* map_array = create_array();
    
    for(unsigned int i = 0; i < array->size; i++){
        map_array[i] = function(array->element[i]);
    }

    return map_array;
}