// a c program that permits the user to insert data in a list 
#include <stdio.h>

typedef struct Node
{
  int data;
  struct *Node next;
};
struct *Node head;
//int insert_data();
int main(void)
{
// declaration of variables for the structure 
struct *Node head=NULL;
struct *Node one=NULL;
struct *Node two=NULL;
struct *Node three=NULL;
struct *Node four=NULL;
// allocating memory to the variable 
one=(struct *Node)malloc(sizeof(struct *Node));
two=(struct *Node)malloc(sizeof(struct *Node));
three=(struct *Node)malloc(sizeof(struct *Node));
four=(struct *Node)malloc(sizeof(struct *Node));

// intializing the variables 
 one->data=10;
 tw0->data=7;
 three->data=3;
 four->data=6;
// connecting the list 
 one->next=two;
 two->next=three;
 three-next=NUll;
 // the head to be assigned to the first 
 head=one;
 while(head!=NULL)
 {
 printf("%d  ",data->next);
 }
 
} 
/* int insert_data()
{
retrun L;
} */
