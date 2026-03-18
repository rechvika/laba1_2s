#include "map.h"

array* map(array* arr, char* (*function)(person*)){
    array* map_array = create_array(arr->size, arr->typeinfo);
    
    for(unsigned int i = 0; i < arr->size; i++){
        void* elem = (char*)arr->element +(i * arr->typeinfo->size);
        char* result = function(elem);
        array_add(map_array, (person*)result);
    }

    return map_array;
}