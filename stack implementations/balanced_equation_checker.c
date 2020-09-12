#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 50
int st[MAX];
int top = -1 ;
bool isEmpty(){
    return (top == -1)? true : false ;
}
bool isFull(){
    return (top == MAX-1)?true : false ;
}
void push(char c){
    if(isFull()) printf("stack is full");
    else st[++top] = c ;

}
void pop(){
    if(isEmpty()) printf("stack is empty\n");
    else top-- ;
}
char peek(){
    return st[top];
}
bool pair(char start,char end)
{
	if(start == '(' && end == ')') return true;
	else if(start == '{' && end == '}') return true;
	else if(start == '[' && end == ']') return true;
	return false;
}
void checker(char *arr , int  n){
    int i = 0;
    char c ;
    for( ; i<n ; i++){
        if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{') push(arr[i]);

        else if(arr[i] == ')' || arr[i] == ']' || arr[i] == '}'){
            c  = peek() ;
            if(isEmpty() || !(pair(c , arr[i]))){
                // return immediately if it is not a pair  
                printf("\nIT IS NOT A BALANCED EQUATION!\n");
                return ;
            }
            else{
                pop();
            }
        }
    }
    if(isEmpty()){
        printf("\nIT IS A BLANCED EQUATION!\n");
    }
    else{
        printf("\nIT IS NOT A BALANCED EQUATION!\n");
    }
}

int main(int argc , char **argv){
    if(argc != 2){
        fprintf(stderr,"<USAGE> enter a equation in the cmd line\n");
        return 1 ;
    }
    checker(argv[1],strlen(argv[1]));
    return 0;
}
