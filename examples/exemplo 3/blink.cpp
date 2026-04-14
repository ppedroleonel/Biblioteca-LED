/**
 * Exemplo pra demonstrar o blink do LED atraves da função piscar().
 */


#include <LED.h>

Led ledTeste(38);


void setup ()
{
  ledTeste.piscar();   // Pisca o LED.
}

void loop ()
{
  ledTeste.update();        // atualiza se o LED acende ou apaga.
}