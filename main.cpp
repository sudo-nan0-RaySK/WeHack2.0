#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <errno.h>
#include <iostream>
#include <time.h>
using namespace std;
char *readFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL; //could not open file

    code = (char*)malloc(1000);

    while ((c = fgetc(file)) != EOF)
    {
        code[n++] = (char) c;
    }


    code[n] = '\0';

    return code;
}

int main ( void )
{
    clock_t start, end;
    char c[300];
    start=clock();
    char* assembly= readFile("../assembly.txt");
    printf("%s \n",assembly);
    char* token =strtok(assembly,"\n");
    int i=0;
    while (token != NULL) {

        FILE *fptr= fopen("ext.c","w");
        if(fptr==NULL){
            printf("Not Found!");
        }

        char f[300]="#include <stdio.h> \n #include <time.h> \n int main(){ clock_t start, end;start=clock(); asm volatile(";
        char e[300]="); end=clock(); double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; printf(\" \\n %lf sec for line ";
        char g[300]=" \",time_taken);}";
        char in[100];
        //sprintf(in,"%d",i);
        //printf("%s \n",in);
        strcat(e,in);
        strcat(f,token);
        strcat(f,e);
        strcat(f,g);
        //++i;
        //free(in);
        fprintf(fptr,"%s", f);
        fclose(fptr);

        system("gcc ext.c");
        //system("./a.out");
        system("./a.out");

        printf("%d ",i);
        i++;

        token = strtok(NULL, "\n");
        end=clock();
        printf("at %lf \n",((double)(end-start))/CLOCKS_PER_SEC);
    }

}
