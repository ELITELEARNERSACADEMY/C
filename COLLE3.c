#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
                  { 
                     int valeur;
                     struct maillon * suivant ;
                   
                   }LSC;
                   
                   
                   
 LSC* AllouerNoeud(){
 	
 	LSC* L;
 	L=(LSC*)malloc(sizeof(LSC));

 	if(L==NULL)
 	{
 	 printf("espace insuffisant :");
 	 exit(-1);
 	}
 	else
 	{
 	L->suivant=NULL;
 	}
 	
 	return L;
 	
 }                  
                   
LSC* insere_debut(LSC* L , int val )
                                 {
                                   
                                   LSC* NE; // NE egale la nouvel element
                                      NE= AllouerNoeud();
                                      NE->valeur = val;// intialisation de la nouvel element
                                      
                             if(L==NULL)
                                       {
                                       L=NE;
                                       }
                                       else{
                                       NE->suivant=L;
                                       L=NE;
                                       } 
       
                                   return L;
                                  
                                 }
                                 
                                                    
LSC* insere_miliue(LSC* L , int val, int position)
                                 {
                                   LSC* courant;// courant pour parcourir la liste simplement chaine 
                                   LSC* NE; // NE egale la nouvel element
                                      courant=L;
                                      NE=  AllouerNoeud();
                                      NE->valeur = val;// intialisation de la nouvel element
                                      int i=1;
                                      
                                       if(L==NULL)
                                       {
                                       
                                       L=NE; 
                                       
                                       }
                                      else{
                                      
                                       while(courant->suivant!=NULL)
                                      {
                                       if(i=position)
                                       {
                                       
                                       NE->suivant=courant->suivant;
                                       courant->suivant=NE;
                                       break;
                                       }
                                       else
                                       {
                                       courant=courant->suivant;
                                       }
                                                                                                                  
                                       }
                                       
                                      }
                                   
                                   return L;                                
                                   
                                 }
                                 

                                 
void afficher(LSC* L){
	
	LSC* courant;
	courant=L;
	while(courant){
	
	printf("%d " ,courant->valeur);
	
	courant=courant->suivant;
	}
	
}
                                  
                                  
void enregitre(LSC* L,char * fichier )
                                    {
                                    FILE* f;
                                    LSC* Q;
                                    
                                    f=fopen(fichier,"w");
                                     if(f==NULL)
                                     {
                                      printf("\nprobleme d'ouverture de fichier\n" ); 
                                      exit(0);
                                     }
                                     else
                                     {
                                         while(Q)
                                         {
                                             fprintf(f," %d ",Q->valeur);
                                             Q=Q->suivant;
                                         }    
                                         fclose(f);
                                     }
                                    
                                     
                                    }   
                                                                 
int main(){
 	LSC* L=NULL;
 	
        L= insere_debut(L,1);
        L= insere_debut(L,3);
        L= insere_debut(L,100 );
        L= insere_debut(L,27);
        L= insere_debut(L,20);
        L= insere_debut(L,290);
        
        
        afficher(L);
        printf("\navant milieu\n");
	L= insere_miliue( L ,1000, 4);
	afficher(L);
	enregitre(L,"fichier20.txt");
	return 0;
}                                 
