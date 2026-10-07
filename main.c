/*-------------------------------------------------------------------------*
 *---                                                                    ---*
 *---              main.c                                                ---*
 *---                                                                    ---*
 *---     This file defines the function swap()                          ---*
 *---     needed for the program of assignment 1.                        ---*
 *---                                                                    ---*
 *---     ----    ----    ----    ----    ----    ----    ----    ----    ---*
 *---                                                                    ---*
 *---     Version 1a                                      Joseph Phillips  ---*
 *---                                                                    ---*
 *-------------------------------------------------------------------------*/

#include "header.h"

const int TEXT_LEN = 256;


//  PURPOSE:  To swap the ints in 'array[]' at indices 'index0' and 'index1'.
//    No return value.
void swap(int* array,
          int index0,
          int index1
         )
{
  int temp = array[index0];

  array[index0] = array[index1];
  array[index1] = temp;
}


//  PURPOSE:  To repeatedly ask the user the text "Please enter ", followed
//    by the text in 'descriptionCPtr', followed by the numbers 'min' and
//    'max', and to get an entered integer from the user.  If this entered
//    integer is either less than 'min', or is greater than 'max', then
//    the user is asked for another number.  After the user finally enters
//    a legal number, this function returns that number.
int obtainIntInRange(const char* descriptionCPtr,
                     int min,
                     int max
                    )
{
  int entry;
  char text[TEXT_LEN];

  do
  {
    printf("Please enter %s (%d-%d): ",
           descriptionCPtr,min,max);

    scanf("%d",&entry);
  }
  while ((entry < min) || (entry > max));

  return(entry);
}


//  PURPOSE:  To generate the array of integer.
int* generateIntArray(int numInts
                     )
{
  int* array = (int*)calloc(numInts,sizeof(int));
  int i;
  int j;

  for (i = 0; i < numInts; i++)
  {
    array[i] = rand()/4096;
  }

  return(array);
}


void print(int* array,
           int arrayLen
          )
{
  int i;
  int j;

  for (i = 0; i < arrayLen; i++)
  {
    printf("%d\n",array[i]);
  }

}


void releaseMem(int* array,
                int arrayLen
               )
{
  free(array);
}


int main()
{
  int arrayLen;
  int* array;
  int choice;

  arrayLen = obtainIntInRange("number of integers",1,65536*16);
  choice = obtainIntInRange("1 for bubble sort or 2 for quicksort",1,2);
  array = generateIntArray(arrayLen);

  switch (choice)
  {
  case 1:
    bubbleSort(array,arrayLen);
    break;

  case 2:
    quickSort(array,arrayLen);
    break;
  }

  print(array,arrayLen);
  releaseMem(array,arrayLen);
  return(EXIT_SUCCESS);
}
