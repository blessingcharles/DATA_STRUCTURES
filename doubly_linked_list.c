#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *start = NULL;
node *create(){
    node *ptr , *new_node ;
    int n ;
    char buff ;
    printf("\nenter a number : ");
    scanf("%d",&n);
    while((buff=getchar()!= '\n') && buff != EOF);

    while(n != 0){
        new_node = (node *)malloc(sizeof(node));
        if (start == NULL)
        {
            start = new_node;
            new_node->data = n;
            new_node->next = new_node->prev = NULL ;
        }
        else
        {
            ptr = start ;
            while(ptr->next != NULL) ptr = ptr->next ;

            ptr->next = new_node ;
            new_node->prev = ptr ;
            new_node->data = n ;
            new_node->next = NULL;
        }
        
    printf("\nenter a number or 0 to exit : ");
    scanf("%d",&n); 
    while((buff=getchar()!= '\n') && buff != EOF); 
    }   
    return start ; 
}

node *display(){

    node *ptr ;
    ptr = start ;
    if(ptr == NULL){
        printf("nothing to display \n");
        return start ;
    }
    while(ptr != NULL){
        printf("the data is %d\n",ptr->data);
        ptr = ptr->next ;
    }
    return start ;

}
node *insert_before(){
    node *ptr , *new_node;
    int n , i;
    char buff ;
    printf("\n enter the data to insert : ");
    scanf("%d",&n);
    while((buff=getchar())!='\n' && buff != EOF);
    printf("\nenter the after data which the data to be inserted :");
    scanf("%d",&i);
    while((buff=getchar())!='\n' && buff != EOF);
    new_node = (node *)malloc(sizeof(node));
    new_node->data = n;
    ptr = start ;

    while (ptr->data != i )
    {
        ptr = ptr->next ;
        if(ptr == NULL) {
            printf("failed to insert\n");
            return start ;
        }
    }
    new_node->next = ptr ;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node ;
    ptr->prev = new_node;


    return start ;
}

node *delete_after(){

    node *ptr , *tmp;
    int i ;
    char buff ;

    ptr = start ;
    if(ptr == NULL) return start ;
    
    printf("\nenter the previous data to delete the after node :");
    scanf("%d",&i);
    while((buff=getchar())!='\n' && buff != EOF );

    while (ptr->data != i )
    {
        
        if(ptr->next == NULL) {
            printf("failed to delete\n");
            return start ;
        }
        ptr = ptr->next;
    }
    if(ptr->next->next == NULL){
        tmp = ptr->next;
        ptr->next = NULL;
        free(tmp);
        return start ;
    }

    tmp = ptr->next;
    ptr->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);

    return start ;
}

int main(){
    int n ;
    char buff;
    do{
        printf("\t1 . create\n");
        printf("\t2. display\n");
        printf("\t3. insert before the given data\n");
        printf("\t4. delete after \n");
        printf("\t0 to exit \n");
        printf("\nENTER THE OPTION :");
        scanf("%d",&n);
        while((buff=getchar())!='\n' && buff != EOF);
        switch (n)
        {
            case 1:
                start = create();
                break ;
            case 2:
                start = display();
                break ;
            case 3:
                start = insert_before();
                break ;
            case 4:
                start = delete_after();
                break ;
            default:
                printf("invalid option\n");
                break ;
        }
    }while (n != 0);
  
    
}
