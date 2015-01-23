#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pa09.h"

int charorbit(const char * filename);
HuffNode * chartree(FILE * input);
HuffNode * bittree(FILE * input);
void Huff_postOrderPrint(HuffNode * tree, FILE * output);
void Destroy_tree(HuffNode * tree);
int main(int argc, char * * argv)
{
  int type = charorbit(argv[1]);
    
  FILE * input = fopen(argv[1], "r");
  HuffNode * tree; 
  if(type == 1)
  {
    tree = chartree(input);
  }
  if(type == 0)
  {
    tree = bittree(input);
  }
    FILE * output = fopen(argv[2], "w");
    Huff_postOrderPrint(tree, output);
    //Huff_postOrderPrint(char_tree);
    Destroy_tree(tree);
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}

int charorbit(const char * filename)
{
  char * determine;
  determine = strstr(filename, "bit");
  if(determine != NULL)
  {
    return 0;
  }
  if(determine == NULL)
  {
    return 1;
  }
}