// c program that the user to calculate the Geometric progression of and the sum of the AP
#include <stdio.h>
#include <math.h>

 int Geometric_progression(int a, int r,int n);// defining functions 
 int Geometric_progression_sum(int a, int r,int n);
 
 /* from the main function will take the data about the first term,common difference and the last term */
  int main(void)
  {
  int a,r,n,sn,GP;
    printf("Enter the first term of the serie \n");
    scanf("%d",&a);
    printf("Enter the value of the common difference\n");
    scanf("%d",&r);
    printf("Enter the first term of the serie \n");
    scanf("%d",&n);
    
    
    GP=Geometric_progression(a,r,n);
    printf("Geometric Progression=%d\n",GP);
    
    sn=Geometric_progression_sum(a,r,n);
    printf("Geometric Progression=%d\n",sn);
  }
  /* this fuction is for fining the Geometric progression*/
  int Geometric_progression(int a, int r,int n)
 {
 int GP;
 
  
  GP=a*pow(r,n-1);
  return GP;
 }
 /* this a function is for finding the sum of the Geometric progressin serie values*/
  int Geometric_progression_sum(int a, int r,int n)
 {
 int sn;
 
  
  sn=(a*(1-pow(r,n+1)))/(1-r);
  return sn;
 }
