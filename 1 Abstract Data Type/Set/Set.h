#ifndef SET_H
#define SET_H

extern const void *Set;

//using const void * so that the poniter can point to any type, 
//but we can't change the object that point to because of "const"
void *add(void *set, const void *element);
void *find(const void *set, const void *element);
void *drop(void *set, const void *element);
int contains(const void *set, const void *element);
void printHeapState();

#endif