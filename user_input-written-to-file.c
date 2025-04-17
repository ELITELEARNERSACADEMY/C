#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 1000

int main()
{
char set[n];
int c=0; 

printf("Enter content to add to the file:\n ");
fgets(set,n,stdin);

FILE* fptr;
fptr = fopen("/home/joseph/c-projects/programation_structure_de_donne/doc.txt","w");

if(fptr!=NULL)
{
         do{
             fputc(set[c],fptr);
             c++;
           }while(c<strlen(set));
         fclose(fptr);
}
else 
{
         printf("Erreur! il y a une faut \n");
         exit(0);

}

return 0;
}
