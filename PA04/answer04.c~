/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */



void partition(int *result, int ind, int left);
void printPartition(int *part, int length);
void partition_increase(int *result, int ind, int left);
void partition_decrease(int *result, int ind, int left);
void partition_odd(int *result, int ind, int left);
void partition_even(int *result, int ind, int left);
void partition6(int *result, int ind, int left);
void partition7(int *result, int ind, int left);
int prime(int val);

void partitionAll(int value)
{
  int *arr = malloc(sizeof(int) * (100000));
  printf("partitionAll %d\n", value);
  partition(arr, 0, value);
  free(arr);
}
  void printPartition(int *part, int length)
  { 
    int ind = 0;
    printf("=");
    for(ind = 0; ind < length - 1; ind++)
    {
      printf(" %d +", part[ind]);
    }
    printf(" %d\n", part[length - 1]);
  }
  void partition(int *result, int ind, int left)
  
  {    int val = 0;
    if(left == 0)
    {
      printPartition(result, ind);
    }
    for(val = 1; val <= left; val++)
    {
      
      
      result[ind] = val;
      partition(result, ind + 1, left - val);
      
    }
  }
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionIncreasing(int value)
{
  int *arr = malloc(sizeof(int) * (100000));
  printf("partitionIncreasing %d\n", value);
  partition_increase(arr, 0, value);
  free(arr);
}

  
  void partition_increase(int *result, int ind, int left)
  
  {    
    int val = 0;
    if(left == 0)
    {
      printPartition(result, ind);
      return;
    }
    for(val = 1; val <= left; val++)
    {
      
      
       result[ind] = val;
       if(val > result[ind - 1] || ind == 0)
      {
       partition_increase(result, ind + 1, left - val);
      
      
      }
    }
  }

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionDecreasing(int value)
{
  int *arr = malloc(sizeof(int) * (100000));
  printf("partitionDecreasing %d\n", value);
  partition_decrease(arr, 0, value);
  free(arr);

}
 void partition_decrease(int *result, int ind, int left)
  
  {    
    int val = 0;
    if(left == 0)
    {
      printPartition(result, ind);
      return;
    }
    for(val = 1; val <= left; val++)
    {
      
      
       result[ind] = val;
       if(val < result[ind - 1] || ind == 0)
      {
       partition_decrease(result, ind + 1, left - val);
      
      
      }
    }
  }


/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOdd(int value)
{
  printf("partitionOdd %d\n", value);
  int *arr = malloc(sizeof(int) * (100000));
  partition_odd(arr, 0, value);
  free(arr);
}
void partition_odd(int *result, int ind, int left)
  
  {    
    int val = 0;
    if(left == 0)
    {
      printPartition(result, ind);
      return;
    }
    for(val = 1; val <= left; val++)
    {
      
      
       result[ind] = val;
       if(val % 2 == 1)
      {
       partition_odd(result, ind + 1, left - val);
      
      
      }
    }
  }


/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEven(int value)
{
  printf("partitionEven %d\n", value);
  int *arr = malloc(sizeof(int) * (100000));
  partition_even(arr, 0, value);
  free(arr);
}
void partition_even(int *result, int ind, int left)
  
  {    
    int val = 0;
    if(left == 0)
    {
      printPartition(result, ind);
      return;
    }
    for(val = 1; val <= left; val++)
    {
      
      
       result[ind] = val;
       if(val % 2 == 0)
      {
       partition_even(result, ind + 1, left - val);
      }
    }
  }

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  int *arr = malloc(sizeof(int) * (100000));
  partition6(arr, 0, value);
  free(arr);
}
void partition6(int *result, int ind, int left)
  
  {    
    int val = 0;
    if(left == 0)
    {
      printPartition(result, ind);
      return;
    }
    for(val = 1; val <= left; val++)
    {
      
      
       result[ind] = val;
       if(val % 2 != ind % 2)
      {
       partition6(result, ind + 1, left - val);
      }
    }
  }

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */



void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);
  int *arr = malloc(sizeof(int) * (100000));
  partition7(arr, 0, value);
  free(arr);
}
int prime(int val)
{
  int i;
  int pri = 1;
  if(val == 1)
  {
    pri = 0;
  }
  for(i = 2; i < val; i++)
  {
    if(val % i == 0)
    {
      pri = 0;
    }
  }
  return pri;
}
    
  
  
  void partition7(int *result, int ind, int left)
  
  {    int val = 0;
    if(left == 0)
    {
      printPartition(result, ind);
    }
    for(val = 1; val <= left; val++)
    {
      if(prime(val) == 1)
      {
      result[ind] = val;
      partition7(result, ind + 1, left - val);
      }
    }
  }

