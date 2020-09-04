#include<stdio.h>
#include<string.h>
#define MAX 30
char a[MAX] , lower[MAX] ;
int k=0 , m=0 ;
void recursive_func(char *arr , int i , int j){
    if(j<i) return ;

    if(arr[i] >= 'A' && arr[i] <= 'Z'){ 
        a[k] = arr[i];
        k++ ;
        recursive_func(arr,++i,j);
        return ;
    }
    else{
        lower[m] = arr[i];
        m++ ;
        recursive_func(arr,++i,j);
        return ;
    }
}
int main(int argc , char *argv[]){
      if(argc != 2) {
        fprintf(stderr,"enter a string in the command line\n");
        return 1;
    }
    int n ;
    n = strlen(argv[1]);
    recursive_func(argv[1] , 0 , n-1);
    strcat(a,lower);
    printf("[+] THE OUTPUT IS %s\n",a);
    return 0 ;
}
