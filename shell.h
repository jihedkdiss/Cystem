#include <stdio.h>
#include <string.h>
#include "structures.h"

int shell(User user) {
    while (1) {
        printf("%s$ ", user.username);
        char cmd[50];
        fflush(stdin);
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';
        if (strcmp(cmd, "permissions") == 0) {
            if (user.permissions.addUser) printf("user.permissions.addUser\t\033[32m[granted]\033[0m\n");
            else printf("user.permissions.addUser\t\033[31m[denied]\033[0m\n");
            if (user.permissions.addGroup) printf("user.permissions.addGroup\t\033[32m[granted]\033[0m\n");
            else printf("user.permissions.addGroup\t\033[31m[denied]\033[0m\n");
            if (user.permissions.deleteUser) printf("user.permissions.deleteUserdeleteUser\t\033[32m[granted]\033[0m\n");
            else printf("user.permissions.deleteUser\t\033[31m[denied]\033[0m\n");
            if (user.permissions.deleteGroup) printf("user.permissions.deleteGroup\t\033[32m[granted]\033[0m\n");
            else printf("user.permissions.deleteGroup\t\033[31m[denied]\033[0m\n");
        } else if (strcmp(cmd, "logout") == 0) {
            printf("Goodbye, %s!\n", user.username);
            return 0;
        } else if (strcmp(cmd, "help") == 0) {
            printf("help\t\tPrints a list of available commands.\n"
                   "permissions\tPrints the status of each permission within the logged user.\n"
                   "whoami\t\tPrints the current username.\n"
                   "passwd\t\tChange the current user password.\n"
                   "id\t\tPrints the current user id and group id.\n"
                   "about\t\tPrints out information about the software.\n"
                   "logout\t\tLogs out the current user.\n");
        } else if (strcmp(cmd, "about") == 0) {
            printf("\033[33mCystem - Nuclear operating system written in C - v0.1 - @jihedkdiss\033[0m\n");
        } else if (strcmp(cmd, "") == 0) {
            continue;
        } else if (strcmp(cmd, "whoami") == 0) {
            printf("%s\n", user.username);
        } else if (strcmp(cmd, "id") == 0) {
            printf("Username: %s ID: %d Group ID: %d\n", user.username, user.id, user.groupid);
        } else if (strcmp(cmd, "passwd") == 0) {
            printf("New password: ");
            char* pwd1;
            scanf("%ms", &pwd1);
            printf("Retype new password: ");
            char* pwd2;
            scanf("%ms", &pwd2);
            if(strcmp(pwd1, pwd2) == 0) {
                user.password = pwd1;
                printf("\033[32mPassword updated successfully!\033[0m\n");
            }
            else printf("\033[31mPasswords don't match!\033[0m\n");
        } else {
            printf("\033[31m%s: Unknown command!\033[0m\n", cmd);
            printf("Use (help) for a list of available commands.\n");
        }
    }
}