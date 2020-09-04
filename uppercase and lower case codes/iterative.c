#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc , char *argv[]){
    if(argc != 2) {
        fprintf(stderr,"enter a string in the command line\n");
        return 1;
    }
    int n, i =0 , j = 0, k =0 ;
    n = strlen(argv[1]);
    char *arr1 = (char *)malloc((n/2)*sizeof(char));
    char *arr = (char *)malloc(n*sizeof(char));
    for( ;i<n;i++){
        if (argv[1][i] >= 'A' && argv[1][i] <= 'Z'){
            arr[j] = argv[1][i];
            j++ ;
        }
        else{
            arr1[k] = argv[1][i];
            k++ ;
        }
    }
    strcat(arr,arr1);
    printf("[+]THE STRING IS %s\n",arr);
    free(arr);
    free(arr1);
    return 0 ;
}
