
#include <stdio.h>

int main()
{

int somme=0,count=0,n,arr[100];

printf("ENtre une valeur positive  : ");
scanf("%i",&n);

while(n!=0)
{
arr[count] = n%10;
somme += n%10;
n = n/10;
count++;
}


printf("\nSOMME  %d  ",somme);

return 0;
}
