#include<stdio.h>
#include<stdlib.h>

typedef struct element
                     {
                      int bin;
                      struct  element* suivant; 
                     } pile;
                     
pile* AllouerNoued()
                    {
                      pile* Q;
                      Q = ( pile* )malloc(sizeof( pile));
                      
                      if( Q==NULL)
                                 {
                                  printf("memoire insuffisant\n "); exit(-1);
                                 }
                             else{
                                 Q->suivant=NULL;
                                 }
                    return Q;
                    }
                    
pile* initialiser( pile* P)
                        { 
                          P=NULL;                  
                          return P;
                        } 
                        
int pile_vide( pile* P)
                       {
                       return (P==NULL);
                       }
                       
pile*  empiler( pile* p, int e){
	pile* d;
	d = AllouerNoued();
	d -> bin = e;
	if( pile_vide( p )){ p = d ; }
	else{
		d -> suivant = p;
		p = d;
		
	}
	return p;
	}
	

pile* depiler( pile* p ){
	pile* elemetsup = p;
	if( pile_vide(p) )
	{
	 printf(" la pile est vide\n ");
	}
	else{
	elemetsup = p;
	p = p-> suivant;
	free( elemetsup );
	}
	return p;
	

}


int peek( pile* p ){
	return p -> bin;
}

void convertir_afficher_binaire( pile* p,int nbr){
	pile* courant;
	int bin;
	while( nbr!=0 ){
	bin=nbr%2;

	nbr = nbr/2;
	p = empiler( p,bin );

	}
	printf(" \napres ");
	for( courant = p; courant!= NULL; courant = courant -> suivant){
	printf("%d", courant->bin);
	}
}


int main(){
    pile* p;
    p=initialiser(p);
    
         convertir_afficher_binaire(p,16);
	return 	0;
}

