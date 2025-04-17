#include <stdio.h>
#include <stdlib.h>

typedef struct
              {
               char num[10] ;// chaine de caratere
               int quantite ; //quantite de marchadrises
              } personne ;
              
typedef struct element
              {
                personne pers;
                struct element* suivant;
              } element;

typedef struct 
              {
                int taille;
                element* debut;
                element* fin;
              } File;
                            
         

element* allouerNoeud()
                   {
                      element* q;
                      q = ( element* )malloc( sizeof( element ) ) ;
                      if(q == NULL){ 
                       printf("memoire insuffisant\n");
                      }
                      else
                      {
                       q->suivant=NULL;
                      }
                      
                      return q;
                    }

File* initialiser(File* F)
                 {
                 F=(File*)malloc(sizeof(File));
                  F->taille=0;
                  F->debut=F->fin=NULL;
                  return F;
                 }
                 
                                    
int file_vide(File* F){

     return (F->debut==NULL&&F->fin==NULL);
}

 
personne creer ( personne q )
               {
               printf("Numero: \n"); scanf("%s", q.num);
               printf("Quantite: \n"); scanf("%i",&q.quantite);
               
               return q;
               }
               
               
File* enfiler(File* F)
               {
               element* NE;
               personne q;
               NE = allouerNoeud();
               q=creer( q );
               NE -> pers =q;
               
               if(file_vide(F))
               { 
               F->debut=NE;
               F->fin=NE;
               F->taille++;
               }
               else 
               {
                  F->fin->suivant=NE;                  
                  F->fin=NE;
                  F->taille++;
               }
               
               return F;
               }
               
void  afficher_filer( File* F )
                {
                  element* courant;
                  courant = F->debut;
                  int v;
                  if(file_vide(F)){
                  printf("Le filer est vide\n");
                  }
                  else
                  {
                  
                  for(int i=0; i<F->taille;i++)
                  {
                  
                  printf("\n person( Numero: %s, Quantite: %d )", courant ->pers.num, courant ->pers.quantite);
                  printf("\n\n");
                  courant = courant->suivant;
                  }
                 
                }
                }
                
                
personne  peek_camion( File* F )
                {
                  return F->debut->pers;
                }
         
         
                
File* defiler(File* F)
{
    personne z;
    element* elem_sup;
    elem_sup=F->debut;     
     
      
     if(file_vide( F ))
     {
      printf( " File est vide\n " ); exit( 0 );
     }
     
     z=peek_camion( F );
     printf("\nNUMERO: %s",z.num);
     printf("\nQUANTITE : %i",z.quantite);

     if( F->taille==1 )
     {
       
      F->debut=F->fin=NULL;

     }
     else
     {
      
       F -> debut = F -> debut ->suivant;
       
     }
        
      free(elem_sup);

      F->taille--;
     
    
return F;
}         


File* vide_filer( File* F ) 
               {
                while( !file_vide( F ) )
                {
                defiler( F );
                }
                
               return F;
               }


int main(){
          File* F=NULL;
          F=initialiser(F);
          int choix;
          
          do{
             printf(" \n1. Ajouter une nouvelle camion\n 2. Afficher toute le persone information de filer \n 3. Defiler \n 4. Vide le filer\n 5.Terminer le programme \n ");
              printf(" Entre le numero de service: "); scanf("%i",&choix);
              
                switch( choix ){
                case 1:
                          
                          F = enfiler( F );
                break ;
                case 2:
                          afficher_filer( F );
                break ;
                case 3:
                           F=defiler( F );
                break ;

                case 4:
                           F=vide_filer( F );
                break ;
                case 0:
                           choix=0;
                break ;

                default:
                printf(" ERREUR choix invalider\n ");
                printf(" Entre une choix vslider\n ");
                 }
            }while(choix!=0);
         
         
         return 0;
         }
