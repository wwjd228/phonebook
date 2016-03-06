#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include "phonebook_opt.h"

extern pthread_mutex_t mutexsum;

/* FILL YOUR OWN IMPLEMENTATION HERE! */
static inline unsigned getindex( char name[] )
{
    /* compute the index */
    unsigned index = 0;
    unsigned i = 0;
    while ( name[i] ) {
        index += name[i];
        i++;
    }

    return (index % 26);
}

name *findName(char lastname[], hash *list)
{
    /* TODO: implement */
    unsigned index = getindex(lastname);
    name *pHead = list[index].pNamelist;
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

hash *append(char lastName[], hash *list)
{
    /* allocate memory for the new entry and put lastName */
    unsigned index = getindex( lastName );
    name *e = (name *) malloc(sizeof(name));
    strcpy(e->lastName, lastName);
    e->pNext = list[index].pNamelist;
    list[index].pNamelist = e;

    return list;
}

void import(void *arg)
{
    int i = 0;
    char line[MAX_LAST_NAME_SIZE];
    pthread_mutex_lock(&mutexsum);
    while (fgets(line, sizeof(line), ((threadArg *)arg) ->fp)) {
        while (line[i] != '\0')
            i++;
        line[i - 1] = '\0';
        i = 0;
        ((threadArg *)arg) ->e = append(line, ((threadArg *)arg) ->e);
    }
    pthread_mutex_unlock(&mutexsum);

    pthread_exit((void *) 0);
}
