#include <stdio.h>
#define n 10 
int main(){
  int x;
  int arr[n];
printf("ENter the number at each count \n");
  for(int i=0;i<=n;i++){
    printf("%d  :",x+1);
    scanf("%d",arr[i]);
  }
  
 for(int i=0;i<=n;i++){
    if( arr[i]%5==0&& arr[i]!==0) printf("%d  \n",arr[i]);
    
  }

  
  return 0;
}
