#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
int arr[MAX], top1 = -1 , top2 = MAX;


int push(){
    if (top1 == top2-1){
        printf("stack is full");
        return 1;
    }
    int n , ch;
    printf("enter a number :");
    scanf("%d",&n);
    printf("\n\nenter 1 to insert into stack 1 and enter 2 to insert into stack2 :");
    scanf("%d",&ch);
    if (ch == 1)
        arr[++top1] = n;
    else
        arr[--top2] = n;

    return 0;    
}

void pop(){
    int op , n;
    printf("\nenter 1 for stack1 to pop and enter 2 for stack2 to pop :");
    scanf("%d",&op);
    if(op == 1){
        if(top1 == -1){
            printf("stack underflow\n");
            return ;
        }
        n = arr[top1--];
        printf("%d is poped from stack1\n",n);

    }
    else
    {
        if(top2 == MAX){
            printf("stack underflow");
            return ;
        }
        n = arr[top2++];
        printf("%d is poped from stack2\n",n);

    }
}

void display(){
    int op , i ;
    char ch ;
    printf("\nenter 1 to display stack1 and 2 to display stack2 :");
    scanf("%d",&op);
    // flushing the input buffer
    while ((ch = getchar()) != '\n' && ch != EOF);
    if(op==1){
        if(top1 == -1) {
            printf("stack1 is empty");
            return ;
        }
        printf("[########STACK1##########]\n");

        for(i=top1;i>=0 ;i--) {
            printf("the elements are %d\n",arr[i]);
        }
        
    }
    else{
        if(top2==MAX){
            printf("stack2 is empty\n");
            return ;
        }
        printf("[########STACK2##########]\n");
        for(i=top2;i<MAX;i++){
            printf("the elements are %d\n",arr[i]);
        }
    }

}

void main(int argc , char *argv[])
{
    int option =0 ;
    do{
        printf("\n\n\t\t1: push operation\n\t\t2: pop operation\n\t\t3: display\n\t\t4: exit\n");
        printf("enter the options :");
        scanf("%d",&option);
        getchar();
        switch (option)
        {
        case 1: push();
            break;
        case 2 : pop();
            break;
        case 3 : display();
            break;
        default:
            printf("enter a valid option\n");
            break;
        }
    }while(option != 4 );

}


