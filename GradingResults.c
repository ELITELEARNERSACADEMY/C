#include <stdio.h>

int main()
{
  float n;
  printf("ENter the value :\n");
  scanf("%d",&n);

   if(n<40){
     printf("%.2f D",n);
   }
   else if(n>=40 && n<45)
   {
     printf("%.2f D+",n);
   }
  else if(n>=45 && n<50)
   {
     printf("%.2f C",n);
   }
  else if(n>=50 && n<55)
   {
     printf("%.2f C+",n);
   }
  else if(n>=55 && n<65)
   {
     printf("%.2f B",n);
   }
  else if(n>=65 && n<75)
   {
     printf("%.2f B+",n);
   }
  else if(n>=75 && n<85)
   {
     printf("%.2f A",n);
   }
  else 
   {
     printf("%.2f A+",n);
   }
  
  return 0;
}
