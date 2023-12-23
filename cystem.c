#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "structures.h"

int userCount = 0;
int groupCount = 0;
User users[32];
Group groups[64];

int createUser(User *user) {
    printf("Username: ");
    scanf("%ms", &(user->username));
    printf("Password: ");
    char* pwd1;
    scanf("%ms", &pwd1);
    printf("Retype password: ");
    char* pwd2;
    scanf("%ms", &pwd2);
    if(strcmp(pwd1, pwd2) == 0) {
        user->password = pwd1;
    }
    else {
        printf("\033[31mPasswords don't match!\033[0m\n");
        return 0;
    }
    printf("First name: ");
    char buffer[100];
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
    if (buffer[0] != '\0') {
        user->firstName = malloc(strlen(buffer) + 1);
        strcpy(user->firstName, buffer);
    } else {
        user->firstName = NULL;
    }
    printf("Last name: ");
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
    if (buffer[0] != '\0') {
        user->lastName = malloc(strlen(buffer) + 1);
        strcpy(user->lastName, buffer);
    } else {
        user->lastName = NULL;
    }
    user->id = userCount;
    user->groupid = groupCount;
    user->permissions.addUser = true;
    user->permissions.addGroup = true;
    userCount++;
    printf("\033[32mUser %s created successfully!\033[0m\n", user->username);
    shell(*user);
}

int main() {
    char *banner = "                                                                                         .         .           \n"
                   "    ,o888888o.  `8.`8888.      ,8' d888888o. 8888888 8888888888 8 8888888888            ,8.       ,8.          \n"
                   "   8888     `88. `8.`8888.    ,8'.`8888:' `88.     8 8888       8 8888                 ,888.     ,888.         \n"
                   ",8 8888       `8. `8.`8888.  ,8' 8.`8888.   Y8     8 8888       8 8888                .`8888.   .`8888.        \n"
                   "88 8888            `8.`8888.,8'  `8.`8888.         8 8888       8 8888               ,8.`8888. ,8.`8888.       \n"
                   "88 8888             `8.`88888'    `8.`8888.        8 8888       8 888888888888      ,8'8.`8888,8^8.`8888.      \n"
                   "88 8888              `8. 8888      `8.`8888.       8 8888       8 8888             ,8' `8.`8888' `8.`8888.     \n"
                   "88 8888               `8 8888       `8.`8888.      8 8888       8 8888            ,8'   `8.`88'   `8.`8888.    \n"
                   "`8 8888       .8'      8 8888   8b   `8.`8888.     8 8888       8 8888           ,8'     `8.`'     `8.`8888.   \n"
                   "   8888     ,88'       8 8888   `8b.  ;8.`8888     8 8888       8 8888          ,8'       `8        `8.`8888.  \n"
                   "    `8888888P'         8 8888    `Y8888P ,88P'     8 8888       8 888888888888 ,8'         `         `8.`8888. \n";

    printf("\033[33m%s\033[0m\n", banner);
    while (1) {
        if (userCount == 0)
            printf("1. Create user\n2. Login as guest\n3. Exit\n> ");
        else
            printf("0. Login\n1. Create user\n2. Login as guest\n3. "
                   "Exit\n> ");
        int choice;
        fflush(stdin);
        scanf("%d", &choice);
        switch (choice) {
            case 0: {
                User user;
                printf("Username: ");
                scanf("%ms", &user.username);
                printf("Password: ");
                scanf("%ms", &user.password);
                int i = 0;
                bool loggedin = false;
                while (i < userCount && !loggedin) {
                    loggedin = (strcmp(users[i].username, user.username) == 0) &&
                               (strcmp(users[i].password, user.password) == 0);
                    i++;
                }
                if (loggedin) {
                    printf("Welcome, %s!\n", user.username);
                    shell(user);
                } else
                    printf("\033[31mPlease check your username or password!\033[0m\n");
                break;
            }
            case 1:
                createUser(&users[userCount]);
                break;
            case 2: {
                User guest;
                guest.username = "guest";
                guest.id = -1;
                guest.groupid = -1;
                printf("Welcome, %s!\n", guest.username);
                shell(guest);
                break;
            }
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("\033[31mNo such option! Try again.\033[0m\n");
        }
    }
}
