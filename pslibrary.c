/********************CS3733 Assignment 2 written by Supakjeera Thanapaisal************************/
// Scheduler algorithms for OS: fcfs,sjf,psjf,rr
// Compile: gcc main.c pslibrary.c -o out.o
// Run: out.o
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pslibrary.h"

#define READY  0
#define RUNNING  1
#define WAITING  2
#define DONE  3
static char stateChars[] = {'r','R','w',0};

/////////////////////////////////*First come First serve algorithm for scheduler*/////////////////////////////////
void fcfs(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2){
   //first come first serve
   int i;                               //i for next char
   int state1 = READY;                  //state of the process
   int state2 = READY;
   int cpuLeft1 = x1;                   //P1 CPU when x is out, z will replace
   int cpuLeft2 = x2;                   //P2 CPU when x is out, z will replace
   int ioLeft1 = y1;                    //P1 IO
   int ioLeft2 = y2;                    //P2 IO
   int w1 = 0;
   int w2 = 0;                          //waiting time
   
   for (i=0; (state1 != DONE) || (state2 != DONE); i++) { 
       
        /* running process completes its CPU burst -> check if the IO is also done*/
        if ((state1 == RUNNING) && (cpuLeft1== 0)) {
           //if the IO also done, then set it done and last string
           if (ioLeft1 == 0) {
              state1 = DONE;
              s1[i] = stateChars[state1];            
           }
           //else wait
           else
              state1 = WAITING;
        }  
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
           //if the IO also done, then set it done and last string
           if (ioLeft2 == 0) {
              state2 = DONE;
              s2[i] = stateChars[state2];          
           }
           //else wait
           else
              state2 = WAITING;
        }         

        // if waiting and IO is complete, set values the next CPU bursts                  
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
      
        //If both ready
        if ( (state1 == READY) && (state2 == READY)) {
            state1 = RUNNING;
        }  
        //handle one ready and CPU available
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  
      
        //insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        
        //decrement counts
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
        if (state1 == READY)
            w1++;
        if (state2 == READY)
            w2++;
   }    

   printf("\nscheduler fcfs:\n");
   pFunc(s1,s2,w1,w2,x1+z1+x2+z2);
}
/////////////////////////////////*Shortest next CPU burts algorithm for scheduler*/////////////////////////////////
void sjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2){
   //shortest next CPU burst
   int i;                               //i for next char
   int state1 = READY;                  //state of the process
   int state2 = READY;
   int cpuLeft1 = x1;                   //P1 CPU when x is out, z will replace
   int cpuLeft2 = x2;                   //P2 CPU when x is out, z will replace
   int ioLeft1 = y1;                    //P1 IO
   int ioLeft2 = y2;                    //P2 IO
   int w1 = 0;
   int w2 = 0;                          //waiting time
   
   for (i=0; (state1 != DONE) || (state2 != DONE); i++) { 
       
        /* running process completes its CPU burst -> check if the IO is also done*/
        if ((state1 == RUNNING) && (cpuLeft1== 0)) {
           //if the IO also done, then set it done and last string
           if (ioLeft1 == 0) {
              state1 = DONE;
              s1[i] = stateChars[state1];            
           }
           //else wait
           else
              state1 = WAITING;
        }  
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
           //if the IO also done, then set it done and last string
           if (ioLeft2 == 0) {
              state2 = DONE;
              s2[i] = stateChars[state2];          
           }
           //else wait
           else
              state2 = WAITING;
        }         

        // if waiting and IO is complete, set values the next CPU bursts                  
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
      
        //If both ready
        if ( (state1 == READY) && (state2 == READY)) {
            if(cpuLeft1 <= cpuLeft2 ){
                state1 = RUNNING;
            }else if(cpuLeft1 > cpuLeft2){
                state2 = RUNNING;
            }        
        }
        //handle one ready and CPU available
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  
      
        //insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
           s1[i] = stateChars[state1];
        if (state2 != DONE)
           s2[i] = stateChars[state2];
        
        //decrement counts
        if (state1 == RUNNING)
           cpuLeft1--;
        if (state1 == WAITING)
           ioLeft1--;
        if (state2 == RUNNING)
           cpuLeft2--;
        if (state2 == WAITING)
           ioLeft2--;
        if (state1 == READY)
            w1++;
        if (state2 == READY)
            w2++;

    
   }                                              
   
   printf("\nscheduler sjf:\n");
   pFunc(s1,s2,w1,w2,x1+z1+x2+z2);
}
/////////////////////////////////*Premptive Shortest next CPU burts algorithm for scheduler*///////////////////////
void psjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2){
   //preemptive shortest
   int i;                               //i for next char
   int state1 = READY;                  //state of the process
   int state2 = READY;
   int cpuLeft1 = x1;                   //P1 CPU when x is out, z will replace
   int cpuLeft2 = x2;                   //P2 CPU when x is out, z will replace
   int ioLeft1 = y1;                    //P1 IO
   int ioLeft2 = y2;                    //P2 IO
   int w1 = 0;
   int w2 = 0;                          //waiting time
   
   for (i=0; (state1 != DONE) || (state2 != DONE); i++) { 
       
        /* running process completes its CPU burst -> check if the IO is also done*/
        if ((state1 == RUNNING) && (cpuLeft1== 0)) {
           //if the IO also done, then set it done and last string
           if (ioLeft1 == 0) {
              state1 = DONE;
              s1[i] = stateChars[state1];            
           }
           //else wait
           else
              state1 = WAITING;
        }  
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
           //if the IO also done, then set it done and last string
           if (ioLeft2 == 0) {
              state2 = DONE;
              s2[i] = stateChars[state2];          
           }
           //else wait
           else
              state2 = WAITING;
        }         

        // if waiting and IO is complete, set values the next CPU bursts                  
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
      
        //If both ready
        if ( (state1 == READY) && (state2 == READY)) {
            if(cpuLeft1 <= cpuLeft2 ){
                state1 = RUNNING;
            }else if(cpuLeft1 > cpuLeft2){
                state2 = RUNNING;
            }        
        }
        //handle one ready and CPU available
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  

        //for psjf ONLY: if either one is running check less CPUburst 
        if((state1 == RUNNING) && (state2 == READY)){
            if (cpuLeft2 < cpuLeft1){
                state2 = RUNNING;
                state1 = READY;
            }
        }else if ((state2 == RUNNING) && (state1 == READY)){
            if (cpuLeft1 < cpuLeft2){
                state1 = RUNNING;
                state2 = READY;
            }
        }
        
        /***********************Do something after checking states***********************/
        //insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        
        //decrement counts
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
        if (state1 == READY)
            w1++;
        if (state2 == READY)
            w2++;

    
   } 
   printf("\nscheduler psjf:\n");
   pFunc(s1,s2,w1,w2,x1+z1+x2+z2);
}
/////////////////////////////////*round robin algorithm for scheduler*/////////////////////////////////
void rr(char *s1, char *s2, int q, int x1, int y1, int z1, int x2, int y2, int z2){
    
    //preemptive shortest
    int i;                               //i for next char
    int state1 = READY;                  //state of the process
    int state2 = READY;
    int cpuLeft1 = x1;                   //P1 CPU when x is out, z will replace
    int cpuLeft2 = x2;                   //P2 CPU when x is out, z will replace
    int ioLeft1 = y1;                    //P1 IO
    int ioLeft2 = y2;                    //P2 IO
    int qleft = q;                           //quantum remaining
    int w1 = 0;
    int w2 = 0;                          //waiting time 
    
    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
                                /* running process completes its CPU burst */
        /* running process completes its CPU burst -> check if the IO is also done*/
        if ((state1 == RUNNING) && (cpuLeft1== 0)) {
           //if the IO also done, then set it done and last string
           if (ioLeft1 == 0) {
              state1 = DONE;
              s1[i] = stateChars[state1];            
           }
           //else wait
           else
              state1 = WAITING;
        }  
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
           //if the IO also done, then set it done and last string
           if (ioLeft2 == 0) {
              state2 = DONE;
              s2[i] = stateChars[state2];          
           }
           //else wait
           else
              state2 = WAITING;
        }      
                                     /* running process has quantum expire */
        if ((state1 == RUNNING) && (qleft == 0) ) {
            qleft = q;
            state1 = READY;
            if(cpuLeft2 != 0)
                state2 = RUNNING;
        }  
        if ((state2 == RUNNING) && (qleft == 0) ) {
           qleft = q;
           state2 = READY;
           if(cpuLeft1 != 0)
                state1 = RUNNING;
        }  

                                                    
        // if waiting and IO is complete, set values the next CPU bursts                  
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
        
        
        //If both ready and reset quantum
        if ((state1 == READY) && (state2 == READY)) {
            state1 = RUNNING;
            qleft = q;
        }                              
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
            qleft = q;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
            qleft = q;
        }  
        
        
        
        /***********************Do something after checking states***********************/
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        

        //decrement counts
        qleft--;                   
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
        if (state1 == READY)
            w1++;
        if (state2 == READY)
            w2++;
   }      
   printf("\nscheduler rr:\n");
   pFunc(s1,s2,w1,w2,x1+z1+x2+z2);
}

/////////////////////////////////*print function, cal AVT and CPU utilization*/////////////////////////////////
void pFunc(char *s1, char *s2,int w1,int w2,int rNums){
   
	//declare
	double avg = 0.0;
    double cpuU = 0.0;
    int l1 = 0;
    int l2 = 0;
    l1 = strlen(s1);
    l2 = strlen(s2);
    
    //find avg
    avg = ((double)w1+(double)w2)/2;
    //determine bigger string and get CPU Util
    if (l1 > l2){
        cpuU = (double)rNums/l1;
    }else if (l1 < l2){
        cpuU = (double)rNums/l2;
    }
    
    printf("%s \n",s1);
    printf("%s \n",s2);
    printf("%d %d %.1lf %.5lf \n",w1,w2,avg,cpuU);

}
