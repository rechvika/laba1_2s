#include "conclusion.h"

int conclusion(){
    char choice[10];
    int running = 1;
    array_errors error;

    printf("-------------------------------\n");
    printf("|      Выбор типа данных      |\n");
    printf("|-----------------------------|\n");
    printf("|                             |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|  +           1           +  |\n");
    printf("|  +        Person         +  |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|                             |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|  +           2           +  |\n");
    printf("|  +        Teachers       +  |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|                             |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|  +           3           +  |\n");
    printf("|  +        Students       +  |\n");
    printf("|  +++++++++++++++++++++++++  |\n");
    printf("|                             |\n");
    printf("|-----------------------------|\n");
    printf("|         Ваш выбор:          |\n");
    printf("-------------------------------\n");
    
    int type_choice;
    scanf("%d", &type_choice);
    getchar();
    
    array* persons = NULL;
    
    switch(type_choice){
        case 1:
            persons = create_test_person();
            printf("\n+++ Загружен массив Person +++\n");
            break;
        case 2:
            persons = create_test_teachers();
            printf("\n+++ Загружен массив Teachers +++\n");
            break;
        case 3:
            persons = create_test_students();
            printf("\n+++ Загружен массив Students +++\n");
            break;
        default:
            printf("Неверный выбор\n");
            return 1;
    }
    
    printf("+++ Выбери, что хочешь +++\n\n");
    
    while (running){
        show_buttons();
        
        printf("\nНажми нужную клавишу и Enter: ");
        scanf("%s", choice);
        
        printf("\n");

        if (strcmp(choice, "1") == 0){
            printf("+++ Вы выбрали получить серию паспорта +++\n");
            char* result = serialize_series(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "2") == 0){
            printf("+++ Вы выбрали получить номер паспорта +++\n");
            char* result = serialize_number(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "12") == 0){
            printf("+++ Вы выбрали получить id (серию и номер) +++\n");
            char* result = serialize_full_id(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "3") == 0){
            printf("+++ Вы выбрали получить имя +++\n");
            char* result = serialize_first_name(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "4") == 0){
            printf("+++ Вы выбрали получить фамилию +++\n");
            char* result = serialize_last_name(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "5") == 0){
            printf("+++ Вы выбрали получить отчество +++\n");
            char* result = serialize_middle_name(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "345") == 0){
            printf("+++ Вы выбрали получить ФИО +++\n");
            char* result = serialize_full_name(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "6") == 0){
            printf("+++ Вы выбрали получить год рождения +++\n");
            char* result = serialize_birth_year(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "7") == 0){
            printf("+++ Вы выбрали получить месяц рождения +++\n");
            char* result = serialize_birth_month(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "8") == 0){
            printf("+++ Вы выбрали получить день рождения +++\n");
            char* result = serialize_birth_date(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "678") == 0){
            printf("+++ Вы выбрали получить дату рождения +++\n");
            char* result = serialize_full_birth(persons, 0, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "17") == 0){
            printf("+++ Вы выбрали получить массив совершеннолетних людей +++\n");
            char* result = serialize_adults_list(persons, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "33") == 0){
            printf("+++ Вы выбрали получить массив имен людей +++\n");
            char* result = serialize_names_list(persons, &error);
            print_serialized(result, error);
        }
        else if (strcmp(choice, "exit") == 0){
            printf("Выход...\n");
            running = 0;
        }
        else{
            printf("+++ Ошибка: такой кнопки нет +++\n");
        }
        
        printf("\n");
    }
    
    free_array(persons);
    return 0;
}

void print_serialized(char* str, array_errors error){
    if (error == ARRAY_OPERATION_OK && str != NULL) {
        printf("%s\n", str);
        free(str);
    } else {
        printf("Ошибка: %d\n", error);
    }
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