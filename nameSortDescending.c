
/* Filename:  nameSortDescending.c
 * Author: jinye xu
 * Description: order by their name
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
 * Function name: nameSortDescending()
 * Function prototype: int nameSortDescending(const void *p1,const void *p2)
 * Description: This function compare the name of fileInfo that was hold
 *               by two pointer arguments. It return an integer so that 
 *               we can use qsort to sort them alphabetically later.
 * Side Effects: outputs an int which indicates the order of these two elements
 * Error Conditions: none
 * Return Value: negative for p1 is before p2, zero for they have the same name,
 *               positive for p1 is after p2
 */

int nameSortDescending(const void *p1, const void *p2){
  int result=0;

  result=strcmp(((struct fileInfo* )p2)->name,
         ((struct fileInfo* )p1)->name);
  
  
  return result;

}


