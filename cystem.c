#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    bool addUser;
    bool addGroup;
    bool deleteUser;
    bool deleteGroup;
} Permissions;

typedef struct
{
    char *name;
    int id;
    Permissions permissions;
} Group;

typedef struct
{
    char *username;
    char *password;
    int id;
    char *firstName;
    char *lastName;
    Permissions permissions;
    char *group;
    int groupid;
} User;

void createUser(User *user)
{
    printf("[CREATE USER]\n");
    printf("Username: ");
    scanf("%ms", &(user->username));
    printf("Password: ");
    scanf("%ms", &(user->password));
    printf("User %s created successfully!", user->username);
}

int userCount = 0;
int groupCount = 0;
User users[32];
Group groups[64];

void shell(User user);

void handle(char *cmd);

int main()
{
    char* banner = "                                                                                         .         .           \n"
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

    printf("%s", banner);

    while (1)
    {
        if (userCount == 0)
            printf("\n1. Create user\n2. Login as guest\n3. Exit\n> ");
        else
            printf("\n0. Login\n1. Create user\n2. Login as guest\n3. "
                   "Exit\n> ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("[LOGIN]\n");
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
            if (loggedin)
                shell(user);
            else
                printf("Please check your username or password!");
            break;
        case 1:
            createUser(&users[userCount]);
            userCount++;
            break;
        case 3:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("No such option! Try again.\n");
        }
    }
}

void shell(User user)
{
    while (1)
    {
        printf("> ");
        char *cmd;
        gets(cmd);
        handle(cmd);
    }
}

void handle(char *cmd)
{
}
