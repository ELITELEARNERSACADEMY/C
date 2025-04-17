#include <stdio.h>
#include <string.h>

typedef struct client
{
    int matricule;
    char nom[20], type[20];
}client;

void rempli(client* T,int n)
{
    int i=0;
    
    do
    {
     printf("\nMatricule: ");
     scanf("%d",&T[i].matricule);
     printf("\nNom:");
     scanf("%s",T[i].nom);
     printf("\nType: ");
     scanf("%s",T[i].type);  
     i++;
     }while (i<n);
    
    }

void afficher(client* T,int n)
{
    int i=0;
    while (i<n)
    {
     printf("\nMatricule: %d",T[i].matricule);
     printf("\nNom: %s",T[i].nom);     
     printf("\nType: %s",T[i].type);
     i++;
    }
    
}

int transfere(client* T, client* T2,int n,char *Type)
{
    int j,i,count=0;

 for(i=0 ;i<n;i++)
 {
       if(strcmp(T[i].type,Type)==0)
        {
           T2[count]=T[i];
           count++;
        }
 }
 return count; 
}

int main()
{   int n,a; char Type[20];
    printf("Entre le nombre de clients: ");
    scanf("%d",&n);

    client T[n],T2[n];// declaratin des tableau 
   // les appelle des fonctions 
    rempli(T,n);
    afficher(T,n);
    printf("\nType de malade cherchez:"); scanf("%s",Type);
    printf("\nNombre de malade %s est %d\n",Type,a);
    a=transfere(T,T2,n,Type);
    afficher(T2,a);
    return 0;
}