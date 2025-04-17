#include <stdio.h>
#include <stdio.h>
#include <string.h>

typedef struct{
char numero[12];
char Nom[15];
char genre[10];
float notes[6];

}Etudiant;

void remplit(Etudiant TE[],int N)
{ 
int j=0;

while(j<N){

    for(int i=0;i<6;i++){
     printf("Entre le numero \n");
     scanf("%s",TE[i].numero);
     printf("Entre votre Nom; \n");
     scanf("%s",TE[i].Nom);
     printf("saisir votre genre \n");
     scanf("%s",TE[i].genre);
     printf("Entre votre Note \n");
     scanf("%f",&TE->notes[i]);
     i++;
     }
     j++;
     }

}

 void afficher(Etudiant TE[],int N)
 { int j=0;
 
 while(j<N){
 
   for(int i=0;i<6;i++){
     printf("Numero:%s\n",TE[j].numero[i]);
     printf("Nom   :%s\n",TE[j].Nom[i]);
     printf("Genre :%s\n",TE[j].genre[i]);
     printf("Note  :%.2f\n",TE[j].notes[i]);
     
       }
       j++;
       }
  }
 
 
 
 float moyenne(Etudiant B)
 {
 float m,s=0;
 for(int i=0;i<6;i++)
    s+=B.notes[i];
    
    return m=s/6;
 }
 void afficher1(Etudiant TE[],int N)
 { 
 int i=0;
 Etudiant* p,* T;
 for(int j=0;j<N;T++){
     if(moyenne(T[j])>=10){
          for(p=TE;p<TE+6;p++){
             printf("Numero: %s",p->numero);
             printf("Nom   :%s",p->Nom);
             printf("Genre :%s",p->genre);
             printf("Note  :%f",p->notes[i]);
             i++;     
       }
       }
       }
  }
  
  void tri(Etudiant TE[],int N)
  {
  int min;
  Etudiant temp;
  for(int i=0;i<N-1;i++)
{
   min=i;
 for(int j=i+1;j<N;j++)
 {
   if(moyenne(TE[min])>moyenne(TE[j])){min=j;}
 }
     temp=TE[i];
     TE[i]=TE[min];
     TE[min]=temp;
 
}
}


 void trier(Etudiant TE[],int N)
  {
  int min;
  Etudiant temp;
  for(int i=0;i<N-1;i++)
{
   min=i;
 for(int j=i+1;j<N;j++)
 {
   if(strcmp(TE[min].Nom,TE[j].Nom)==0){min=j;}
 }
     temp=TE[i];
     TE[i]=TE[min];
     TE[min]=temp;
   
 }
} 


int copie(Etudiant TE[],int N,char Tnom[][15])
{
int j=0,count=0;


for(j;j<N;j++){
if(strcmp(TE[j].genre,"fille")==0){
if(strlen(TE[j].genre)<=15){

strcpy(Tnom[j][15],TE[j].Nom);
printf("%s\n",TE[j].numero);

count++;
}
}
}
return count;
}


 int main()
 {
 int N;
 
 printf("Nombre de person vous voulez remplit les information\n ");
 scanf("%i",&N);
 
 Etudiant TE[N];
 char Tnom[N][15];
 
 remplit(TE,N);
 afficher(TE,N);
 afficher1(TE,N);
 tri(TE,N);
 trier(TE,N);
 printf("il y a %i fille(s)\n",copie(TE,N,Tnom));
 return 0;
 }
