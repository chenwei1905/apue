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
  // 打开文件

  fdin = open(argv[1], O_RDONLY);
<<<<<<< HEAD
  // use lseek print file length 
  //  printf("file length: %ld\n", lseek(fdin, 0L, SEEK_END));
  
=======
  //使用lseek确定文件的大小
  printf("file length: %ld\n", lseek(fdin, 0L, SEEK_END));
>>>>>>> 10b186df46341588f30ce8509dfc53d247921188
  if (fdin < 0) {
    fprintf(stderr, "open error: %s\n",
	    strerror(errno));
    exit(1);
  } else {
    printf("open file: %d\n", fdin);
  }
  //写入文件
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
