
## Como reproduzir

1. Instale a IDE do Arduino em seu computador, se ainda não estiver instalada. <br>
- Abra a IDE do Arduino e vá para o menu "Arquivo" -> "Preferências". <br>
- Em "URLs Adicionais para Gerenciadores de Placas", adicione a seguinte URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json. <br>
- Vá para o menu "Ferramentas" -> "Placa" -> "Gerenciador de Placas", pesquise por "esp8266" e instale o pacote "ESP8266" desenvolvido pela ESP8266 Community.
2. Instalação de Bibliotecas.
- Instale as seguintes bibliotecas através do menu "Sketch" -> "Incluir Biblioteca" -> "Gerenciar Bibliotecas":
- "PubSubClient" para a comunicação MQTT.
- "ESP8266WiFi" para a comunicação WiFi.
3. Conexão do hardware
- Conecte o sensor de pulso ao pino analógico definido no código (PulseSensorPin).
- Conecte o buzzer ao pino digital definido no código (BuzzerPin).
4. Configuração do código:
- Substitua "Nome_da_rede" e "Senha_da_rede" pelas credenciais da sua rede WiFi.
- Se desejar utilizar um servidor MQTT diferente, substitua "mqtt.eclipseprojects.io" pelo endereço do seu servidor.
- Escolha um tópico MQTT apropriado para publicar os dados do sensor, e ajuste o valor de "mqtt_topic" conforme necessário.
- Certifique-se de que o limite (Threshold) definido no código corresponda ao comportamento esperado do sensor de pulso.
5. Carregue o código
- Conecte o microcontrolador ESP8266 ao seu computador via USB.
- Selecione a placa correta em "Ferramentas" -> "Placa" -> "NodeMCU 1.0 (ESP-12E Module)" (ou similar).
- Selecione a porta correta em "Ferramentas" -> "Porta".
- Carregue o código para o microcontrolador pressionando o botão "Upload".
6. Observação
- Certifique-se de monitorar a saída serial (menu "Ferramentas" -> "Monitor Serial") para acompanhar o status da conexão WiFi, MQTT e a leitura dos batimentos cardíacos.
