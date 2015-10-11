#include <stdlib.h>

#include "phonebook_opt.h"

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
