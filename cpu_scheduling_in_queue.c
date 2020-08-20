#include<stdio.h>
#include<string.h>
#define MAX 5
/* AUTHOR TH3H04X */

void calculate_waiting_time(int bt[],int wt[],int service_time[],int arrival_time[])
{
    int i;
    for(i=0;i<MAX;i++){
        wt[i] = 0 ;
        service_time[i] = 0;

    }
    //printf("hello %d %d\n",bt[0],arrival_time[1]);
 
    for(i=1;i<MAX;i++){

        service_time[i] = service_time[i-1] + bt[i-1];
        wt[i] = service_time[i] - arrival_time[i] ;
        if(wt[i] < 0){
            wt[i] = 0;
        }

    }
}

void turn_around_time(int bt[] , int wt[],int tat[]){
    int i;
    for(i=0;i<MAX;i++){
        tat[i] = bt[i] + wt[i];
    }
}

int main(int argc , char *argv[])
{
    int bt[MAX] , wt[MAX] , tat[MAX] ,service_time[MAX], arrival_time[MAX],i , total_turnaround_time = 0 , total_waiting_time = 0;
    char c;
    for(i=0;i<MAX;i++){
        printf("\nENTER THE %d PROCESSOR BLASTING TIME AND ARRIVAL TIME :",i);
        scanf("%d %d",&bt[i],&arrival_time[i]);
        //clearing the input buffer
        while((c= getchar())!= '\n' && c != EOF);
        
    }
   
    calculate_waiting_time(bt , wt ,service_time,arrival_time);
    turn_around_time(bt,wt,tat);

    printf("PROCESSORS\tWAITING TIME\tTURN AROUND TIME\n\n");  

    for(i=0;i<MAX;i++){
        total_turnaround_time = total_turnaround_time + tat[i];
        total_waiting_time = total_waiting_time + wt[i];
        printf("  %d\t\t %d \t\t %d\n",i+1,wt[i],tat[i]);

        
    }
    float t = (float)total_turnaround_time/(float)MAX ;
    float w = (float)total_waiting_time/(float)MAX ;
    printf("\nTOTAL WORKING TIME    -------> %0.3f\n",w);
    printf("\nTOTAL TURN AROUND TIME -------> %0.3f\n",t);
    

    return 0 ;
}
