#include <stdio.h>

void swap_ptr(char **p1, char **p2){

	char* temp = NULL;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
