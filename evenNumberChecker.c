#include <stdio.h>

int main(){
  int x;
  printf("Enter an interger : ");
  scanf("%i",&x);

  if(x%2==0){
    printf("%i is an Integer",x);
  }
  else{
    printf("%i is not an Integer");
  }
  
  return 0;
}
