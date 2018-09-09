#include <stdio.h> 
 #include <time.h> 
 int main(){ clock_t start, end;start=clock(); asm volatile("mov $10, %ebx;"); end=clock(); double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; printf(" \n %lf sec for line  ",time_taken);}