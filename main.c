#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define ARRAY_SIZE 5

struct Application {
    int id;
    char name[BUFFER_SIZE];
    char company[BUFFER_SIZE];
    char date[BUFFER_SIZE];
    int status;
};

struct Application applications[ARRAY_SIZE] = {0};// array of structs, hold all the applications

// display main menu
void display_menu(void)
{
    printf("\n====== Job Application Tracker ======\n");
    printf("1. Add Application\n");
    printf("2. List Applications\n");
    printf("3. Update Status\n");
    printf("4. Delete Application\n");
    printf("5. Search / Filter\n");
    printf("6. Quit\n");
}

// get user input for the main menu
int get_user_input(void)
{
    int user_input;

    printf("Enter your choice: ");
    scanf("%d", &user_input);

    return user_input;
}

struct Application add_application(int counter)
{
    struct Application application;

    getchar();
    // set id
    application.id = counter;
    // get name
    printf("Enter the name: ");
    fgets(application.name, BUFFER_SIZE, stdin);
    application.name[strcspn(application.name, "\n")] = '\0';

    // get company
    printf("Enter the company: ");
    fgets(application.company, BUFFER_SIZE, stdin);
    application.company[strcspn(application.company, "\n")] = '\0';

    // get date
    printf("Enter the date: ");
    fgets(application.date, BUFFER_SIZE, stdin);
    application.date[strcspn(application.date, "\n")] = '\0';

    // get status
    printf("Enter the status: ");
    scanf("%d", &application.status);

    return application;
}

void list_applications(struct Application *applications, int counter)
{
    printf("\n================================\n");
    for (int i = 0; i < counter; i++) {
        printf("Id: %d\n", applications[i].id);
        printf("Name: %s\n", applications[i].name);
        printf("Company: %s\n", applications[i].company);
        printf("Date: %s\n", applications[i].date);
        printf("State: %d\n", applications[i].status);
    }
    printf("================================\n");
}

void update_application(struct Application applications[])
{
    int id, user_choice;


    printf("\n====== Update Application ======\n");

    printf("Enter the application id: ");
    scanf("%d", &id);

    if (id > (ARRAY_SIZE - 1) || id < 0) {
        printf("ID out of range!\n");
        return;
    }

    printf("\nWhat to update?\n");
    printf("1. Name\n");
    printf("2. Company\n");
    printf("3. Date\n");
    printf("4. Status\n");
    printf(">>> ");
    scanf("%d", &user_choice);

    getchar();
    switch (user_choice) {
        case 1:
            printf("Enter the new name: ");
            fgets(applications[id].name, BUFFER_SIZE, stdin);
            applications[id].name[strcspn(applications[id].name, "\n")] = '\0';
            break;
        case 2:
            printf("Enter the new company: ");
            fgets(applications[id].company, BUFFER_SIZE, stdin);
            applications[id].company[strcspn(applications[id].company, "\n")] = '\0';
            break;
        case 3:
            printf("Enter the new date: ");
            fgets(applications[id].date, BUFFER_SIZE, stdin);
            applications[id].date[strcspn(applications[id].date, "\n")] = '\0';
            break;
        case 4:
            printf("Enter the new status: ");
            scanf("%d", &applications[id].status);
        default:
            printf("Invalid input!");
    }

}

void delete_application(struct Application applications[], int counter)
{
   int id;

   printf("\n====== Delete Application ======\n");

   printf("Enter the id: ");
   scanf("%d", &id);

   if (id > counter || id < 0) {
       printf("ID out of range!\n");
       return;
   }


}

int main(void)
{
    int user_choice;
    int counter = 0;

    // main loop
    while (true) {
        // main menu
        display_menu();
        user_choice = get_user_input();

        switch (user_choice) {
            case 1:
                applications[counter] = add_application(counter);
                counter++;
                break;
            case 2:
            list_applications(applications, counter);
                break;
            case 3:
                update_application(applications);
                break;
            case 4:
                printf("Delete Application\n");
                break;
            case 5:
                printf("Search / Filter\n");
                break;
            case 6:
                printf("Quit\n");
                return 0;
            default:
                printf("Invalid Input");
        }
    }


    return 0;
}
