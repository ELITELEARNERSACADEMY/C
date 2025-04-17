#include <stdio.h>

int main(){
  //primitive data types: int, float, char,
  // declaration a variable for each data type 
  int x ; //we can perform mathematic operations 
  float y; // we can perform mathematic operations 
  char z;  // we can  not perform mathematic operations , z can store only one character 
  char Q[2];  // we can  not perform mathematic operations , Q can store only many a word or group characters
  //user data types : arrays, structure,unions enumirations etc  we use them later 

    //asigning variables;
  x = 100;
  y = 92.4223;
  char z = 'T';
  Q[2] = 'yes';

  printf("100 + 92.4223 : %f ",x+y); // results 192.4223
  printf("What is stored in z is : %c",z); // results T
  printf(" %s C programming is easy",Q); // results yes
  return 0;
}
