#include <stdio.h>
#include <unistd.h>

int main(void)
{
  printf("hello world");
  while(1) {
    sleep(1);
  }
  return 0;
}

