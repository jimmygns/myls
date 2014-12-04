/*
 * Filename: buildFileInfoTable.c
 * Author: jinye xu
 * Date: Nov. 29
 * Source of Help: Piazza, stackOverflow
 */


#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "strings.h"
#include "myls.h"


/*
 * Function name: buildFileInfoTable()
 * Function prototype: int buildFileInfoTable( const char *filename, struct fileInfo ** const tablePtr );
 * Description: buildFileInfoTable() takes the file/directory name and the address of 
 *              the pointer to struct fileInfo back in main() that we will fill in based on 
 *              our dynamic building of this fileInfo table.
 * Parameters: const char *filename, struct fileInfo ** const tablePtr.
 * Side Effects: Outputs an int that counts the number of directories and files  
 * Error Conditions: the filename is illegal or there are too many arguments
 * Return Value: int count that represents the number of files or directories in filename
 */


int
buildFileInfoTable(const char *filename, struct fileInfo ** const tablePtr){
  
  //file infomation
  struct stat stbuf;
  struct fileInfo *file;
  
  //is a directory
  DIR * dir;
  struct dirent *subDir;

  int count=0; 

  
  if(lstat(filename,&stbuf)==-1){
    (void)fprintf(stderr,STR_LSTAT_ERR);
    perror(filename);
    return 0;
    
  }

  if(S_ISDIR(stbuf.st_mode)!=1){
    file=(struct fileInfo *)malloc(sizeof(struct fileInfo));
    
    //allocation error
    if(file==NULL){
      (void)fprintf(stderr,STR_ALLOC_ERR);
      return 0;
    }
    file[0].stbuf=stbuf;
    (void)strncpy(file[0].name,filename,MAXNAMLEN);
    *tablePtr=file;

    return 1;

  }

  if(S_ISDIR(stbuf.st_mode)==1){
    dir=opendir(filename);
    
    //cannot open the directory(directory err)
    if(dir==NULL){
      (void)fprintf(stderr,STR_OPENDIR_ERR);
      perror(filename);
      return 0;
    }
    
    file=(struct fileInfo *)malloc(sizeof(struct fileInfo));


    if(file==NULL){
      (void)fprintf(stderr,STR_ALLOC_ERR);
      return 0;
    }

    while((subDir=readdir(dir))!=NULL){
       char str[MAXNAMLEN];
       char *strPtr;
       struct fileInfo *fileCpy;
       strncpy(str,filename,MAXNAMLEN);
       strcat(str,"/");
       strcat(str,subDir->d_name);
       strPtr=str; 

       if(lstat(str,&stbuf)==-1){
         (void)fprintf(stderr,STR_LSTAT_ERR);
         perror(strPtr);
         return 0;
    
       }
       
       fileCpy=file;
       file=realloc(file,sizeof(struct fileInfo)*(count+1));

       if(file==malloc(sizeof(struct fileInfo))){
         (void)fprintf(stderr,STR_ALLOC_ERR);
         (void)fprintf(stderr,STR_PARTIAL_INFO);
         (void)strncpy(fileCpy[count].name,subDir->d_name,MAXNAMLEN);
         fileCpy[count].stbuf=stbuf;
         *tablePtr=fileCpy;
         return count;
       }
       
       
       (void)strncpy(file[count].name,subDir->d_name,MAXNAMLEN);
       file[count].stbuf=stbuf;

       count++;

    }
    //end of the while loop
    *tablePtr=file;
    return count;

  }
  //end of isdir if statement

  return 1;
  
}
