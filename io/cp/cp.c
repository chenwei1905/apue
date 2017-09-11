#include "io.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "usage: %s srcfile destfile\n",
	    argv[0]);
    exit(1);
  }

  int fdin, fdout;
  // open a only-read file

  fdin = open(argv[1], O_RDONLY);
  if (fdin < 0) {
    fprintf(stderr, "open error: %s\n",
	    strerror(errno));
    exit(1);
  } else {
    printf("open file: %d\n", fdin);
  }
  //write a file
  fdout =open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);

  if (fdout < 0) {
    fprintf(stderr, "open error: %s\n",
	    strerror(errno));
    exit(1);
  } else {
    printf("open file: %d\n", fdout);
  }
  //copy 
  copy(fdin, fdout);
  
  close(fdin);
  close(fdout);
  return 0;
  
}
