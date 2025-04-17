#include <stdio.h>
#include <string.h>


int main()
{
char t[1000]={"am a zambian, am a student doing my second year at FSTM\n"};
char* c;
int len=strlen(t);
FILE* F;
     F=fopen("text.txt","a");
     if(F==NULL) printf("Problem with opening the file \n");
     else 
     for(c=&t[0];c<&t[0]+len;c++)
     {
     printf("%c\n",*c);
     
      fputc(*c,F);
     }
     printf("file open successifully \n");
     fclose(F);
     
return 0; 
}
