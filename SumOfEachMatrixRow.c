#include <stdio.h>
#define size 3
int main()
{
int  arr[seize][size];
float sum = 0;

printf("fill in row by row count  ");

for(int i=0;i<=size;i++){
    printf("Row %d :",i+1);
     for(int j=0;j<=size;j++){
            scanf("%d",arr[i][j]);
        }
  }

for(int i=0;i<=size;i++){
     for(int j=0;j<=size;j++){
            sum+= arr[i][j];
        }
    printf("Row No %d sum %.2f:",i+1,sum);
  }

return 0;
}
