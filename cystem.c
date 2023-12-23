#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    bool addUser;
    bool addGroup;
    bool deleteUser;
    bool deleteGroup;
} Permissions;

typedef struct {
    char *name;
    int id;
    Permissions permissions;
} Group;

typedef struct {
    char *username;
    char *password;
    int id;
    char *firstName;
    char *lastName;
    Permissions permissions;
    char *group;
    int groupid;
} User;

int userCount = 0;
int groupCount = 0;
User users[32];
Group groups[64];

void createUser(User *user) {
    printf("[CREATE USER]\n");
    printf("Username: ");
    scanf("%ms", &(user->username));
    printf("Password: ");
    scanf("%ms", &(user->password));
    printf("First name: ");
    scanf("%ms", &(user->firstName));
    printf("Last name: ");
    scanf("%ms", &(user->lastName));
    user->id = userCount;
    user->groupid = groupCount;
    printf("User %s created successfully!", user->username);
}

int shell(User user) {
    while (1) {
        printf("> ");
        char cmd[50];
        fflush(stdin);
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';
        if (strcmp(cmd, "permissions") == 0) {
            printf("[PERMISSIONS]\n");
            if (user.permissions.addUser) printf("user.permissions.addUser [granted]\n");
            else printf("user.permissions.addUser [denied]\n");
            if (user.permissions.addGroup) printf("user.permissions.addGroup [granted]\n");
            else printf("user.permissions.addGroup [denied]\n");
            if (user.permissions.deleteUser) printf("user.permissions.deleteUserdeleteUser [granted]\n");
            else printf("user.permissions.deleteUser [denied]\n");
            if (user.permissions.deleteGroup) printf("user.permissions.deleteGroup [granted]\n");
            else printf("user.permissions.deleteGroup [denied]\n");
        } else if (strcmp(cmd, "logout") == 0) {
            printf("Goodbye, %s!", user.username);
            return 0;
        } else if (strcmp(cmd, "help") == 0) {
            printf("[HELP]\n");
            printf("help\t\t\tPrints a list of available commands.\n"
                   "permissions\t\t\tPrints the status of each permission within the logged user.\n"
                   "logout\t\t\tLogs out the current user.\n");
        } else {
            printf("Unknown command!\n");
            printf("Use 'help' for a list of available commands.\n");
        }
    }
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

    printf("%s", banner);

    while (1) {
        if (userCount == 0)
            printf("\n1. Create user\n2. Login as guest\n3. Exit\n> ");
        else
            printf("\n0. Login\n1. Create user\n2. Login as guest\n3. "
                   "Exit\n> ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 0: {
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
                if (loggedin) {
                    printf("Welcome, %s!\n", user.username);
                    shell(user);
                } else
                    printf("Please check your username or password!");
                break;
            }
            case 1:
                createUser(&users[userCount]);
                userCount++;
                break;
            case 2: {
                User guest;
                guest.username = "guest";
                guest.id = -1;
                guest.groupid = -1;
                printf("Welcome, %s!\n", guest.username);
                shell(guest);
            }
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("No such option! Try again.\n");
        }
    }
}
