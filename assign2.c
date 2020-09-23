/********************CS3733 Assignment 2 written by Supakjeera Thanapaisal************************/
// main file for Scheduler algorithms for OS: fcfs,sjf,psjf,rr
// Compile: gcc assign2.c pslibrary.c -o out.o
// Run: out.o
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pslibrary.h"


int main(int argc, char** argv) {
    int numArg = argc-1;
    int i;
    int q,x1,y1,z1,x2,y2,z2;
    char s1[MAX_SIZE];
    char s2[MAX_SIZE];
    char *p;
	
	//check num of args or print and assign values
    if(numArg != 7){
        printf("ERROR: Incorrect number of arguments");
        exit(101);
    }else{
        printf("Assignment 2 program was written by Supakjeera Thanapaisal \n"); 
        for(i=1; i <= numArg; i++){
            printf("%s ",argv[i]);
        }
        printf("\n");
		//convert str from argv to int base 10 using string.h lib
        q = strtol(argv[1], &p, 10);
        x1 = strtol(argv[2], &p, 10);
        y1 = strtol(argv[3], &p, 10);
        z1 = strtol(argv[4], &p, 10);
        x2 = strtol(argv[5], &p, 10);
        y2 = strtol(argv[6], &p, 10);
        z2 = strtol(argv[7], &p, 10);
    }
    
	//call 4 algorithms
    fcfs(s1,s2,x1,y1,z1,x2,y2,z2);
    sjf(s1,s2,x1,y1,z1,x2,y2,z2);
    psjf(s1,s2,x1,y1,z1,x2,y2,z2);
    rr(s1,s2,q,x1,y1,z1,x2,y2,z2);
    
    return (EXIT_SUCCESS);
}

