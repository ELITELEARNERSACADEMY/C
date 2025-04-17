//C Program to Input 3 Arguments and Operate Appropriately on the Numbers
#include <stdio.h>
float operate(float x,float y,char z);

int main(){
float n1,n2;
char operatorStr;
  
printf("Enter a the two numbers");
scanf("%d%d",&n1,&n2);
printf("Enter the operator symbol");
scanf("%c",&operatorStr);
  
printf ("%.2f",operate(n1,n2,operatorStr);
return 0;
}

float operate(float x,float y,char z){

    switch(z){
      case '+': return x+y; break;
      case '-': return x-y; break;
      case '*': return x*y; break;
      case '/': return x/y; break;
      case '%': return x%y; break;
      default:  printf("Please enter valid data  "); 
    }
}
