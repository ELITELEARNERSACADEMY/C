#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

bool hours();
bool minutes();
void seconds();
bool millisecond();

           
void seconds(int  sec)
             {
             
             int h, m, s;
             
             
             while( sec != 0)
             {
             
             
             printf("\r%04d ",sec); 
             clock_t stop = clock()+CLOCKS_PER_SEC;
             
             fflush(stdout);
             while(clock() < stop ){}
              sec--;
             }
              printf("\rtime up!!");
             
             }


 
int main()
{

int  n;


printf("Entre number of seconds "); scanf("%d",&n);

seconds(n); 



return 0;
}
