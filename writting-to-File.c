//writting to a file
#include <stdio.h>
#include <stdlib.h>


int main()
{

            
            FILE* f;
 
              f=fopen("/home/joseph/c-projects/programation_structure_de_donne/text.txt","w");
              if(f!=NULL){
                for(int i=1; i<=100 ;i++)
                                 fputc('H',f);
                                 fclose(f);
                }else{
                            printf("File not opened \n");
                  }
  return 0;
}
