#include <stdio.h>

#include "New.h"
#include "Object.h"
#include "Set.h"

int main(){

	void *s = new(Set);
	printHeapState();

	void *a = add(s, new(Object));
	printHeapState();

	void *b = add(s, new(Object));
	printHeapState();

	void *c = new(Object);
	printHeapState();


	if(contains(s, a) && contains(s, b)){
		puts("ok");
		printHeapState();
	}

	if(contains(s, c)){
		puts("contains?");
		printHeapState();
	}

	if(differ(a, add(s, a))){
		puts("differ?");
		printHeapState();
	}

	if(contains(s, drop(s, a))){
		puts("drop?");
		printHeapState();
	}

	delete(drop(s, b));
	printHeapState();

	delete(drop(s, c));
	printHeapState();

	return 0;
}