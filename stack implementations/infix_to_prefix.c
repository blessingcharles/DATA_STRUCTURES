#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<ctype.h>
#include<stdlib.h>

struct node { 
	char data ; 
	struct node *next ; 
};
struct node *top = NULL ;
int isEmpty() 
{ 
	return top == NULL ; 
} 
char peek() 
{   char c = '\0';
	if(top == NULL){
        printf("stack underflow\n");
        return  c;
    }
    else return top->data ;
} 
char pop() 
{ 
    struct node *ptr;
    ptr = top ;
    char c = '\0';       
    if(top == NULL){
        printf("stack underflow\n");
        return c;
    }
    else{
        top = ptr->next ;
        return ptr->data ;
    }
} 
void push(char op) 
{ 
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = op;
    if(top == NULL){
         ptr->next = NULL ;
         top = ptr ;
    }
    else {
        ptr->next = top ;
        top = ptr ;
        }
} 

int Prec(char ch) 
{ 
	switch (ch) 
	{ 
	case '+' :
	case '-': 
		return 1; 
	case '/' :
	case '*': 
		return 2; 
	case '^': 
		return 3; 
	} 
	return -1; 
} 

char* infixToPostfix(char exp[]) 
{ 
	int i, k; 
	for (i = 0, k = -1; exp[i]; ++i) 
	{ 
		if (isalnum(exp[i])) 
			exp[++k] = exp[i]; 
		
		else if (exp[i] == '(') 
			push(exp[i]); 
	
		else if (exp[i] == ')') 
		{ 
			while (!isEmpty() && peek() != '(') 
				exp[++k] = pop(); 
			if (!isEmpty() && peek() != '(') 
				return NULL;			 
			else
				pop(); 
		} 
		else 
		{ 
			while (!isEmpty() && Prec(exp[i]) <= Prec(peek())) 
				exp[++k] = pop(); 
			push( exp[i]); 
		} 

	} 
	while (!isEmpty()) 
		exp[++k] = pop(); 

	exp[++k] = '\0'; 
	//printf( "%s\n\n", exp );
    return exp ;
} 
void reverse(char *s){
   int length, c;
   char *begin, *end, temp;
   length = strlen(s);
   begin  = s;
   end    = s;
 
   for (c = 0; c < length - 1; c++) end++;
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}
int main(int argc , char *argv[]) {	
	if(argc != 2) {
		fprintf(stderr,"\n<USAGE> ENTER ONLY ONE INFIX IN THE COMMAND LINE\n");	
		return 1;
	}
    char *str ;
	str = infixToPostfix(argv[1]); 
    printf("[+]POSTFIX ---> %s\n\n",str);
    //reversing the given input 
    reverse(argv[1]);
    str = infixToPostfix(str);
    reverse(str);
    printf("[+]PREFIX --->  %s\n\n",str);   
	return 0; 
} 
