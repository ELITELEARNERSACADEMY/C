#include <stdio.h>

int main()
{

int count=0,n,arr[100];

printf("ENtre une valeur positive  : ");
scanf("%i",&n);

while(n!=0)
{
arr[count] = n%10;
n = n/10;
count++;
}


for(int i=0;i<count;i++) printf("%i",arr[i]);

return 0;
}
