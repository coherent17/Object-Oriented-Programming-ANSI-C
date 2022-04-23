#include <stdio.h>

#include "New.h"
#include "Object.h"
#include "Set.h"

int main(){

	void *s = new(Set);
	printHeapState();
	//heap = [0 ,10 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0];
	//new a set at heap[1], and mark as MANY (define in Set.c)

	void *a = add(s, new(Object));
	printHeapState();
	//heap = [0 ,10 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0];
	//new an object and put it into set s, and mark as (set_pointer - reference_pointer) (&heap[1] - &heap[0])


	void *b = add(s, new(Object));
	printHeapState();
	//heap = [0 ,10 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0];
	//new an object and put it into set s, and mark as (set_pointer - reference_pointer) (&heap[1] - &heap[0])

	void *c = new(Object);
	printHeapState();
	//heap = [0 ,10 ,1 ,1 ,10 ,0 ,0 ,0 ,0 ,0];
	//new an object but didn't assign to any set, mark as MANY

	if(contains(s, a) && contains(s, b)){
		puts("ok");
	}

	if(contains(s, c)){
		puts("contains?");
	}

	if(differ(a, add(s, a))){
		puts("differ?");
	}

	if(contains(s, drop(s, a))){
		puts("drop?");
		printHeapState();
	}

	delete(drop(s, b));
	printHeapState();
	//heap = [0 ,10 ,10 ,0 ,10 ,0 ,0 ,0 ,0 ,0];
	//delete b from the heap and mark as 0

	delete(drop(s, c));
	printHeapState();
	//heap = [0 ,10 ,10 ,0 ,10 ,0 ,0 ,0 ,0 ,0];
	//since c doesn't affiliate to set, so it won't be remove in the heap, and still mark as MANY

	return 0;
}