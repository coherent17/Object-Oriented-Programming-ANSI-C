#include <stdio.h>
#include <assert.h>

#include "Set.h"
#include "New.h"
#include "Object.h"

const void *Set;
const void *Object;

#if ! defined MANY || MANY < 1
#define MANY 10
#endif

//static: initialize the elements in heap to zero 
static int heap [MANY];


//find a empty place in the heap, and mark as MANY, and return the pointer to that index
void *new(const void *type, ...){
	int *p;

	//using heap[0] as a reference, in add function will specified which set to add in
	for(p = heap + 1; p < heap + MANY; ++p){
		if(! *p) break;
	}
	assert(p < heap + MANY);
	*p = MANY;
	return p;
}

//delete the occupied state in heap, set the _item(a pointer to the heap index) that index to 0
void delete(void *_item){
	int *item = _item;
	if(item){
		assert(item > heap && item < heap + MANY);
		*item = 0;
	}
}

//add an element into the set, and return the address in the heap of element
void *add(void *_set, const void *_element){
	int *set = _set;
	const int *element = _element;

	assert(set > heap && set < heap + MANY);
	assert(*set == MANY);
	assert(element > heap && element < heap + MANY);

	//affiliate the element to the specific set by using the set address - reference address (heap[0])
	if(*element == MANY)
		*(int *) element = set - heap;
	else
		assert(*element == set - heap);

	return (void *) element;
}

//check if the element is in the set
void *find(const void *_set, const void * _element){
	const int *set = _set;
	const int *element = _element;

	assert(set > heap && set < heap + MANY);
	assert(*set == MANY);
	assert(element > heap && element < heap + MANY);
	assert(*element);

	return *element == set - heap ? (void *) element : 0;
}

//turn the find output to the truth value
int contains(const void *_set, const void *_element){
	return find(_set, _element) != 0;
}

//remove an element in the set, but still remain in the heap
void *drop(void *_set, const void *_element){
	int *element = find(_set, _element);

	if(element)
		*element = MANY;
	return element;
}

//simply compare the pointer is same or not
int differ(const void *a, const void *b){
	return a != b;
}

void printHeapState(){
	for(int i = 0; i < MANY; i++){
		printf("%d ,", heap[i]);
	}
	printf("\n");
}