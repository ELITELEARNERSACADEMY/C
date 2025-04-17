//a  c program  thats permits the user to compute numbers using different operators to perfom specific tasks
#include <stdio.h>
#include <math.h>

#define Pi 3.421

// declaration of functions for the computation 
float sum_num(float X, float y);
float dif_num(float x,float y);
float pro_num(float x, float y);
float div_num(float x, float y);
float squire_num(float x);
int squire_root(int x);
float cube_root(float x);
float sinus_cosinus_tangent(float x);
float power_num(float x, float y);
int fact(int x);
float reciprocal(float x);
float Sin(float x);
float Cos(float x);
float Tan(float x);
float exponetial(float x);
float logarithm(float x);
float logarithm10(float x);
float logarithmx(float x, float y);
 

int main(void)
{
int i,choice;
float a,b,c,ans,off_button=1;
// displaying the list of options 
while(off_button!=0){
printf("choose the operation: Enter ;\n 1.  Addition \n 2.  Substract\n 3.  Multiplication;\n 4.  Division;\n 5.  Squire root;\n 6.  Squire;\n 7.  Number Powered(x^y);\n 8.  Number factorial (x!);\n 9.  Reciprocal of number(1/x)\n 10. Cube root;\n 11. Sin\n 12. cos\n 13. tan\n 14. exp\n 15. ln\n 16. log\n 17. logx(Y)\n 0. Power off;\n");
printf("Here:");
scanf("%d",&choice);
// to avoid the options to happen at once instead one by choice using the switch

 switch(choice){
 case 1: printf("Enter the values: \n"); printf("x space y:"); scanf("%f   %f",&a,&b); ans=sum_num(a,b);
 break;
 case 2: printf("Enter the values: \n"); printf("x space y:"); scanf("%f   %f",&a,&b); ans=dif_num(a,b);
 break;
 case 3: printf("Enter the values: \n"); printf("x space y:"); scanf("%f   %f",&a,&b); ans=pro_num(a,b);
 break;
 case 4: printf("Enter the values: \n"); printf("x space y:"); scanf("%f   %f",&a,&b); ans=div_num(a,b);
 break;
 case 5: printf("Enter the value: \n");printf("x :"); scanf("%d",&i); ans=squire_root(i);
 break;
 case 6: printf("Enter the value: \n"); printf("x :"); scanf("%f",&a); ans=squire_num(a);
 break;
 case 7: printf("Enter the values: \n"); printf("x space y =x^y :"); scanf("%f %f",&a,&b); ans=power_num(a,b);
 break;
 case 8: printf("Enter the value: \n"); printf("x :"); scanf("%f",&a); ans=fact(a);
 break;
 case 9: printf("Enter the value: \n"); printf("x :"); scanf("%f",&a); ans=reciprocal(a);
 break;
 case 10: printf("Enter the value: \n"); printf("x :"); scanf("%f",&c); ans=cube_root(c);
 break;
 case 11: printf("Enter the value: \n"); printf("sin( "); scanf("%f",&c);ans=Sin(c);
 break;
 case 12: printf("Enter the value: \n"); printf("cos( "); scanf("%f",&c); ans=Cos(c);
 break;
 case 13: printf("Enter the value: \n"); printf("tan( "); scanf("%f",&c); ans=Tan(c);
 break;
 case 14: printf("Enter the value: \n"); printf("exp( "); scanf("%f",&c); ans=exponetial(c);
 break;
 case 15: printf("Enter the value: \n"); printf("ln( "); scanf("%f",&c); ans=logarithm(c);
 break;
 case 16: printf("Enter the value: \n"); printf("log( "); scanf("%f",&c); ans=logarithm10(c);
 break;
 case 17: printf("Enter the value: \n"); printf("logx(y) x space y "); scanf("%f   %f",&a,&b); ans=logarithmx(a,b);
 break;

 case 0: off_button=0;
 break;
  default: printf("please enter a valid choice\n");
 }
 // the condition only permits us to see the answer when calcultor if on
 if(choice!=0){ printf("ans = %.3f\n",ans); printf("\n");}// displaying an answers    
 }
}
float pro_num(float x, float y){
return x*y;// the function returns the product
}
float div_num(float x, float y){
return x/y;// the function returns the divident 
}
// the substraction function
float dif_num(float x,float y){
return x-y; // the function returns the difference between the number
}
float sum_num(float x, float y){
return x+y;// the fuction returns the sum of two numbers 
}

float squire_num(float x){
return x*x;// the function returns the squire of the number 
}
int squire_root(int x){
return sqrt(x);
}
float cube_root(float x){
return cbrt(x);
}

float power_num(float x, float y){
 float power=x;
// this function returns a power of a number with the help of the for  loop 
for(int j=1;j<y;j++){
power=power*x;
}
return power;
}

int fact(int x){
 if(x==0)
 return 1;
 else
 return x*fact(x-1);
}

float reciprocal (float x){
return 1/x; // returns the reciprocal of the given value 
}

float Sin(float x)
{
  return sin(x);// returns  a floating value of sinus of the entered figuire  
}
float Cos(float x)
{
   return cos(x);// returns  a floating value of cosinus of the entered figuire 
}

float Tan(float x)// returns  a floating value of tangent of the entered figuire 
{
 return tan(x);
}
float exponetial(float x)
{
return exp(x);// returns  a floating value of expontiel of the entered figuire
}
float logarithm(float x)
{
return log(x);// returns  a floating value of natural log of the entered figuire
}

float logarithm10(float x)
{
return log(x);// returns  a floating value of log base 10 of the entered figuire
}
float logarithmx(float x, float y)
{
return logl(y);// returns  a floating value of log base choice, of the entered figuire
}
