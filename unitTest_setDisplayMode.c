/* Author: jinye xu
 * ID: cs30xen
 * Filename: unitTest_setDisplayMode.c
 * Unit Test for setDisplayMode.c
 *
 * unsigned int setDisplayMode(int argc, char * argv[]);
 *
 *  
 */



#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

#include <string.h>

#include "myls.h"
#include "test.h"


void
testsetDisplayMode(){

  
  unsigned int result;
  int argc;
  char* argv[10];
  
  argc=2;
  argv[0]="fileName";
  argv[1]="-a";


  result=setDisplayMode(argc,argv);
  printf("\n%d\n",result);
  TEST(result==AFLAG);
  
  optind=1;
  result=0;
  argc=4;
  argv[1]="-S";
  argv[2]="-a";
  argv[3]="-r";
  result=setDisplayMode(argc,argv);
  printf("\n%d\n",result);


  TEST(result&SFLAG==SFLAG);
  TEST(result&RFLAG==RFLAG);
  TEST(result&AFLAG==AFLAG);


  optind=1;
  result=0;
  argc=2;
  argv[1]="-z";
  result=setDisplayMode(argc,argv);

  TEST(result==ERR_FLAG);

}


int main(){
  (void)fprintf(stdout,"Running tests for setDisplayMode.\n");
  testsetDisplayMode();
  (void)fprintf(stdout,"Done running tests!\n");
  
  return 0;
}
