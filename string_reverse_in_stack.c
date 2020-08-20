#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

char stack_str[MAX] ;
int top = -1 ;
void push(char c)
{
	if(top == (MAX-1)){
		printf("STACK OVERFLOW\n");
		exit(1);
	}
	printf("%c",c);
	stack_str[++top] = c ;
}
char pop()
{
	if(top == -1)
	{
		printf("STACK UNDERFLOW\n");
		exit(1);
	}
	return stack_str[top--];

}
int main(int argc , char *argv[])
{
	char str[MAX] , initial_str[MAX];
        int i , flag = 1 ;
	printf("ENTER A STRING :");
	gets(str);
	for(i=0 ;i<strlen(str); i++ )
	{
		push(str[i]);
		initial_str[i] = str[i] ;
	}
	for(i=0;i<strlen(str);i++)
	{
		str[i] = pop();
		if(initial_str[i] != str[i] )
			flag = 0 ;
	}
	if(flag) printf("the reversed string is %s and is a palindrome string\n" , str);
	else printf("the reversed string is %s and is not a palindrome\n",str);

	return 0;
}

