// a c program that permits the user to insert data in a list 
#include <stdio.h>
#include <stdlib.h>

 struct Node
{
  int data;
  struct Node* next;
};
struct Node* head;


int insert_data(int x);
int delete_data(int position);

int main(void)
{
int a;
// declaration of variables for the structure 
struct Node* head=NULL;
struct Node* one=NULL;
struct Node* two=NULL;
struct Node* three=NULL;
struct Node* four=NULL;
// allocating memory to the variable 
one=malloc(sizeof(struct Node*));
two=malloc(sizeof(struct Node*));
three=malloc(sizeof(struct Node*));
four=malloc(sizeof(struct Node*));

// intializing the variables 
 one->data=insert_data(a);
 two->data=7;
 three->data=3;
 four->data=6;
// connecting the list 
 one->next=two;
 two->next=three;
 three->next=four;
 four->next=NULL;
 struct Node* five=NULL;
five=malloc(sizeof(struct Node*));
 five->data=5;
 // the head to be assigned to the first 
 head=one;
 printf("%d %d %d %d %d",one->data,two->data,three->data,four->data,five->data);

} 

int insert_data(int x)
{
printf("Enter here:\n");
scanf("%d",&x);
return x;
}

int delete_data(int position)
{
printf("Enter the postion position of the element you want to delete\n");
scanf("%d",& position);
return position;
}
