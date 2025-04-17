#include <stdio.h>

int main(){
int x,y,z;
printf("%i%i%i",&x,&y);

if(x>=y){
         if(x>z){   
           printf("%i is greater that or equal to %i and greater that or equal to %i ",x,y,z);
         }
}
else if(y>=x) 
{
         if(y>=z){   
           printf("%i is greater that or equal to %i and greater that or equal to %i ",y,x,z);
         }

}
else 
{
      printf("%i is the biggest number among the three");
}

return 0;
}
