#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
               char numero[12];
               char nom[15];
               float notes[10];
               }etudiant;

typedef struct element {
               char numero[12];
               char nom[15];
               float  notes[10];
               struct element* suivant;
               }L_C;
 
L_C* nouveau()
             {
               L_C* Q;
                    Q=(L_C*)malloc(sizeof(L_C));
                    
                    if(Q==NULL){printf("memoire insuffisante! \n"); exit(-1);}
                    else
                    {
                    Q->suivant=NULL;
                    }
                    return Q;
             }
             
             
L_C* ajouter(L_C* I, etudiant x)
             {
                 L_C* courant,* ne;
                 ne= nouveau();
                 strcpy(ne->numero,x.numero);
                 strcpy(ne->nom,x.nom);
                 for(int i=0;i<10;i++) ne->notes[i]=x.notes[i];
                 
                 if(I==NULL){I=ne;}
                 else
                 {
                     for(courant=I;courant->suivant!=NULL; courant=courant->suivant);
                     courant->suivant=ne;
                     
                 }
                                  
             return I;
             }
             
 L_C* creer()
           {
           
             etudiant E;
             L_C* I=NULL;
             
             int n,i=0;
             
             printf("Entre nombre des Etudiants emplie\n");
             scanf("%d",&n);
             
             do
             {
             printf("Numero: \n"); scanf("%s",E.numero);
             printf("Nom: \n"); scanf("%s",E.nom);
             printf("Emplie les notes\n");
             for(int j=0;j<10;j++) scanf("%f",&E.notes[j]); 
             i++;
             
             I=ajouter(I,E);
             
             }while(i!=n);
             
             return I;
           }          
           
void afficher(L_C* I)
             {
                L_C* courant;
                courant=I;
                if(I==NULL)
                {
                printf("Le liste est vide \n"); exit(0);
                }
                else
                {
                while(courant)
                {
                printf("\n");
                printf("Numero : %s\n",courant->numero);
                printf("Nom : %s\n",courant->nom);
                printf("Notes: ");
                for(int j=0;j<10;j++) printf("%2.2f ",courant->notes[j]);
                courant=courant->suivant;
                
                }
                
                }  
             }
             
             
void copier(L_C* I,char* fichier )
                  {
                    FILE* F;
                    L_C* courant=I;
                    
                    F=fopen(fichier,"w");
                    if(F==NULL){ printf("probleme d'ouverture de fichier\n");}
                    else 
                    {
                    while(courant)
                    {
                    fprintf(F,"%s %s",courant->numero,courant->nom);
                    for(int j=0;j<10;j++) fprintf(F,"%f",courant->notes[j]);
                    
                    courant=courant->suivant;
                    }
                    fclose(F);
                    }
                  }  


void afficher_fichier()
              {
              FILE* F;
                    char c;
                    
                    F=fopen("fichier.txt","r");
                    if(F==NULL){ printf("probleme d'ouverture de fichier\n");}
                    else 
                    {
                    while(c!=EOF)
                    {
                    c=fgetc(F);                    
                    printf("%c",c);
                    }
                    fclose(F);
                    }
              
              }                                 
int main()
{
   L_C* I=NULL;
   
   int choix;
   do{
    printf("1. Remplir les infor des Etudiant \n 2. Afficher les Information\n 3. copier information vers la fichier\n 4. afficher le ficher\n 5. Terminer le programme\n");
      printf("Entre votre choix\n");
      scanf("%d",&choix);
      
      switch(choix)
      {
      case 1: I=creer();
      break;
      case 2: afficher(I);
      break;
      case 3: copier(I,"fichier.txt");
      break;
      case 4: afficher_fichier();
      break;
      case 5: choix=0;
      break;

      default:
      printf("erreur!! choix invalide\n Entre une choix valide\n ");
     
      }
     }while(choix!=0); 
return 0;
}
