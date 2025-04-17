// c program that the user to calculate the arithmetic progression of and the sum of the AP
#include <stdio.h>

 int Arithmetic_progression(int a, int d,int n);// defining functions 
 int Arithmetic_progression_sum(int a, int d,int n);
 
 /* from the main function will take the data about the first term,common difference and the last term */
  int main(void)
  {
  int a,d,n,s,AP;
    printf("Enter the first term of the serie: \n");
    scanf("%d",&a);
    printf("Enter the value of the common difference: \n");
    scanf("%d",&d);
    printf("Enter term you are looking for:  \n");
    scanf("%d",&n);
    
    
    AP=Arithmetic_progression(a,d,n);
    printf("AP of %i Terms : %d\n",n,AP);
    
    s=Arithmetic_progression_sum(a,d,n);
    printf("Sum of AP : %d\n",s);
  }
  /* this fuction is for finding the arithmetic progression*/
  int Arithmetic_progression(int a, int d,int n)
 {
 int AP;
 
  
  AP=a+(n-1)*d;
  return AP;
 }
 /* this a function is for finding the sum of the arithmetic progressin serie values*/
  int Arithmetic_progression_sum(int a, int d,int n)
 {
 int sum;
 
  
  sum=(n/2)*(2*a+(n-1)*d);
  return sum;
 }
