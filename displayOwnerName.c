/*
 * Filename: displayOwnerName.c
 * Author: jinye xu
 * Date: Nov. 29
 * Source of Help: Piazza, stackOverflow
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "strings.h"
#include "myls.h"
#include "globals.c"

/*
 * Function name: displayOwnerName()
 * Function prototype: void displayOwnerName( const uid_t uid ); 
 * Description: This function prints either the numeric value of uid or 
                the owner's name got from the uid.
 * Parameters: const uid_t uid
 * Side Effects: display the value of uid or owner's name
 * Error Conditions: none
 * Return Value: none
 */

void 
displayOwnerName( const uid_t uid){
  
  struct passwd *pwd;
  pwd=getpwuid(uid);

  if(pwd==NULL){
    (void)fprintf(stdout,STR_UID,uid);

  }
  else
    (void)fprintf(stdout,STR_PWNAME,pwd->pw_name);


}
