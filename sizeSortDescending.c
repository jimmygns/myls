/*
 * Filename: sizeSortDescending.c
 * Author: jinye xu
 * Description: comparing the size of two files and return an integer
 * Date: Nov. 29
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "strings.h"
#include "myls.h"
#include "globals.c"


/*
 * Function name: sizeSortDecending()
 * Function prototype: int sizeSortDescending( const void *p1, const void *p2 );
 * Description: The function takes two pointers as arguments. It then compares 
 *              the st_size memember by searching into the memory address. It
 *              returns a number that indicates which argument holds a bigger file.
 * Side Effects: output an int which indicates the result of comparison
 * Error Conditions: none
 * Return Value: negative for arg1>arg2, zero for arg1=arg2, positive for arg1>arg2
 */


int 
sizeSortDescending(const void *p1, const void *p2){
  
  int result=0;

  result=((struct fileInfo* )p2)->stbuf.st_size -
         ((struct fileInfo* )p1)->stbuf.st_size;
  return result;

}
