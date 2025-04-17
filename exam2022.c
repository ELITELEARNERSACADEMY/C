#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char nom[30];
   int age;
   int salaire;
   int numero_employe;
   int annee;
  }employe;

employe creer(){
           employe p;
 
                  printf("Entre detail d'Employe\n");
                  printf("NOm: \n"); scanf("%s",p.nom);
                  printf("Age: \n"); scanf("%d",&p.age);
                  printf("Salaire: \n"); scanf("%d",&p.salaire);
                  printf("Numero d'employe: \n"); scanf("%d",&p.numero_employe);
                  printf("Annee d'experience \n: "); scanf("%d",&p.annee);
 
                 return p;
}

void afficher(employe employes){
                     printf("NOm: %s \n",employes.nom);
                     printf("Age: %d \n",employes.age);
                     printf("Salaire: %d  \n",employes.salaire);
                     printf("Numero d'employe: %d \n",employes.numero_employe);
                     printf("Annee d'experience : %d \n",employes.annee);
}

void afficherTousEmployes(employe* emp, int taille){    
    employe* ptr;
    for(  ptr = emp; ptr < emp + taille ; ptr++ )
    {
          afficher ( *ptr ); printf ( " \n\n " ) ;
    }
} 

employe employePlusHautscalaire(employe* emp, int taille){
                   employe emp1;
                   int i=1,temp,j=0;
                   temp=emp[0].salaire;
  
                    while(i<taille){
                                     if(temp<emp[i].salaire){
                                                   temp=emp[i].salaire;
                                                   j=i;
                                      }
                                      i++;
                    }
                    emp1=emp[j];
                    return emp1;
}

float moyenneAge(employe* emp, int taille)
{
                           float m;
                           int j=0,s=0;

                           while(j<taille){
                                   s+=emp[j].age;
                                   j++;
                           }
                           m=(float)(s/taille);

                           return m;
}

void trier_employes_par_nom(employe emp[], int taille)
{
                           employe temp;
                           int j,i,k;
                           for(i=0;i<taille-1;i++){ 
                                        k=i;
                                        for(j=i+1;j<taille;j++){
                                                if(strcmp(emp[k].nom,emp[j].nom)>0){
                                                             k=j;
                                                 }
                                          }
                                          temp=emp[i];
                                          emp[i]=emp[j];
                                          emp[j]=temp;
                         }
  
}
 
 
employe* longestName(employe emp[],int n)
{
    employe* longName;
    
    int i,k,j;
    
    k=strlen(emp[0].nom);
    
    for(i=1;i<n;i++){
                 if(k>strlen(emp[i].nom){
                        *longName=emp[i];
                        k=strlen(emp[i].nom);
                 } 
    }
    
    return longName;
}

void savgarder_bin(employe employees[], int n, char* rep)
{
             FILE* fp;
             fp=fopen("Doc","wb");
             if(fp==NULL){
                          printf("memoire insuffisant \n");
                          exit(-1);
             }else{
                          fwrite(&employees,sizeof(employe),1,fp);
             }
   
            fclose(fp);
}

void afficher_ensemble_Employe(FILE* rep)
{

              char c[200];
 
              rep=fopen("Doc","rb");
   
              if(rep==NULL){
                       printf("memoire insuffisant \n");
                       exit(-1);
               }else{
                        fread(&c,sizeof(employe),1,rep); 
                        printf("Here: "); puts(c);
               }
   
                fclose(rep);
}

int main()
{


                             int taille,choix,i=0;
                             printf("Combien employee\n"); scanf("%d",&taille);
                             employe emp[taille],*temp2,temp,*temp1;

                              do{
                                               printf(" 1.Remplie informations d'employee\n 2.Afficher Tous les Employe\n 3.Employee avec plus haut salaire\n 4.Trouver moyenne Age\n 5.Trier\n 6.Employe avec le plus long nom\n 7.Enregistre information des employees\n 8.Afficher dossier d'inforamtion des employe 9.Terminer la programme\n");
printf("choissir l'operation\n"); scanf("%d",&choix);


                             switch(choix){
                                      case 1: 
                                                   for(temp2 = emp; temp2<emp+taille;temp2++){ 
                                                               *temp2=creer();
                                                    } break;
                                      case 2: 
                                                    afficherTousEmployes(emp,taille);
                                                    break;
                                      case 3:
 
                                                   temp=employePlusHautscalaire(emp, taille);
                                                    afficher(temp);
                                                     break;
                                     case 4: 
                                                    printf("moyenne d'Age des employees : %f\n",moyenneAge(emp,taille));
                                                    break;
                                    case 5: 
                                                    trier_employes_par_nom(emp,taille);
                                                    break;
                                  case 6: 
                                                    temp1=longestName(emp,taille);
                                                    temp=*temp1;
                                                    afficher(temp);
                                                    break;
                                  case 7: 
   
                                                     savgarder_bin(emp,1000,"Doc.bin");
                                                     break;
                                  case 8: 
                                                     FILE* rep;
                                                     afficher_ensemble_Employe(rep);
                                                     break;
                                  case 9:
                                                     choix=9;
                                                     break;
                                  default: printf("Erreur de choix\n");
                              }

                             }while(choix!=9);


                              return 0;
}
