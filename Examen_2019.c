#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

typedef struct maillon
             {
              int x;
              int y;
              struct maillon* suivant;
             }snake;

             
int taille(snake* s)
          {
            snake* courant;
            int count;
            
            while(courant)
            {
            count++;
            courant=courant->suivant;
            }
          
           return count;
          }


          
void deduire(snake** s)
          {
             snake* delete;
             
             while(s!=NULL)
             {
              delete=*s;
              *s = (*s) -> suivant;
              free(delete);
             }
           
          }


          
int mordre( snake* s)
          {
            
            snake* courant=s;
            if(s==NULL)
            {
            
             printf("le serpent est morte\n");
             exit(-1);
             
            }
            else 
            {
            while(courant)
            {
            courant=courant->suivant;
            if(courant->x==s->x && courant->y==s->y)
            return 1;
            }
            
            return 0;
            }

          }
          
          
          
snake* inserer_tete(snake* s, int x, int y)
             {
             snake* ne;
             ne=(snake*)malloc(sizeof(snake));
             
             if(ne==NULL)
             {
              printf("memoire insuffisante\n"); exit(-1);
             }
             else 
             {
              ne->x=x;
              ne->y=y;
              
              if(s==NULL)
              {
              ne->suivant =s;
              s=ne;
              }
             }
             
             return s;
             }
             
             
snake* supprimer_queue(snake* s)
             {
              snake* Q,* delete;
              
              if(s==NULL)
              {
               printf("Le serpent est morte\n"); exit(-1);
              }
             else
             {
              delete=Q=s;
              while(delete)
              {
                Q=delete;
                delete=delete->suivant;
              }
              Q->suivant=NULL;
              free(delete);
             }
             
             return s;
             }

snake* mouvement(snake* s, char direction)
             {
              int x,y;
              direction=toupper(direction);
              
              if(direction=='N')
              {
               
               x=s->x; y=s->y-1; if(y<0) y=9;
               
               if(mordre(s))
               {
                  printf("Perdu!!!\n");
                  printf("Score %d", taille(s));
                  deduire(&s);
               }
               }
               else if(direction=='S')
               {
               
               x=s->x; y=s->y+1; if(y>9) y=0;
               
               if(mordre(s))
               {
                  printf("Perdu!!!\n");
                  printf("Score %d", taille(s));
                  deduire(&s);
                }
                
                }
                else if( direction=='E')
                {
                  x=s->x-1; y=s->y;
                  
                  if(x<0) x=9;
                  
               if(mordre(s))
               {
                  printf("Perdu!!!\n");
                  printf("Score %d", taille(s));
                  deduire(&s);
                } 
                }
                else
                {
                 x=s->x+1; y=s->y;
                 if(x>9); x=0;
                 
                 if(mordre(s))
                {
                  printf("Perdu!!!\n");
                  printf("Score %d", taille(s));
                  deduire(&s);
                } 
               
                s=inserer_tete(s,x,y);
                
                return s; 
                }
               
               }
             
             
snake* gain(snake* s, int x1, int y1)
{

if(s->x==x1 && s->y==y1)
s=inserer_tete(s,x1,y1);
return s;
}


int main()
{
return 0;
}
