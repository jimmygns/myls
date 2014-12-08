/*
 * Filename: displayPermissions.c
 * Author: jinye xu
 * Date: Nov. 29
 * Source of Help: Piazza, stackOverflow
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "strings.h"
#include "myls.h"
#include "globals.c"

/*
 * Function name: displayPermissions()
 * Function prototype: void displayPermissions( const mode_t mode ); 
 * Description: This routine prints out the various rwx permissions 
                for the owner, group, and others.
 * Parameters: const mode_t mode
 * Side Effects: display the permission of a certain file
 * Error Conditions: none
 * Return Value: none
 */


void 
displayPermissions( const mode_t mode){

  //owner's permissions
  if(mode&S_IXUSR)
    (void)fprintf(stdout,"x");
  else
    (void)fprintf(stdout,"-");

  if(mode&S_IRUSR)
    (void)fprintf(stdout,"r");
  else
    (void)fprintf(stdout,"-");

  if(mode&S_IWUSR)
    (void)fprintf(stdout,"w");
  else
    (void)fprintf(stdout,"-");
  

  //group's permissions
  if(mode&S_IXGRP)
    (void)fprintf(stdout,"x");
  else
    (void)fprintf(stdout,"-");

  if(mode&S_IRGRP)
    (void)fprintf(stdout,"r");
  else
    (void)fprintf(stdout,"-");

  if(mode&S_IWGRP)
    (void)fprintf(stdout,"w");
  else
    (void)fprintf(stdout,"-");
   

  //other's permissions
  if(mode&S_IXOTH)
    (void)fprintf(stdout,"x");
  else
    (void)fprintf(stdout,"-");

  if(mode&S_IROTH)
    (void)fprintf(stdout,"r");
  else
    (void)fprintf(stdout,"-");

  if(mode&S_IWOTH)
    (void)fprintf(stdout,"w");
  else
    (void)fprintf(stdout,"-");
  




}
