#include <stdio.h>
#include <stdlib.h>

//singular linked list structure 
typedef struct cellule
{
             char d; //le delimiteur ouvrant
             struct cellule* suivant; 
}pile;

//memory allocation
pile* allouer()
{
           pile* Q;
           Q=(pile*)malloc(sizeof(pile));
           
           if(Q==NULL){
             printf("memoire insufissant\n");
             exit(-1);
             }else{
              Q->suivant=NULL;
             }
return Q;
}

pile* initialise_pile(pile* P)
{
      P->d='\0';
      return P;
}

int pile_vide(pile* P)
{
         return (P!=NULL); 
}

pile* empile(pile* p)
{



}

int main()
{
        return 0;
}
