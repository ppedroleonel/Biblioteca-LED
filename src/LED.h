#ifndef LED_h                   // * se nao tiver definido LED_h (LED_h seria o nome da biblioteca, entao é so por a que eu quero)
#define LED_h                   // * definir LED_h

#include <Arduino.h>

/**
        *  @class Led
        * @brief Classe para controle não bloqueante de um LED.
        * 
        * Permite ligar, desligar, ligar por um tempo, 
        * piscar continuamente e piscar por quantidade definida.
        * 
        * @note  O método update() deve ser chamado continuamente no loop().
        */
class Led
{
    private:            // nao pode manipular nada que ta no private
        uint8_t pino;   // salva uma variavel com nome de PINO 
        bool estado;
        
        bool apagarNoTempo;
        uint32_t apagarNoMomento;
        bool estadoPiscar;
        
        uint32_t tempoEspera;
        uint32_t tempoAnteriorPiscar;
        uint16_t repeticoes;

        /**
         * @brief Processa o desligamento temporizado.
         */     
        void funcaoApagarNoTempo ();

        /**
         * @brief Processa a lógica da piscada do LED.
         */
        void funcaoPiscar();

        public:
        
        /**
         * @brief Constrói um objeto Led.
         * @param pin Número do pino digital onde o LED está conectado.
         */
        Led(uint8_t pin);
        
        /**
         * @brief Liga o LED continuamente.
         */
        void acender ();

        /**
         * @brief Liga o LED por um tempo determinado.
         * @param tempoLigado Tempo, em milissegundos, que o LED ficará ligado.
         */
        void acender(uint32_t tempoLigado);
        
        /**
         * @brief Desliga o LED e cancela modos automaticos.
         */
        void apagar();
        
        /**
         * @brief Pisca o LED a cada 500ms continuamente.
         */
        void piscar();

        /**
         * @brief Pisca o LED, atraves da quantidade de vezes que voce definiu por segundo.
         * @param freq A frequencia é a quantidade de vezes que o LED vai piscar por segundo.
         */
        void piscar(float freq);                    
        
        /**
         * @brief Pisca o LED, em uma certa quantidade de vezes que foi definida, além disso é repitida por uma quantidade definida.
         * @param freq  A frequencia é a quantidade de vezes que o LED vai piscar por segundo.
         * @param repeticoes Define quantas vezes o LED vai piscar.
         */
        void piscar(float freq, uint16_t repeticoes);
        
        /**
         * @brief Troca o estado do LED e desliga os modos automaticos.
         */
        void alternar();
        
        /**
         * @brief Define o estado do LED.
         * @param estado true para ligado, false para desligado.
         */
        void setEstado(bool estado);

        /**
         * @brief Atualiza as funções do LED e com base nisso define oq ele vai fazer com o LED.
         */
        void update();

        /**
         * @brief Pega qual o valor do pino do LED e retorna para você.
         */
        uint8_t getPino();//
};

#endif                      // * finaliza o primeiro IF