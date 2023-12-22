#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool addUser;
    bool addGroup;
    bool deleteUser;
    bool deleteGroup;
} Permissions;

typedef struct {
    char* name;
    int id;
    Permissions permissions;
} Group;

typedef struct {
    char* username;
    char* password;
    int id;
    char* firstName;
    char* lastName;
    Permissions permissions;
    char* group;
    int groupid;
} User;

int main() {
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
    printf("\n1. Create user\n2. Login as guest\n> ");
    int choice;
    scanf("%d", &choice);
    return 0;
}
