#include <locale.h>
#include "array_of_person.h"
#include "concatenation.h"
#include "map.h"
#include "where.h"
#include "test_person.h"
#include "person_typeinfo.h"
#include "array_errors.h"

void show_buttons(void);

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    char choice;
    int running = 1;
    array_errors error;

    array* persons = create_test_person();

    printf("+++ Выбери, что хочешь +++\n\n");

    while (running){
        show_buttons();

        printf("\nНажми нужную клавишу и Enter");
        scanf(" %c", &choice);

        printf("\n");

        switch(choice){
            case '1':
                printf("+++ Вы выбрали получить серию паспорта +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("Серия паспорта: %u\n", get_series(&persons->element[0]), &error);
                } else{
                    printf("Ошибка получения серии: %d\n", error);
                }
                break;

            case '2':
                printf("+++ Вы выбрали получить номер паспорта +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("Номер паспорта: %u\n", get_number(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '12':
                printf("+++ Вы выбрали получить id (серию и номер) +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("id: %s\n", get_full_id(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '3':
                printf("+++ Вы выбрали получить имя +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("Имя: %s\n", get_first_name(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '4':
                printf("+++ Вы выбрали получить фамилию +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("Фамилия: %s\n", get_middle_name(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '5':
                printf("+++ Вы выбрали получить отчество +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("Отчество: %s\n", get_last_name(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '345':
                printf("+++ Вы выбрали получить ФИО +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("ФИО: %s\n", get_full_name(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '6':
                printf("+++ Вы выбрали получить год рождения +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("Год: %u\n", get_birth_year(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                } // переписать чтобы выводились строки
                break;

            case '7':
                printf("+++ Вы выбрали получить месяц рождения +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("Месяц: %s\n", get_birth_month(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '8':
                printf("+++ Вы выбрали получить день рождения +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("День: %u\n", get_birth_date(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '678':
                printf("+++ Вы выбрали получить дату рождения +++\n");
                if (error == ARRAY_OPERATION_OK){
                    printf("Дата рождения: %s\n", get_full_birth(&persons->element[0]), &error);
                } else {
                    printf("Ошибка получения номера: %d\n", error);
                }
                break;

            case '17':
                printf("+++ Вы выбрали получить массив совершеннолетних людей +++\n");

                array* age_person = where(persons, age_verification, &error);

                if (error == ARRAY_OPERATION_OK && age_person != NULL) {
                    printf("Найдено совершеннолетних: %u\n", age_person->size);
                    
                    for (unsigned int i = 0; i < age_person->size; i++) {
                        person* p = (person*)((char*)age_person->element + (i * age_person->typeinfo->size));
                        char* full_name = get_full_name(p, &error);
                        if (error == ARRAY_OPERATION_OK && full_name != NULL) {
                            printf("%d. %s\n", i + 1, full_name);
                            free(full_name);
                        }
                    }
                    
                    free_array(age_person);
                } else {
                    printf("Ошибка получения массива: %d\n", error);
                }
                break;

            case '33':
                printf("+++ Вы выбрали получить массив имен людей +++\n");

                printf("Имена в массиве:\n");
                for (unsigned int i = 0; i < persons->size; i++) {
                    person* p = (person*)((char*)persons->element + (i * persons->typeinfo->size));
                    char* first_name = get_first_name(p, &error);
                    if (error == ARRAY_OPERATION_OK && first_name != NULL) {
                        printf("%d. %s\n", i + 1, first_name);
                    }
                }
                break;
    
            default:
                printf("+++ Ошибка: такой кнопки нет +++\n", choice);
                printf("Нажми Enter, чтобы продолжить");
                getchar();
                break;
            }
            printf("\n");
        }

    return 0;
}

void show_buttons(void){
    printf("-------------------------------\n");
    printf("|     Достыпные   функции     |\n");
    printf("|-----------------------------|\n");
    printf("|                             |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|  +           1           +  |\n");
    printf("|  +Получить серию паспорта+  |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|                             |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|  +           2           +  |\n");
    printf("|  +Получить номер паспорта+  |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|                             |\n");
    printf("|        +++++++++++++        |\n");
    printf("|        +     12    +        |\n");
    printf("|        +Получить id+        |\n");
    printf("|        +++++++++++++        |\n");
    printf("|                             |\n");
    printf("|       +++++++++++++++       |\n");
    printf("|       +      3      +       |\n");
    printf("|       +Получить  имя+       |\n");
    printf("|       +++++++++++++++       |\n");
    printf("|                             |\n");
    printf("|     +++++++++++++++++++     |\n");
    printf("|     +        4        +     |\n");
    printf("|     +Получить  фамилию+     |\n");
    printf("|     +++++++++++++++++++     |\n");
    printf("|                             |\n");
    printf("|     +++++++++++++++++++     |\n");
    printf("|     +        5        +     |\n");
    printf("|     +Получить отчество+     |\n");
    printf("|     +++++++++++++++++++     |\n");
    printf("|                             |\n");
    printf("|       +++++++++++++++       |\n");
    printf("|       +     345     +       |\n");
    printf("|       +Получить  ФИО+       |\n");
    printf("|       +++++++++++++++       |\n");
    printf("|                             |\n");
    printf("|   +++++++++++++++++++++++   |\n");
    printf("|   +          6          +   |\n");
    printf("|   +Получить год рождения+   |\n");
    printf("|   +++++++++++++++++++++++   |\n");
    printf("|                             |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|  +           7           +  |\n");
    printf("|  +Получить месяц рождения+  |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|                             |\n");
    printf("|   ++++++++++++++++++++++++  |\n");
    printf("|   +          8           +  |\n");
    printf("|   +Получить день рождения+  |\n");
    printf("|   ++++++++++++++++++++++++  |\n");
    printf("|                             |\n");
    printf("|   ++++++++++++++++++++++++  |\n");
    printf("|   +         678          +  |\n");
    printf("|   +Получить дату рождения+  |\n");
    printf("|   ++++++++++++++++++++++++  |\n");
    printf("|                             |\n");
    printf("| +++++++++++++++++++++++++++ |\n");
    printf("| +           17            + |\n");
    printf("| +Получить массив людей >17+ |\n");
    printf("| +++++++++++++++++++++++++++ |\n");
    printf("|                             |\n");
    printf("|+++++++++++++++++++++++++++++|\n");
    printf("|+            33             +|\n");
    printf("|+Получить  массив имен людей+|\n");
    printf("|+++++++++++++++++++++++++++++|\n");
    printf("|                             |\n");
    printf("|-----------------------------|\n");
    printf("|            Всё              |\n");
    printf("-------------------------------\n");
}