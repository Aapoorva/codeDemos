#include "stdio.h"

int count = 10;

// using global variable(not static) of extern1main.c file
// extern is just reference to a global variable of some other file
// extern int count;

void showCount(){
	printf("%d\n",count);
}