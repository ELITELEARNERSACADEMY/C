#include <stdio.h>

typedef struct
{
int id;
char nom[50];
char prenom[50];
float moyenne; 
}Etudiant;

Etudiant lire()
{
Etudiant Q;
printf("ID: "); scanf("%i",&Q.id);
getchar();
printf("Nom: "); scanf("%s",Q.nom);
printf("\nPrenom: "); scanf("%s",Q.prenom);
printf("moyenne: "); scanf("%f",&Q.moyenne);

return Q;
}

void lire_tous(Etudiant* etudiant, int n)
{
Etudiant* ptr;

for(ptr=etudiant;ptr<etudiant+n;ptr++)
{
*ptr=lire();
} 
}


void afficher_tous(Etudiant* etudiant, int n)
{
Etudiant* ptr;

for(ptr=etudiant;ptr<etudiant+n;ptr++)
{
printf("\n");
printf("ID: %i\n",ptr->id);
printf("Nom: %s\n",ptr->nom);
printf("prenom: %s\n",ptr->prenom);
printf("Moyenne: %.f\n",ptr->moyenne);
printf("\n");
} 
}

void trier_par_moyenne(Etudiant* etudiant, int n)
{
 int i,j,min;
 Etudiant temp;
 
 for(i=0;i<n-1;i++){
     min=i;
     for(j=0;j<n;j++){
     if(etudiant[j].moyenne<etudiant[min].moyenne){min=j;}
       }
       temp=etudiant[i];
       etudiant[i]=etudiant[min];
       etudiant[min]=temp;
       
    }

}

Etudiant recherche_dichotomique(Etudiant* etudiant,int n, int id)
{
Etudiant q={0,"","",0};
 int i,j,mid,g=0,l=n,d;
  
  
  while(g<l){
  mid=(l+g)/2;
  if(etudiant[mid].id==id)
  {
  q=etudiant[mid];
  }
  else if(etudiant[mid].id>id)
  {
  l=mid-1;
  }
  else
  {
  g=mid+1;
  }
  }
  
 
 return q;
}

void mise_a_jour(Etudiant* etudiant, int n)
{
Etudiant* Q;
 
 for(Q=etudiant;Q<etudiant+n;Q++)
 {
 Q->moyenne+=0.5;
 }
}


float moyenne_generale(Etudiant* etudiant, int n)
{
float s;
Etudiant* Q;
 
 for(Q=etudiant;Q<etudiant+n;Q++)
 {
 s+=Q->moyenne;
 }
 return s/n;
}

int main()
{

int n;
 printf("Combien etudiant saissiez la inforamtion"); scanf("%d",&n);
 Etudiant etudiant[n];
 lire_tous(etudiant,n);
 trier_par_moyenne(etudiant,n);
 afficher_tous(etudiant,n);
 mise_a_jour(etudiant,n);
 printf("Moyenne generale: %.2f",moyenne_generale(etudiant,n));
return 0;
}
