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
            printf("[PERMISSIONS]\n");
            if (user.permissions.addUser) printf("user.permissions.addUser\t\t[granted]\n");
            else printf("user.permissions.addUser\t\t[denied]\n");
            if (user.permissions.addGroup) printf("user.permissions.addGroup\t\t[granted]\n");
            else printf("user.permissions.addGroup\t\t[denied]\n");
            if (user.permissions.deleteUser) printf("user.permissions.deleteUserdeleteUser\t\t[granted]\n");
            else printf("user.permissions.deleteUser\t\t[denied]\n");
            if (user.permissions.deleteGroup) printf("user.permissions.deleteGroup\t\t[granted]\n");
            else printf("user.permissions.deleteGroup\t\t[denied]\n");
        } else if (strcmp(cmd, "logout") == 0) {
            printf("Goodbye, %s!\n", user.username);
            return 0;
        } else if (strcmp(cmd, "help") == 0) {
            printf("[HELP]\n");
            printf("help\t\t\tPrints a list of available commands.\n"
                   "permissions\t\tPrints the status of each permission within the logged user.\n"
                   "logout\t\t\tLogs out the current user.\n");
        } else if (strcmp(cmd, "") == 0) {
            continue;
        } else {
            printf("Unknown command!\n");
            printf("Use 'help' for a list of available commands.\n");
        }
    }
}