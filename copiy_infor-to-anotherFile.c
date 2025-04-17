#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file(char* fichier,char* fichier3, char arr[]);

int main()
{

char arr[]={"hello good morning joseph, are 21 you years old"};
file("fichier2.txt","fichier3.txt",arr);
return 0;
}

void file(char* fichier,char* fichier3,char arr[])
{
 FILE* fp,*fp1;
 int i=0;
 char c;
 char temp[200];
     fp=fopen("fichier2.txt","w");
     fp1=fopen("fichier3.txt","w");
     
     if(fp==NULL){printf("probleme d'ouverture de fichier\n"); exit(-1);}
     else{
             fprintf(fp,"%s\t",arr);
             fprintf(fp1,"%s\t",arr);

             int count=0;
             int a=strlen(temp);
             
             printf("%i",a);
             while(count<strlen(temp)){
                     printf("%c",temp[count]);
                     count++;
             }
              fclose(fp);
              fclose(fp1);
     }
     
}
