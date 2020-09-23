#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pslibrary.h"

#define MAX_INDEX 10
#define MAX_SIZE 6*MAX_INDEX

int array[9][7] = {
	{3,8,7,3,6,3,2},
	{3,8,7,3,6,7,2},
	{4,8,7,3,6,1,2},
	{3,3,3,4,2,1,2},
	{3,3,2,3,2,1,2},
	{3,5,2,5,4,1,1},	
	{3,2,3,4,1,1,5},
	{3,2,3,4,1,4,1},
	{3,2,3,4,5,6,2}
};
	
	
	
int main(int argc, char** argv) {
	
	int i,j;
	char s1[MAX_SIZE];
	char s2[MAX_SIZE];
	int x1,x2,y1,y2,z1,z2;
        
	for(i = 0; i < 9; i++){
		
		
			
			x1 = array[i][1];
			y1 = array[i][2];
			z1 = array[i][3];
			x2 = array[i][4];
			y2 = array[i][5];
			z2 = array[i][6];

	                printf("Test %d: %d %d %d %d %d %d %d\n",i+1,array[i][0],x1,y1,z1,x2,y2,z2);	
			fcfs(s1,s2,x1,y1,z1,x2,y2,z2);
			//sjf(s1,s2,x1,y1,z1,x2,y2,z2);
			//psjf(s1,s2,x1,y1,z1,x2,y2,z2);
			//rr(s1,s2,x1,array[i][0],y1,z1,x2,y2,z2);
                        printf("\n");
	        	
	
	        	
	
	        	
	
	}
	
	
	
	return (EXIT_SUCCESS);
}
