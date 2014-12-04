/* Author: jinye xu
 * ID: cs30xen
 * Filename: unitTest_sizeSortAscending.c
 * Unit Test for sizeSortAscending.s
 * 
 *
 *  
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <setjmp.h>

#include <string.h>

#include "myls.h"
#include "test.h"
#include "global.c"

void unitTest_sizeSortAscending(){

  int result;
  result=0;
  struct fileInfo file1;
  struct fileInfo file2;
  
  struct stat stbuf;
  offset=offsetof(struct fileInfo,stbuf.st_size);
  
  file1.stbuf.st_size=100;
  file2.stbuf.st_size=200;
  
  result=sizeSortAscending(&file1,&file2);
  TEST(result<0);

  file1.stbuf.st_size=200;
  
  result =sizeSortAscending(&file1,&file2);
  TEST(result==0);


}

int main(){
 (void)fprintf(stdout,"Running tests for sizeSortAscending.\n");
 unitTest_sizeSortAscending();
 (void)fprintf(stdout,"Done running tests!\n");

 return 0;
}

