
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

int gotdata = 0;
void signalhandler(int sigio)
{
  if(sigio == SIGIO)
    gotdata++;
  return;
}

char buffer[4096];

int main(int argc, char **argv)
{
  int count;
  struct sigaction action;
  
  memset(&action, 0, sizeof(action));
  action.sa_handler = signalhandler;
  action.sa_flags = 0;
  
  sigaction(SIGIO, &action, NULL);
  
  while(1) {
    /* this only returns if a signal arrives */
    sleep(86400); /* one day */
    if(!gotdata)
      continue;
    count = read(0, buffer, 4096);
    /* buggy: if avail data is more than 4k bytes ... */
    write(1, buffer, count);
    gotdata = 0;
  }
}