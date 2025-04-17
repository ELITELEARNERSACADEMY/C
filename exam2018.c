#include <stdio.h>

int len(char* s)
{
int count=0, i=1;
char c=s[0];

while(c!='\0')
{
++count;
c=s[i];
i++;
}

return count;
}

int len_point(char* s)
{
char* c=s;
int count=0, i=0;

for(c;*c!='\0';c++)
{
count++;
}
return count;
}

int est_prefixe(char* m,char* s )
{
int i=0,count=0;

char c=m[0],M=m[0];
while(c!='\0')
{

if(c!=s[i])
{
  break;
}
else 
{
 ++count;
}

 i++;
}
return (count!=0);
}

int est_suffixe(char* m, char* s)
{
char c;
int i=0,count=0;
for(int j=0;j<len(m);j++) printf("%c\t",m[j]);
  c=s[i];
  while(c!='\0')
  {  
     c=s[i];
     
     if(c==m[i]){
      ++count;}
     else{ count=0; }
     
     i++;
     
  }
  
  return len_point(s)-count;
}


int main()
{
  char s[]={"mynameisjoseph"};
  char m[]={"joseph"};
 printf("\nnumeber elements %d",len(s));
 printf("\n2numeber elements: %d",len_point(s));
 printf("here:  %i\n",est_suffixe(m,s) );
 
 if(est_prefixe(m,s))
  {
  printf("\nest un prefixe");
  }
  else
  {
  printf("\nN'est pas un prefixe");
  }
 
 
  if(est_suffixe(m,s)!=len_point(s))
  {
  printf("\nest un suffixe de len:%d ",est_suffixe(m,s));
  }
  else
  {
  printf("\nN'est pas un suffixe");
  }
 
  return 0;
}


