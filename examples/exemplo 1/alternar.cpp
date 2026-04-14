/**
 * Exemplo para demonstrar a troca do estado do LED, fazendo ele piscar so alternando
 */

#include <Arduino.h>
#include <LED.h>

const char pinBotaoBoot = 0;
Led ledTeste(38);

void setup ()
{
  
}

void loop()
{
  ledTeste.alternar();  // alterna o estado
  ledTeste.update();    // atualização para ver se acende ou desliga o LED
  delay(1000);
}