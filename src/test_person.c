#include "test_person.h"
#include "person_typeinfo.h"

array* create_test_person(){

    typeinfo* person_type = get_person_typeinfo();

    array* test_array = create_array(5, person_type);
    
    person p1;
    p1.id.series = 1234;
    p1.id.number = 567890;
    strcpy(p1.first_name, "Спанчбоб");
    strcpy(p1.middle_name, "Паторикович");
    strcpy(p1.last_name, "Сквидвардов");
    p1.birth.year = 2000;
    strcpy(p1.birth.month, "Январь");
    p1.birth.date = 1;
    
    person p2;
    p2.id.series = 2345;
    p2.id.number = 678901;
    strcpy(p2.first_name, "Сенди");
    strcpy(p2.middle_name, "Пантриковна");
    strcpy(p2.last_name, "Сквидвордовна");
    p2.birth.year = 1995;
    strcpy(p2.birth.month, "Март");
    p2.birth.date = 15;
    
    person p3;
    p3.id.series = 3456;
    p3.id.number = 789012;
    strcpy(p3.first_name, "Сидор");
    strcpy(p3.middle_name, "Закусович");
    strcpy(p3.last_name, "Кальмарович");
    p3.birth.year = 2010;
    strcpy(p3.birth.month, "Июнь");
    p3.birth.date = 20;
    
    array_add(test_array, &p1);
    array_add(test_array, &p2);
    array_add(test_array, &p3);

    return test_array;
}