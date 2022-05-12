#include "stdio.h"
#include "stdlib.h"

struct L{
    int x;
    struct L *next;
};

//Print Linked List
void print(struct L *head){
    while(head != NULL){
        printf("%d\n", head->x);
        head = head->next;
    }
}


//Insert at end 
void insend(struct L *head){
    struct L *input = (struct L *)malloc(sizeof(struct L));
    scanf("%d", &input->x);
    input->next = NULL;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = input;
}

//Insert at start
struct L * instart(struct L *head){
    struct L *input = (struct L *)malloc(sizeof(struct L));
    scanf("%d", &input->x);
    input->next = head;
    return input;
}

//Insert at position
void inspos(struct L *head, int n){
    int i = 1;
    while(i != n+1){
        head = head->next;
        i++;
    }
    struct L *input = (struct L *)malloc(sizeof(struct L));
    scanf("%d", &input->x);
    input->next = head->next;
    head->next = input;
}

//Delete from position
void del(struct L *head, int n){
    int i = 1;
    while(i != n+1){
        head = head->next;
        i++;
    }
    head->next = head->next->next;
}

//Shift last element to front and vice versa
struct L * lasttofront(struct L *head){     
    struct L *h = head, *h1;
    while(head->next->next != NULL){
        head = head->next;
    }
    printf("head, h:- %d and %d\n", head->x, h->x);
    h1 = h->next;
    h->next = NULL;
    head->next->next = h1;
    h1 = head->next;
    head->next = h;
    return h1;
}

//Find the middle element of linked list
void middle(struct L *head){
    int i = 1, p = 0;
    struct L *h = head;
    while(head != NULL){
        head = head->next;
        i++;
    }
    while(p < i/2 - 1){
        h = h->next;
        p++;
    }
    printf("Middle element:- %d\n", h->x);
}

//Pair wise exchange 
void pair_wise(struct L *head){
    struct L *temp = head;
    int x;
    while(temp != NULL && temp->next !=NULL){
        x = temp->x;
        temp->x = temp->next->x;
        temp->next->x = x;
        temp = temp->next->next;
    }
}

//Address of element
void head_add(struct L *head){
    int n,i;
    struct L *ptr = head, *x;

    printf("Enter element whose address u want: ");
    scanf("%d", &n);
    while(ptr != NULL){
        if(ptr->x == n){
            i++;
            x = ptr;
        }
        ptr = ptr->next;
    }
    if(i != 0)
        printf("Element %d at Address %p\n", n, x);
    else
        printf("NULL\n");
}

void main(){
    struct L *head, *ptr;
    ptr = (struct L *)malloc(sizeof(struct L));
    head = ptr;
    int n;
    printf("Enter number of values: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &ptr->x);
        struct L *nn;
        if(i != n-1)
            nn = (struct L *)malloc(sizeof(struct L));
        else
            nn = NULL;
        ptr->next = nn;
        ptr = nn;
    }
    printf("Enter choice: ");
    scanf("%d", &n);
    switch(n){
        case 1: print(head); break;     //Print Linked List
        case 2: insend(head);           //Insert at end
                print(head); 
                break;
        case 3: head = instart(head);       //Insert at start
                print(head);
                break;
        case 4: printf("Enter element position, starting from 1");      //Insert element before position
                scanf("%d", &n);
                if(n-1 > 0)
                    inspos(head, n-1);
                else
                    printf("Error. Exiting..\n");
                print(head);
                break;
        case 5: printf("Enter element position, starting from 1");      //Insert element after position
                scanf("%d", &n);
                if(n-2 >= 0)
                    inspos(head, n-2);
                else
                    printf("Error. Exiting..\n");
                print(head);
                break;
        case 6: printf("Enter element position, starting from 1");      //Insert  element before position
                scanf("%d", &n);
                if(n-2 >= 0)
                    del(head, n-2);
                else
                    printf("Error. Exiting..\n");
                print(head);
                break;
        case 7: head = lasttofront(head);               //Last to front shift
                print(head); break;

        case 8: pair_wise(head); print(head); break;        //Pair wise exchange elements

        case 9: middle(head); break;            //Middle of linked list
        case 10: head_add(head); break;         //Address of element
    }       
}