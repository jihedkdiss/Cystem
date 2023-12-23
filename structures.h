#ifndef CYSTEM_STRUCTURES_H
#define CYSTEM_STRUCTURES_H

#include <stdbool.h>

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

#endif //CYSTEM_STRUCTURES_H
