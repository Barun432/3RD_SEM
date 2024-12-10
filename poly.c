#include <stdio.h>
#include <stdlib.h>

struct node {
    int co;
    int exp;
    struct node* next;
};

void create(struct node** head);
void print(struct node* head);
void add(struct node *p1, struct node *p2, struct node **result);

int count = 0;

int main() {
    struct node* p1 = NULL;
    struct node* p2 = NULL;
     struct node* p3 = NULL;
    create(&p1);
    create(&p2);
    printf("Polynomial p1: ");
    print(p1);
    printf("Polynomial p2: ");
    print(p2);
    p3=(struct node*)malloc(sizeof(struct node));
    add(p1,p2,&p3);
    printf("addition=");
 	print(p3);
    return 0;
}

void create(struct node** head) {
    struct node* temp = *head;
    struct node* newnode;
    int choice = 1;
    printf("List %d\n", ++count);
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient: ");
        scanf("%d", &newnode->co);
        printf("Enter exponent: ");
        scanf("%d", &newnode->exp);
        newnode->next = NULL;
        if (*head == NULL) {
            *head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void print(struct node* temp) {
    while (temp != NULL) {
        printf("%dx^%d", temp->co, temp->exp);
       temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

void add(struct node *p1, struct node *p2, struct node **temp)
{
	
	struct node*result;
	result= (struct Node *)malloc(sizeof(struct node));
	result->next=0;
	*temp=result;
   while(p1 && p2)
   {
      if(p1->exp > p2->exp)
	  {
         result->exp = p1->exp;
         result->co = p1->co;
         p1 = p1->next;
      }
      
      else if(p1->exp < p2->exp)
	  {
         result->exp = p2->exp;
         result->co = p2->co;
         p2 = p2->next;
      }
      
	   else 
	   {
         result->exp = p1->exp;
         result->co = p1->co+p2->co;
         p1 = p1->next;
         p2 = p2->next;
      }
      if(p1&&p2)
      {
      result->next = (struct Node *)malloc(sizeof(struct node));
      result = result->next;
      result->next = NULL;
   }
}
   
   while(p1 || p2){
   	result->next = (struct Node *)malloc(sizeof(struct node));
      result = result->next;
      result->next = NULL;
      if(p1){
         result->exp = p1->exp;
         result->co = p1->co;
         p1 = p1->next;
      }
      if(p2){
         result->exp = p2->exp;
         result->co = p2->co;
         p2 = p2->next;
      }
      
   }
}



