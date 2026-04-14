/**
 * Exemplo pra demonstrar como ligar o LED atraves da função acender().
 */


#include <LED.h>

Led ledTeste(38);


void setup ()
{
  ledTeste.acender();  
}

void loop ()
{
  ledTeste.update();
}