# Biblioteca LED

A Biblioteca "LED.h" foi criada com o intuito de facilitar o uso das funções básicas do LED.
 
 FUNCÕES BÁSICAS DO LED
 
 - Ligar, 
 - Desligar, 
 - Ligar por um determinado tempo,
 - Piscar continuamente, 
 - Piscar por uma quantidade definida, 
 - Piscar por uma frequencia equantidade definida; 
 
 Além disso gerencia as funções atraves do update() que sempre deve ser chamado no loop(). Tudo isso de uma forma não bloqueante pois, nessa biblioteca o controle do LED é feito de uma forma que substitui o uso do delay() por millis().


## ESTRUTURA DA BIBLIOTECA 

LED/
├── library.json
├── README.md
├── LICENSE
├── src/
│   ├── LED.h
│   └── LED.cpp
└── examples/