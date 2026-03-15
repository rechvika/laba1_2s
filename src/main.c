#include "array_of_person.c"
#include "concatenation.c"
#include "map.c"
#include "where.c"
#include "array_of_person.h"
#include "concatenation.h"
#include "map.h"
#include "where.h"

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    char choice;
    int running = 1;

    printf("+++ Выбери, что хочешь +++\n\n");

    while (running){
        show_buttons();

        printf("\nНажми нужную клавишу и Enter");
        scanf("%c", &choice);
        clean_input();

        printf("\n");

        switch(choice){

            case '1':
                printf("+++ Вы выбрали получить серию паспорта +++\n");
                person person;
                printf("Серия паспорта: %u\n", get_series(&person));
                break;

            case '2':
                printf("+++ Вы выбрали получить номер паспорта +++\n");
                person person;
                printf("Номер паспорта: %u\n", get_number(&person));
                break;

            case '12':
                printf("+++ Вы выбрали получить id (серию и номер) +++\n");
                person person;
                printf("id: %c\n", get_full_id(&person));
                break;

            case '3':
                printf("+++ Вы выбрали получить имя +++\n");
                person person;
                printf("Имя: %c\n", get_first_name(&person));
                break;

            case '4':
                printf("+++ Вы выбрали получить фамилию +++\n");
                person person;
                printf("Фамилия: %c\n", get_middle_name(&person));
                break;

            case '5':
                printf("+++ Вы выбрали получить отчество +++\n");
                person person;
                printf("Отчество: %c\n", get_last_name(&person));
                break;

            case '345':
                printf("+++ Вы выбрали получить ФИО +++\n");
                person person;
                printf("ФИО: %c\n", get_full_name(&person));
                break;

            case '6':
                printf("+++ Вы выбрали получить год рождения +++\n");
                person person;
                printf("Год: %u\n", get_birth_year(&person));
                break;

            case '7':
                printf("+++ Вы выбрали получить месяц рождения +++\n");
                person person;
                printf("Месяц: %c\n", get_birth_month(&person));
                break;

            case '8':
                printf("+++ Вы выбрали получить день рождения +++\n");
                person person;
                printf("День: %u\n", get_birth_date(&person));
                break;

            case '678':
                printf("+++ Вы выбрали получить дату рождения +++\n");
                person person;
                printf("Дата рождения: %c\n", get_full_birth(&person));
                break;

            case '17':
                printf("+++ Вы выбрали получить массив совершеннолетних людей +++\n");
                person person;
                array* array;

                array* age_person = (array*)malloc(array->size);
                strcpy(age_person, where(array* array, unsigned short (*age_verification)(person*)));
                char* age_person_2;

                printf("Массив совершеннолетних людей: %c\n", age_person);
                free(age_person);
                break;

            case '33':
                printf("+++ Вы выбрали получить массив имен людей +++\n");
                array* array;
                person person;

                array* name_array = (array*)malloc(array->size);
                strcpy(name_array, map(array* array, char* (*map_function)(person*)));
                char* name_array_2;
                
                printf("Массив имен людей: %c\n", name_array_2);
                free(name_array);
                break;
            case '34':
                printf("+++ Вы выбрали получить массив сначала имен потом фамилий людей +++\n");
                array* array;
                person person;

                array* name_array = (array*)malloc(array->size);
                array* middle_array = (array*)malloc(array->size);
                array* full_array = (array*)malloc(array->size);
                full_array = concatenation(array* name_array, array* middle_array);
                
                char* full_array_2
                
                strcpy(full_array_2, full_array);
                printf("Массив имен затем фамилий людей: %c\n", full_array_2);

                free(name_array);
                free(middle_array);
                free(full_array);
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
    printf("|+++++++++++++++++++++++++++++|\n");
    printf("|+            34             +|\n");
    printf("|+Получить массив имена, фам.+|\n");
    printf("|+++++++++++++++++++++++++++++|\n");
    printf("|                             |\n");
    printf("|-----------------------------|\n");
    printf("|            Всё              |\n");
    printf("-------------------------------\n");
}