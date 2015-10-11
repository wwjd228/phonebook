#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define ___cacheline_aligned __attribute__((align(64)))

/* original version */
typedef struct __PHONE_BOOK_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entry ___cacheline_aligned;

typedef struct __LAST_NAME {
    char lastName[MAX_LAST_NAME_SIZE];
    entry *data;
    struct __LAST_NAME *pNext;
} name ___cacheline_aligned;

typedef struct __NAME_HASH {
    name *pNamelist;
} hash ___cacheline_aligned;

name *findName(char lastname[], hash *list);
hash *append(char lastName[], hash *list);
#endif
