/**
 * Exemplo pra demonstrar o blink do LED sem delay atraves do botão. 
 * Demonstra Tambem o uso das funções update() e piscar() com os parametros de repeticoes e frequência.
 */


#include <LED.h>

Led ledTeste(38);
const char pinBotao = 0;

void setup ()
{
  pinMode(pinBotao, INPUT_PULLUP);
}

void loop ()
{
  ledTeste.update();

  bool estadoAtualBotao = digitalRead(pinBotao);
  static bool estadoAnteriorBotao = HIGH;

  if(!estadoAtualBotao && estadoAnteriorBotao)
  {
    ledTeste.piscar(6,4);   // pisca o LED 6 vezes por segundo num ciclo de 4 repeticões.
  }
  estadoAnteriorBotao = estadoAtualBotao;

}