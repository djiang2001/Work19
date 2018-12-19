#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while(1){
  printf("Input message: \n");

  char input[BUFFER_SIZE];
  fgets(input,BUFFER_SIZE,stdin);

  }
}
