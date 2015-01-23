#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
  printf("\n%d\n", argc);
  printf("\n%s\n", argv[1]);
  printf("\n%c\n", argv[2][8]);
  printf("\n%s\n", argv[3]);
  printf("\n%s\n", argv[0]);
  
  FILE* input = fopen(argv[2], "r");
  char a = fgetc(input);
  char b = fgetc(input);
  printf("\n%c%c\n", a, b);

  return 0;
}
    
