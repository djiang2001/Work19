#include "pipe_networking.h"
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    remove("wkp");
    exit(0);
  }
}



int main() {
  
  signal(SIGINT, sighandler);

  int to_client;
  int from_client;

  while(1){
    from_client = server_handshake( &to_client );
    char msg[BUFFER_SIZE];

    while(read(from_client,msg,BUFFER_SIZE)){
      printf("Server message: %s \n", msg);
      strcat(msg, " is not here");
      write(to_client,msg,BUFFER_SIZE);
    }
  }
}
