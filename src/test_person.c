#include "test_person.h"

array* create_test_person(){
    array_errors error;
    typeinfo* person_type = create_person_typeinfo();
    array* test_array = create_array(5, person_type, &error);
    if (test_array == NULL) return NULL;
    
    person_id id1 = {1234, 567890};
    birth_date birth1 = {2000, "Январь", 1};
    person* p1 = create_person(id1, "Спанчбоб", "Паторикович", "Сквидвардов", birth1);
    
    person_id id2 = {2345, 678901};
    birth_date birth2 = {1995, "Март", 15};
    person* p2 = create_person(id2, "Сенди", "Пантриковна", "Сквидвордовна", birth2);
    
    person_id id3 = {3456, 789012};
    birth_date birth3 = {2010, "Июнь", 20};
    person* p3 = create_person(id3, "Сидор", "Закусович", "Кальмарович", birth3);
    
    array_add(test_array, (person*)p1, NULL);
    array_add(test_array, (person*)p2, NULL);
    array_add(test_array, (person*)p3, NULL);
    
    return test_array;
}

array* create_test_teachers(){
    array_errors error;
    typeinfo* teacher_type = create_teacher_typeinfo();
    array* test_array = create_array(5, teacher_type, &error);
    if (test_array == NULL) return NULL;
    
    person_id id1 = {1111, 111111};
    birth_date birth1 = {1980, "Январь", 17};
    teacher* t1 = create_teacher(id1, "Грю", "Фулониус", "Сергеевич", birth1, "История гадкого я");
    
    person_id id2 = {2222, 222222};
    birth_date birth2 = {1975, "Март", 14};
    teacher* t2 = create_teacher(id2, "Лунтик", "Кузивич", "Шэршэроф", birth2, "История лунтика");
    
    person_id id3 = {3333, 333333};
    birth_date birth3 = {2020, "Июнь", 18};
    teacher* t3 = create_teacher(id2, "Крош", "Барашович", "Капатович", birth2, "История смешариков");

    array_add(test_array, (person*)t1, NULL);
    array_add(test_array, (person*)t2, NULL);
    array_add(test_array, (person*)t3, NULL);
    
    return test_array;
}

array* create_test_students(){
    array_errors error;
    typeinfo* student_type = create_student_typeinfo();
    array* test_array = create_array(5, student_type, &error);
    if (test_array == NULL) return NULL;
    
    person_id id1 = {1234, 567890};
    birth_date birth1 = {2005, "Февраль", 10};
    student* s1 = create_student(id1, "Вупсень", "Котиков", "Артемович", birth1, "Прикладные смашарики и гадкий я");
    
    person_id id2 = {2345, 678901};
    birth_date birth2 = {2006, "Апрель", 25};
    student* s2 = create_student(id2, "Пупсень", "Сабачиков", "Денисович", birth2, "Дизайн смешариков и лунтика");

    person_id id3 = {2345, 678901};
    birth_date birth3 = {2007, "май", 5};
    student* s3 = create_student(id3, "Пин", "Пинпонгович", "Петрович", birth3, "Низкоуровнивые смешарики и системы гадкого я");
    
    array_add(test_array, (person*)s1, NULL);
    array_add(test_array, (person*)s2, NULL);
    array_add(test_array, (person*)s3, NULL);
    
    return test_array;
}