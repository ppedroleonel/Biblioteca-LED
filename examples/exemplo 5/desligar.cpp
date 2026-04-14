/**
 * Exemplo pra demonstrar o blink do LED atraves da função piscar() com parametro de frequencia.
 */


#include <LED.h>

Led ledTeste(38);


void setup ()
{
  ledTeste.piscar(30);  // Pisca o LED 30 vezes por segundo
}

void loop ()
{
  ledTeste.update();        // atualiza se o LED acende ou apaga.
}