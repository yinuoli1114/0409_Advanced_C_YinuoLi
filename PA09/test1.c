#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
  if (argc < 2)
    {
      return EXIT_FAILURE;
    }
  FILE * fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      return EXIT_FAILURE;
    }
  while (! feof (fptr))
    {
      unsigned char onebyte = fgetc(fptr);
      int loc; // location of the bit
      //int onebyte = 255;
      unsigned char mask = 128;
      for (loc = 0; loc < 8; loc ++)
    {
      if ((onebyte & mask) == 0)
        {
          printf("0 ");
        }
      else
        {
          printf("1 ");
        }
      mask >>= 1; // shift right
    }
      printf(" ### onebyte = %d %c\n", onebyte, onebyte);
    }
  fclose (fptr);
  return EXIT_SUCCESS;
}