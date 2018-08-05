#include "stdio.h"

int count = 5;

extern int count;

extern void showCount();

int main(){
	// count = 5;
	count++;
	showCount();
	printf("%d\n",count);
	return 0;
}