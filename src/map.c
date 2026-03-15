#include "map.h"

array* map(array* arr, char* (*function)(person*)){
    array* map_array = create_array(arr->size);
    
    for(unsigned int i = 0; i < arr->size; i++){
        char* result = function(arr->element[i]);
        array_add(map_array, (person*)result);
    }

    return map_array;
}