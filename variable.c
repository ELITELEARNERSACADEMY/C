//working with a variable 
#include <stdio.h> 

int main(){
//declaration of  variables
  const z ; //this asigned once can't be change for the rest of the  programm
  int x ;
  int y ; //we can also declare the two variable like this ' int x,y ;' they are  equivalent  
// the a number of  c programming operators among them are the commonly used mathematical operators 
// asigning  variables 
  x = 9;
  y = 4;
  z = 3; // if we try to 

  printf("value of  : i% ",x);
  printf("value of  : i% ",y);
  printf("value of  : i% ",z);

  //reasigning the variables
  x = 1; // the new value for y is 1
  y = 6; // the new value for y is 6
  //z = 2; it is not allowed to reasign a constant variable  

  printf("value of  : i% ",x);
  printf("value of  : i% ",y);
  

return 0;
}
