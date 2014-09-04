#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrayList.h"

/*
 * Programmer:  Brandon C. Eason
 * UserID:      easonbc
 * Description:  This program implements a limited generic
 * ArrayList capable of storing one of three primitive types:
 * char, short, or int.  Written for CS3481 Fall 2014 - Lab 3.
 */

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/*
 * Function: initialize
 * Description:  Initialize the underlying structure and fields of
 * the ArrayList.
 * Param: type - the primitive type of elements to be stored
 * Returns: A pointer to the arrayList struct
 */
arrayList * initialize(primitiveType type)
{
   int size = getSize(type);
   arrayList * list = malloc(sizeof(arrayList));
   list->array = malloc(4 * size);
   list->elementSize = size;
   list->numElements = 0;
   list->arraySize = 4;
   list->type = type;
   return list;
}

/*
 * Function: getSize
 * Description:  Returns the number of bytes in a variable of the
 * given type.
 * Param: type - the primitive type of element
 * Returns:  The size in bytes of a variable of the given type.
 */
int getSize(primitiveType type)
{
   if (type == charType)
   {
       return sizeof(char);
   }
   else if (type == shortType)
   {
       return sizeof(short);
   }
   else
   {
    return sizeof(int);
   }
}

/*
 * Function: addElement
 * Description: Add an element to the end of the ArrayList.
 * Param: arylstP - a pointer to the ArrayList
 * Param: element - a pointer to the element to be added
 */
void addElement(arrayList * arylstP, void * element)
{
   if (arylstP->numElements == arylstP->arraySize)
   {
       int size = arylstP->elementSize * arylstP->arraySize;
       void * array = malloc(2 * size);
       memcpy(array, arylstP->array, sizeof(arylstP->array));
       free(arylstP->array);
       arylstP->array = array;
       arylstP->arraySize *= 2;
   }
   primitiveType type = arylstP->type;
   int index = arylstP->numElements;
   if (type == charType)
   {
       char * array = (char *)arylstP->array;
       array[index] = *(char *)element;
   }
   else if (type == shortType)
   {
       short * array = (short *)arylstP->array;
       array[index] = *(short *)element;
   }
   else
   {
       int * array = (int *)arylstP->array;
       array[index] = *(int *)element;
   }    
   arylstP->numElements++;
   return;
}

/*
 * Function: removeElement
 * Description: Remove the element at index from the ArrayList.
 * Param: arylstP - a pointer to the ArrayList
 * Param: index - the index of the element to be removed
 */
void removeElement(arrayList * arylstP, int index)
{
   int i;
   void * array = arylstP->array;
   for (i = index; i < arylstP->numElements; i++)
   {
       if (arylstP->type == charType)
       {
           ((char *)array)[i] = ((char *)array)[i + 1];            
       }
       else if (arylstP->type == shortType)
       {
           ((short *)array)[i] = ((short *)array)[i + 1];
       }
       else
       {
           ((int *)array)[i] = ((int *)array)[i + 1];
       }
   }
   arylstP->numElements--;
   return;
}
      
/*
 * Function: printArray
 * Description: Print the elements in the ArrayList.
 * Param: arylstP - a pointer to the ArrayList
 */
void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff);
   }
   printf("\n");
}

