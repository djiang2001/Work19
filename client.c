#include "pipe_networking.h"


int main() {
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char input[BUFFER_SIZE];
  char output[BUFFER_SIZE];

  while(1){
  printf("Input message: ");


  fgets(input,BUFFER_SIZE,stdin);
  input[strlen(input) -1] = '\0';

  write(to_server,input,BUFFER_SIZE);
  read(from_server, output, BUFFER_SIZE);
  
  printf("Server response: %s \n", output);
  }
}
