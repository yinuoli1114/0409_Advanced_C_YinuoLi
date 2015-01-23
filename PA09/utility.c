#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pa09.h"

void Huff_postOrderPrint(HuffNode * tree, FILE * output);
HuffNode * chartree(FILE * input);
//void Huff_postOrderPrint(HuffNode *tree);
void Destroy_tree(HuffNode * tree);



/*void Huff_postOrderPrint(HuffNode *tree)
{
    // Base case: empty subtree
    if (tree == NULL) {
		return;
    }

    // Recursive case: post-order traversal

    // Visit left
    printf("Left\n");
    Huff_postOrderPrint(tree->left);
	printf("Back\n");
    // Visit right
    printf("Right\n");
    Huff_postOrderPrint(tree->right);
	printf("Back\n");
    // Visit node itself (only if leaf)
    if (tree->left == NULL && tree->right == NULL) {
		printf("Leaf: %c\n", tree->value);
    }
    
return;
}*/

void Huff_postOrderPrint(HuffNode * tree, FILE * output)
{
  if(tree == NULL)
  {
    return;
  }
  fprintf(output, "Left\n");
  Huff_postOrderPrint(tree -> left, output);
  fprintf(output, "Back\n");
  fprintf(output, "Right\n");
  Huff_postOrderPrint(tree -> right, output);
  fprintf(output, "Back\n");
  if(tree -> left == NULL && tree -> right == NULL)
  {
    fprintf(output, "Leaf: %c\n", tree -> value);
  }
}
  

Stack * Stack_create(HuffNode * tn)
{
  Stack * st = NULL;
  st = malloc(sizeof(Stack));
  st -> node = tn;
  st -> next = NULL;
  return st;
}

HuffNode * Huffnode_create(int ch)
{
  HuffNode * treenode = malloc(sizeof(HuffNode));
  treenode -> left = NULL;
  treenode -> right = NULL;
  treenode -> value = ch;
  return treenode;
}


Stack * Stack_push(Stack * st, HuffNode * tn)
{
  Stack * stacktop = Stack_create(tn);
 // stacktop -> node = tn;
  stacktop -> next = st;
  return stacktop;
}

Stack * Stack_pop(Stack * stacktop)
{
  /*if(stacktop == NULL)
  {
    return NULL;
  }*/
  Stack * new_stacktop = stacktop -> next;
  free(stacktop);
  return new_stacktop;
}


HuffNode * chartree(FILE * input)
{
  int finish = 0;
  int ch_number;
  int ch_letter;
  HuffNode * leaf = NULL;
  HuffNode * nodetop = NULL;
  HuffNode * right = NULL;
  HuffNode * left = NULL;
  Stack * stacktop = NULL;
  while(finish == 0)
  {
    ch_number = fgetc(input);
    printf("%c", ch_number);
    if(ch_number == '1')
    {
      ch_letter = fgetc(input);
      printf("%c", ch_letter);
      leaf = Huffnode_create(ch_letter);
      stacktop = Stack_push(stacktop, leaf);
    }
   if(ch_number == '0')
    {
      right = stacktop -> node;
      stacktop = Stack_pop(stacktop);
      if(stacktop == NULL)
      {
	finish = 1;
	//return right;
      }
      else
      {
	left = stacktop -> node;
	stacktop = Stack_pop(stacktop);
	nodetop = Huffnode_create(0);
	nodetop -> left = left;
	nodetop -> right = right;
	stacktop = Stack_push(stacktop, nodetop);
      }
    }
  }
  return right;
}


HuffNode * bittree(FILE * input)
{
  int finish = 0;
  //int ch_number;
  char ch_letter;
  HuffNode * leaf = NULL;
  HuffNode * nodetop = NULL;
  HuffNode * right = NULL;
  HuffNode * left = NULL;
  Stack * stacktop = NULL;
  
  unsigned int mask[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
  unsigned char command;
  unsigned char x= 0;
  unsigned char y= 0;
  unsigned char tempy= 0;
  int pos = 0;
  x = fgetc(input);
  
  while(finish == 0)
  {
    if(pos > 7)
    {
      pos = 0;
      x = fgetc(input);
    }
    command = mask[pos] & x;
    
    if(command != 0)//oh my god!! first I write command == 1 here, and it took me 2 hours to debug this unbelievable error!!!!
      
    {
      y = fgetc(input);
      tempy = y;
      x = x << (pos + 1);
      y = y >> (7 - pos);
      ch_letter = x | y;
      pos++;
      x = tempy;
      
      leaf = Huffnode_create(ch_letter);
      stacktop = Stack_push(stacktop, leaf);
    }
   
   if(command == 0)
    {
      if(pos > 7)
      {
	pos = 0;
	x = fgetc(input);
      }
      else
      {
	pos++;
        //x = fgetc(input);
      }
      
      right = stacktop -> node;
      stacktop = Stack_pop(stacktop);
      if(stacktop == NULL)
      {
	finish = 1;
	//return right
      }
      else
      {
	left = stacktop -> node;
	stacktop = Stack_pop(stacktop);
	nodetop = Huffnode_create(0);
	nodetop -> left = left;
	nodetop -> right = right;
	stacktop = Stack_push(stacktop, nodetop);
      }
    }
  }
  return right;
}




void Destroy_tree(HuffNode * tree)
{
  if(tree == NULL)
  {
    return;
  }
  Destroy_tree(tree -> left);
  Destroy_tree(tree -> right);
  free(tree);
}
      
      
      
      
      




