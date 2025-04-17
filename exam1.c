#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {

               int j1 ;
               int j2 ;
               
               }Injection;
               

typedef struct {

                char code[ 12 ] ;
                char nom_prenom[ 30 ] ;
                int age ;
                char categorie[ 20 ] ;
                char vaccin[ 20 ] ;//" Sinopharm " ou " Astrazenica "
                Injection inj ;
                        
               } Personne ;

typedef struct element {

                Personne P;
                struct element* suivant ;
                struct element* precedent ;

               }Liste;
   
   
Personne lire_personne()
                        {
                        
                        Personne Q;
                        
                        printf(" Code: "); scanf("%s",Q.code);
                        getchar();
                        printf(" Nom et Prenom: "); fgets(Q.nom_prenom,30,stdin);
                        printf(" Age: "); scanf("%d",&Q.age);
                        printf(" Categorie: "); scanf("%s",Q.categorie);
                        printf(" Vaccin "); scanf("%s",Q.vaccin);
                        printf(" Type d'injection 1ere:  "); scanf("%d",&Q.inj.j1);
                        printf(" Type d'injection 2eme:  "); scanf("%d",&Q.inj.j2);
                        
                        return Q;                       
                        
                        }

Liste* AllouerNoued()
                     {
                       Liste* L;
                       L = ( Liste* )malloc( sizeof( Liste ) );
                       
                       if( L == NULL )
                       {
                        printf(" Memoire insuffisant\n "); exit(-1);
                       }
                       else 
                       {
                       L -> suivant=NULL;
                       L -> precedent=NULL;
                       L -> P.inj.j1=0;
                       L -> P.inj.j2=0;
                       }
                       
                       return L;
                     }
                     
                                                
Liste* ajouter_fin(Liste* L, Personne nv)
                       {
                         Liste* NE;
                        
                         NE = AllouerNoued();
                         NE -> P = nv;
                         
                         if( L == NULL )
                         {
                           L = NE;
                         }
                         else
                         {
                           NE -> suivant = L;
                           L -> precedent = NE;
                           L = NE;
                         } 
                       }
                       
Liste* supprimer( Liste * L )
                          {
                            Liste* elem_sup,* courant=L;
                            
                            if(L == NULL)
                            {
                               printf(" Liste est vide\n "); exit(-1);
                            }
                            else 
                            {
                              while( courant!=NULL )
                              {
                              
                               elem_sup = courant;
                               
                              if( courant -> P.age < 17)
                              {
                               
                               if( courant == L )
                               {  
                                 elem_sup=L;      
                                  L = L -> suivant;
                                  free(elem_sup);
                               }
                               else
                               {
                                elem_sup = courant;
                                
                                courant = courant->precedent;
                                courant->suivant=elem_sup->suivant;
                                 
                                free(elem_sup);
                               }
                               
                                }
                              
                                 courant=courant->suivant;
                              }
               
                            }
              
               
               
                          }
                          
void diviser( Liste* L, Liste** L1, Liste** L2)
     {
     
                Liste* courant = L;
                Personne nv;
                
                if(L!=NULL)
                {
                
                while(courant)
                {
                nv=courant->P;
                //le liste qui stocke le personne avec 2 vaccine
                 
                if(courant->P.inj.j1!=0 && courant->P.inj.j2!=0)
                {
                   *L1=ajouter_fin(*L1,nv);
                }
                //le liste qui stocke le personne avec 2 vaccine
                else
                {
                   *L2=ajouter_fin(*L2,nv);
                }
                
                courant=courant->suivant;
                }
                
                }
     
     }
     
     
     
int somme(Liste* L)
                  {
                  
                  Liste* courant=L;
                  int somme=0;
                  
                  if( L != NULL )
                  {
                  
                  while( courant )
                               {
                               if( strcmp(courant->P.vaccin,"Sinopharm")==0 )
                               {
                               somme++;
                               }
                               courant = courant -> suivant;
                               }
                  }
                  else
                  {
                  printf("Liste est vide\n"); exit(-1);
                  }
                  
                  return somme;
                  }                                          

int rechercher( Liste* L , char* code )
                   {
                   Liste* Q=L;
                   if(L!=NULL)
                   {
                   while(Q)
                   {
                   
                   if(strcmp(Q->P.code,code)==0){ return 1; }
                   Q=Q->suivant;                   
                   }
                    return 0;
                   }
                   }
void enseignement(Liste* L)
                   {
                   Liste* Q=L;
                   
                   while(Q)
                   {
                   
                   if( strcmp(Q->P.categorie,"enseignement") == 0 || Q->P.age >= 45 )
                   {
                        printf("\n Code: %s",Q->P.code); 
                        printf("\n Nom et Prenom: %s",Q->P.nom_prenom); 
                        printf("\n Age: %d",Q->P.age); 
                        printf("\n Categorie: %s",Q->P.categorie); 
                        printf("\n Vaccin %s",Q->P.vaccin); 
                        printf("\n Type d'injection: 1 %d",Q->P.inj.j1);
                        printf("\n Type d'injection: 2 %d",Q->P.inj.j2); 
                        
                   } 
                   
                   Q = Q -> suivant;
                   
                   }
                    
                   }       
                               
int main()
         {
         Liste* L=NULL, *L1=NULL, *L2=NULL;
         
         Personne buntu;
         int choix;
         char* code ;
        do
        {
          printf("\nEntre votre choix: ");
          printf("\n 1. Ajouter Person\n 2. supprimmer jeune moin 17 ans\n 3. Diviser Liste\n 4. Nombre injecte ”Sinopharm”\n 5. Rechercher par code\n 6. afficher Enseignement\n ");
           scanf("%d",&choix);
        
        switch(choix)
        {
        case 1:
        
        buntu = lire_personne();
        L = ajouter_fin( L,buntu);
        
        break;
        
        case 2:
        L = supprimer( L );
        break;
        
        case 3:
        diviser( L, &L1, &L2);
        break;
        
        case 4:
        printf("\nPersonne Injecte par ”Sinopharm”: %d",somme(L));
        break;
        
        case 5:
        printf("Cherche Personne par code: "); scanf("%s", code); 
        if(rechercher(  L ,code ))
        {
        printf("\nTrouve !!!");
        }
        else
        {
        printf("\nAbsente !!!");
        }
        break;
        
        case 6:
        enseignement(L);
        break;
        
        case 0:
        choix=0;
        break;
        
        default:
        printf("Erreuer!!!");
        printf("Entre une choix valide");
        
        }
        
        }while(choix!=0);
        
        
         return 0;
         
         }
