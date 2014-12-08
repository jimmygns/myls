/*
 * Filename: displayFileInfo.c
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
#include <time.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/mkdev.h>
#include <dirent.h>
#include <stddef.h>
#include <signal.h>
#include <setjmp.h>


#include "strings.h"
#include "myls.h"
#include "globals.c"


/*
 * Function name: displayFileInfo()
 * Function prototype: void displayFileInfo( struct fileInfo * const table,
 const int entries, const int displayMode);
 * Description: display all the specified information of the files parsed in
 *              as struct fileInfo. This function also calls other functions 
 *              according to the moode parsed in.
 * Parameters: struct fileInfo * const table is the first argument which contains
 *             all the information about a specific file or directory.
 *             const int entries indicates how my files inside the directory
 *             const int displayMode gives the instructions on what information
 *             should be displayed and in which order should them be printed to 
 *             the terminal.
 * Side Effects: Outputs the information about files indicated
 * Error Conditions: When err_flag is set. usage error message will be printed
 * Return Value: none
 */

  void 
displayFileInfo(struct fileInfo * const table, const int entries
    , const int displayMode)
{
  
  offset=offsetof(struct fileInfo,stbuf.st_size); 
  //determining the sorting order
  if((displayMode&SFLAG)==SFLAG){
    if((displayMode&RFLAG)==RFLAG){
      qsort(table,entries,sizeof(struct fileInfo),sizeSortAscending);
    }
    else{
      qsort(table,entries,sizeof(struct fileInfo),sizeSortDescending); 
    }
  }
  else{
    if((displayMode&RFLAG)==RFLAG)
      qsort(table,entries,sizeof(struct fileInfo),nameSortDescending);
    else
      qsort(table,entries,sizeof(struct fileInfo),nameSortAscending);
  }

  //looping through the table
  int index;

  int printSize=0;
  for(index=0;index<entries;index++){

    char* base;
    base=basename(table[index].name);
    char firstChar=*base;
    if(firstChar=='.'&&((displayMode&AFLAG)!=AFLAG)){
      continue;
    }
    if((displayMode&BFLAG)==BFLAG){
      char endChar=base[strlen(base)-1];
      if(endChar=='~')
        continue;
    }

    if((displayMode&LFLAG)==LFLAG){

      //cases for file property 
      if(S_ISDIR(table[index].stbuf.st_mode)){
        (void)fprintf(stdout,"d");
      }

      else if(S_ISLNK(table[index].stbuf.st_mode)){
        (void)fprintf(stdout,"l");
      }

      else if(S_ISBLK(table[index].stbuf.st_mode)){
        (void)fprintf(stdout,"b");
        printSize=1;
      }

      else if(S_ISCHR(table[index].stbuf.st_mode)){
        (void)fprintf(stdout,"c");
        printSize=1;
      }
      else{
        (void)fprintf(stdout,"-");

      }
      //end of file property


      displayPermissions(table[index].stbuf.st_mode);

      (void)fprintf(stdout," ");

      (void)fprintf(stdout,STR_NLINK,table[index].stbuf.st_nlink);

      displayOwnerName(table[index].stbuf.st_uid);

      displayGroupName(table[index].stbuf.st_gid);

      if(printSize==1){
        (void)fprintf(stdout,STR_MAJOR_MINOR,(long int)major(table[index].stbuf.st_rdev),
            (long int)minor(table[index].stbuf.st_rdev));

      }
      else{
        (void)fprintf(stdout,STR_SIZE,table[index].stbuf.st_size);
      }

      char* timer=ctime(&(table[index].stbuf.st_mtime));


      time_t myTime=time(NULL);
      time_t fileTime=table[index].stbuf.st_mtime;


      if(fileTime<(myTime-15724800)){
        char* start=strchr(timer,' ')+1;
        char* year=strrchr(timer,' ')+1;
        char* end=start+6;
        *end=NULL;
        (void)fprintf(stdout," %s",year);

      }
      else{
        char* start=strchr(timer,' ')+1;
        char* end=strrchr(timer,':');
        *end=NULL;     
        (void)fprintf(stdout,"%s ",start);
      } 
    }
    //end of LFLAG
    (void)fprintf(stdout,"%s\n",table[index].name);

  }
  //end of for loop

}




