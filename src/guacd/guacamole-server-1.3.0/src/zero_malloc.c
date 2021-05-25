#include <stdio.h>
#include <stdlib.h>

void* _zero_malloc(int size)
{
	void* ptr = malloc(size);
	if (ptr == (void *)0) return (void*)0;
	memset(ptr, 0, size);
	return ptr;
}

