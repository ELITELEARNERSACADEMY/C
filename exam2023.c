#include <stdio.h>
#include <stdlib.h>

/* temp d'execution necessaire en minutes*/
#define T1 3
#define T2 7
#define T3 10
#define T4 12

typedef struct{
  int num;/* numero de client*/
  int type_serv;/*le service dont le client a besoin 1 2,3 ou 4*/
}client;

typedef struct element 
{
 client cl; /* la donne que notre file stockera*/
 struct element * suivant;/* pointeur ver l'element suivant*/
}Element;

typedef struct 
{  
    Element* debut;
    Element* fin;
    int taille;
    int temp_att;
}File;

File* Fintiliser( File* F)
{
    F=NULL;
    F->taille=0;
    F->temp_att=0;
 return F;
}


client lire_client()
{  
  client q;
  do{
      printf("Entre le numbre  des clients: \n"); scanf("%i",& q.num);
      
    }while(q.num<0);
    
    do{
       printf (" \n1. Guichet\n 2. Guichet\n 3. Guichet\n 4. Guichet \n");
       scanf (" %i ", & q.type_serv);
      }while(q.type_serv != 1 || q.type_serv != 2 || q.type_serv != 3 || q.type_serv != 4 );
      
  return q;
}

int service_client(client Q)
{
  
   Q=lire_client();
   // on va returne le quantite de temp selon le choix de service de cliente
   if( Q.type_serv == 1) { return T1; }
   if(Q.type_serv == 2) { return T2; }
   else if(Q.type_serv == 3) { return T3; }
   else if(Q.type_serv == 4) { return T4; }
    
}

Element* allouerNoued()
{  Element* K;
     K = ( Element* ) malloc ( sizeof ( Element* ) );
     if(K == NULL){ printf(" insuffissante memoire \n ") ; }
     else
     {
      K -> suivant = NULL;
     }
     
     return K;
}

File* evalue_temp_attente(File* F1,File* F2,File* F3)
{ 
 client Q;
  int* T;
  int j = 1, min;
  T[0] = F1-> temp_att;
  T[1] = F2 -> temp_att;
  T[2] = F3-> temp_att;
  
   min = T[0] ;
   
   while( j <= 3){ if( min < T[j] ) min = T[j]; j++;}  
   
   
   
   if (T[0]==min){ return F1;}
   if (T[1]==min){ return F2;}
   if (T[2]==min){ return F3;}
   
    
}


File* enfiler(File* F, client clt)
{
   struct element* NE;
    NE = allouerNoued();
    NE -> cl = clt;
    if( F -> taille == 0)
    {
       F -> debut = NE;
       F -> fin = NE;
    }
    else
    {
       F -> fin -> suivant = NE;
       F -> fin = NE ;
    }
    F -> taille++;
    F -> temp_att = F->temp_att + service_client( clt );
    return F;
}


File* defiler(File* F)
{ 
   File* elem_sup;
   elem_sup = F;
 
 if(F -> taille == 1) 
 {
   F -> debut = NULL;
   F -> fin = NULL; 
 }
 else
 {
    F -> debut = F -> debut -> suivant;
 }
 F -> taille--;
 free ( elem_sup );
return F;

}

void imprimer_ticket( File* F, client c)
{
   F = enfiler( F, c);
   char* ticket = "ticket.txt";
   
FILE*  fp;
    fp = fopen( ticket, "w");
    
    if( fp == NULL ){ printf ( "erreur d'ouverture le ficher\n" ); exit ( -1 );}
    else
    {
    fprintf ( fp ," %i \t %i \t", & F -> debut -> cl.num,&F->debut->cl.type_serv);
    F=defiler(F);
    }
    fclose(fp);
}


void tri_file(File* F_a,File* F_b)
{
   client clt, ck;
   int test;
   Element* courant,* courant2;
   courant = F_a -> debut;
   clt.num = courant -> cl.num; // clt.num = numero de client utiliser en file qui n'est pas trier 
   
   do{
   
      test=0;
      while(courant -> suivant != NULL)
      {
       if(clt.num < courant -> cl.num)// evalue la minimum valuer de numero de client 
       {
          ck = courant -> cl;//initialiser la client
            F_b = enfiler(F_b , ck);// enfiler le la file avec le contient de client par ordre croissant de nunero de client 
         test=1; 
       }
       
       courant = courant -> suivant;
      }
      
      clt.num = courant -> suivant -> cl.num;
     
     }while(test != 0); 
      
}


int main()
{
  lire_client();
return 0;
}
