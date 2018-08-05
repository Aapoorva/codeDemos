#include "stdio.h"

int count;

extern void showCount();

int main(){
	count ++;
	showCount();
	return 0;
}