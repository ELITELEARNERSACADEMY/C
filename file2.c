#include <stdio.h>

int main(){
             FILE* fptr;
              fptr = fopen("/home/joseph/c-projects/programation_structure_de_donne/text.txt","r");
 char content[100];
 
while(fgets(content,100,fptr)){
                   printf("%s",content);
}
 fclose(fptr);
return 0;
}
