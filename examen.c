#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 typedef struct 
              {
                int j1 ; // j1=1 si personne a recue la premiere
                        // injection et j1=0 sinon.
                int j2 ; // j2=1 si personne a recue la deuxieme
                        // injection et j2=0 sinon.
                        
              }Injection ;

 typedef struct 
              {
               char code[12] ; // le CIN de la personne 
               char nom_prenom[30] ; // Nom et prenom de personne 
               int age ; // Age de la personne 
               char categorie[20] ; // population ciblee
               char vaccine[20] ; // " sinophara " ou " Astrazenica "
               Injection inj ;// Injections realise

              }personne ;

typedef struct element
              {
                      personne P;
                      struct element * suivant ;
                      struct element * precedent ;

              }Liste ;
personne creer_personne()
                       {
                       
                       personne Q;
                       
                       
                       printf ("\n Injection: ") ; scanf ( " %i ", &Q.inj.j1 ) ;
                       printf ("\n Injection: ") ; scanf ( " %i ", &Q.inj.j2 ) ;
                       printf ("\n Age: ") ; scanf ( " %i ", &Q.age);
                       getchar();
                       printf ("\n Categorie: ") ; scanf ( " %s ", Q.categorie ) ;
                       printf ("\n Vaccine: ") ; scanf ( " %s ", Q.vaccine ) ;
                       printf ("\nEcrire le code: ") ; scanf ( " %s " , Q.code) ;                       
                       printf ("\n Nom et prenom: ") ; scanf ( " %s " , Q.nom_prenom) ;
 
                       return Q ;


                       }

Liste* AlloueurNoued(){
                      Liste* Q ;
                      Q = ( Liste* ) malloc (sizeof (Liste));
                      if ( Q == NULL ) { printf (" memoire insuffisant\n ") ; exit ( -1 ) ; }
                     else
                     {
                       Q -> suivant = NULL ;
                       Q -> precedent = NULL ;
                     }
                     
                     return Q ;
                     
                     }
Liste* ajouter_fin ( Liste* L, personne nv )
                                        {
                                          Liste* courant ,* NE ;
                                          NE = AlloueurNoued() ;
                                          NE->P = nv ;
                                           
                                          if( L == NULL ){ L = NE; }
                                          for ( courant = L ; courant != NULL ; courant = courant->suivant );
                                          
                                          NE -> precedent = courant ;
                                          courant -> suivant = NE ;
                                          
                                          return L ;
                                         }
Liste* Supprimer();


int main()
{
  Liste* L = NULL ;
  personne p ;
  p = creer_personne() ;
  L = ajouter_fin ( L, p );
  
}
