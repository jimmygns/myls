/*
 * Filename: myls.c
 * Author: jinye xu
 * Date: Nov. 29
 * Source of Help: Piazza, stackOverflow
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
 * Function name: main()
 * Function prototype: int main(int argc, char* argv[]); 
 * Description: C main driver which calls all functions and display all the
 *              messages and files according to the inputs
 * Parameters: int argc, char* argv[] 
 * Side Effects: display the files and all the informations accordingly
 * Error Conditions: display error messages when the input is not valid
 * Return Value: int
 */


int
main(int argc, char* argv[]){

  unsigned int flags=setDisplayMode(argc, argv);

  if((flags&ERR_FLAG)==ERR_FLAG){
    (void)fprintf(stderr,STR_USAGE,argv[0]);
    return 0;
  }
  
  struct fileInfo** const table=(struct fileInfo **const)malloc(
                                      sizeof(struct fileInfo));
  int counts=0;
  char *filename;

  if(argv[optind]==NULL){
    filename=".";
    counts=buildFileInfoTable(filename,table);  
    displayFileInfo(*table,counts,flags);
    (void)free(*table);
  }

  else{
    int index=optind;
    while(argv[index]!=NULL){
      filename=argv[index];
      counts=buildFileInfoTable(filename,table);
      displayFileInfo(*table,counts,flags);
      index++;
      (void)free(*table);

    }
  }
  return 0;
}
