# IoT-Pulse-Sensor
- Sensor de batimentos cardiacos programado na IDE do Arduino.
- Projeto desenvolvido para a matéria de Objetos Inteligentes Conectados (IoT), Quinto Semestre do curso Análise e Desenvolvimento de Sistemas.

## Como usar
- Instale a IDE do Arduino
- Adicione a placa NodeMcu nas preferências da IDE.
- Instale a Biblioteca PubSubClient via Biblioteca de Gerenciamento na IDE do Arduino
- Carregue o código
- Modifique as configurações de Wi-Fi e MQTT no código conforme necessário
- Identifique a porta USB utilizada na IDE do Arduino.
- Compile e faça o upload do código para ESP8266

## Documentação
- [Descrição do Hardware](docs/hardwaredescription.md)
- [Software e Documentação do Código]()
- [Documentação das Interfaces, Protocolos e Módulos de Comunicação](docs/communication.md)

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
- [HiveMQ](https://www.hivemq.com/demos/websocket-client/)
- Os dados de BPM são publicados no tópico 'sensor/bpm'.
