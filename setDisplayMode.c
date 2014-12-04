/*
 * Filename: setDisplayMode.c
 * Author: jinye xu
 * Description: getting the information from the command line and setting
 *              the displayMode accordingly
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


/*
 * Function name: setDisplayMode()
 * Function prototype: unsigned int setDisplayMode(int argc, char* argv[]);
 * Description: setDisplayMode()'s job is to parse the command-line options with getOpt(), 
 *              and set the necessary flags in an unsigned int variable by turning on bits 
 *              of this variable to signify which command line options have been entered.
 * Parameters: int argc, char* argv[] 
 * Side Effects: Outputs the int result with all the bits set accordingly
 * Error Conditions: When the input commands are not recognized, errflag would be set.
 * Return Value: result that stores all the flags parsed from command line.
 */


unsigned int
setDisplayMode(int argc, char* argv[]){

  char input;
  unsigned int result;
  result=0;


  while((input=getopt(argc,argv,OPTIONS))!=-1){

    switch(input){

      case 'a':
        result=result|AFLAG;
        break;

      case 'l':
        result=result|LFLAG;
        break;

      case 'r':
        result=result|RFLAG;
        break;

      case 'B':
        result=result|BFLAG;
        break;

      case 'S':
        result=result|SFLAG;
        break;


      default:
        result=result|ERR_FLAG;
        return result;
        break;
    }


  }

return result;

}

