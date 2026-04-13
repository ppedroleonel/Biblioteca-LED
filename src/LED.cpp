#include "LED.h"
/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * 
 * Permite ligar, desligar, ligar por um tempo, 
 * piscar continuamente e piscar por quantidade definida.
 * 
 * @note 
 */
Led::Led(uint8_t pin) :            //* O PRIMEIRO LED FALA SOBRE A CLASSE (CLASS)  E O SEGUNDO FALA SOBRE O METODO CONSTRUTOR (public)
    pino(pin),
    estado(LOW),
    apagarNoTempo(false),
    apagarNoMomento(false),
    estadoPiscar(false),
    tempoEspera(0),
    tempoAnteriorPiscar(0),
    repeticoes(0)
    {
        pinMode(pino, OUTPUT);
    }

void Led::acender()
{
    estado = HIGH;
    apagarNoTempo = false;
    estadoPiscar = false;
}
void Led::acender(uint32_t tempoLigado)
{
    apagarNoMomento = millis() + tempoLigado;
    apagarNoTempo = true;
    estadoPiscar = false;
}

void Led::apagar()
{
    estado = LOW;
    apagarNoTempo = false;
    estadoPiscar = false;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::alternar()
{
    estado = !estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::setEstado(bool estado)
{
    this -> estado = estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::update()
{
    if(apagarNoTempo) funcaoApagarNoTempo();
    if(estadoPiscar)  funcaoPiscar();

    digitalWrite(pino, estado);
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;                // * todos q ta com essa linha, serve pra nao desligar
}

void Led::piscar(float freq)
{
    if(freq == 0)
    {
        return;   // isso serve pra ele nao bugar qnd definir a freq pra 0 pois zero tende ao infinito
    } 
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * freq)); //* esse 0.f fala q os numeros sao floats
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}

void Led::piscar(float freq, uint16_t repeticoes)
{
     if(freq == 0)
    {
        return;   // isso serve pra ele nao bugar qnd definir a freq pra 0 pois zero tende ao infinito
    }
    
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * freq)); //* esse 0.f fala q os numeros sao floats
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
    apagarNoTempo = false;
}

void Led::funcaoApagarNoTempo()
{
    if (millis() >= apagarNoMomento)
    {
        estado = LOW;
        apagarNoTempo = false;
    }
}

void Led::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}
