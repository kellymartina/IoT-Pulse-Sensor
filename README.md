# IoT-Pulse-Sensor
- Sensor de batimentos cardiacos programado na IDE do Arduino.
- Projeto desenvolvido para a matéria de Objetos Inteligentes Conectados (IoT), Quinto Semestre do curso Análise e Desenvolvimento de Sistemas.

## Funcionamento 
- Este projeto consiste em um dispositivo que mede os batimentos cardíacos de uma pessoa utilizando um sensor de pulso conectado a um microcontrolador ESP8266. Os batimentos cardíacos são medidos através das variações no sinal captado pelo sensor. O dispositivo se conecta à rede WiFi e envia os dados de frequência cardíaca para um servidor MQTT. Além disso, o dispositivo controla um buzzer para fornecer feedback audível com base na frequência cardíaca medida.

## Como reproduzir

2. Instale a IDE do Arduino em seu computador, se ainda não estiver instalada. <br>
- Abra a IDE do Arduino e vá para o menu "Arquivo" -> "Preferências". <br>
- Em "URLs Adicionais para Gerenciadores de Placas", adicione a seguinte URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json. <br>
- Vá para o menu "Ferramentas" -> "Placa" -> "Gerenciador de Placas", pesquise por "esp8266" e instale o pacote "ESP8266" desenvolvido pela ESP8266 Community.
3. Instalação de Bibliotecas.
- Instale as seguintes bibliotecas através do menu "Sketch" -> "Incluir Biblioteca" -> "Gerenciar Bibliotecas":
- "PubSubClient" para a comunicação MQTT.
- "ESP8266WiFi" para a comunicação WiFi.
4. Conexão do hardware
- Conecte o sensor de pulso ao pino analógico definido no código (PulseSensorPin).
- Conecte o buzzer ao pino digital definido no código (BuzzerPin).
5. Configuração do código:
- Substitua "Nome_da_rede" e "Senha_da_rede" pelas credenciais da sua rede WiFi.
- Se desejar utilizar um servidor MQTT diferente, substitua "mqtt.eclipseprojects.io" pelo endereço do seu servidor.
- Escolha um tópico MQTT apropriado para publicar os dados do sensor, e ajuste o valor de "mqtt_topic" conforme necessário.
- Certifique-se de que o limite (Threshold) definido no código corresponda ao comportamento esperado do sensor de pulso.
6. Carregue o código
- Conecte o microcontrolador ESP8266 ao seu computador via USB.
- Selecione a placa correta em "Ferramentas" -> "Placa" -> "NodeMCU 1.0 (ESP-12E Module)" (ou similar).
- Selecione a porta correta em "Ferramentas" -> "Porta".
- Carregue o código para o microcontrolador pressionando o botão "Upload".
7. Observação
- Certifique-se de monitorar a saída serial (menu "Ferramentas" -> "Monitor Serial") para acompanhar o status da conexão WiFi, MQTT e a leitura dos batimentos cardíacos.


## Documentação
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

- Os dados de BPM são publicados no tópico 'sensor/bpm'.
