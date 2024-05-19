# IoT-Pulse-Sensor
- Sensor de batimentos cardiacos programado na IDE do Arduino.
- Projeto desenvolvido para a matéria de Objetos Inteligentes Conectados (IoT), Quinto Semestre do curso Análise e Desenvolvimento de Sistemas.

## Funcionamento 
- Este projeto consiste em um dispositivo que mede os batimentos cardíacos de uma pessoa utilizando um sensor de pulso conectado a um microcontrolador ESP8266. Os batimentos cardíacos são medidos através das variações no sinal captado pelo sensor. O dispositivo se conecta à rede WiFi e envia os dados de frequência cardíaca para um servidor MQTT. Além disso, o dispositivo controla um buzzer para fornecer feedback audível com base na frequência cardíaca medida.


## Documentação
- [Como reproduzir](docs/reproduce.md)
- [Descrição do Hardware](docs/hardwaredescription.md)
- [Código](batimentos_iot.ino)
- [Interfaces, Protocolos e Módulos de Comunicação](docs/communication.md)

## Estrutura do Código
- setup(): Configura os pinos e estabelece conexão WiFi e MQTT.
- loop(): Lê os dados do sensor de pulso, calcula os BPM, publica os dados via MQTT e controla o buzzer.
- publicarBatimentosNoTopico(): Publica os dados de BPM no tópico MQTT.
- reconnectMQTT(): Reestabelece a conexão MQTT em caso de desconexão.

## Lógica do Sensor
- O sensor de pulso está conectado ao pino A0. O valor do sinal é lido e comparado com um limiar (Threshold) para detectar batimentos. O tempo entre os batimentos é usado para calcular os BPM.

## Controle do Buzzer
- O buzzer é ativado quando os BPM estão entre 60 e 100, emitindo um som a cada segundo.

## Protocolo MQTT
- O MQTT é um protocolo de mensagens leve e de baixa largura de banda, ideal para dispositivos conectados à Internet das Coisas (IoT). Ele opera sobre o protocolo TCP/IP e utiliza o conceito de publicação e subscrição para troca de mensagens entre dispositivos.
- No contexto deste projeto, o protocolo MQTT é utilizado para enviar os dados de frequência cardíaca do dispositivo para um servidor MQTT hospedado no [HiveMQ](https://www.hivemq.com/demos/websocket-client/), permitindo sua visualização e processamento remotos.
- [Conectar pelo HiveMQ](docs/hivemq.md)
