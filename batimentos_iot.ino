// ----- WIFI
#include <ESP8266WiFi.h>
const char *ssid = "Nome_da_rede";
const char *password = "Senha_da_rede";
WiFiClient espClient;

// ----- MQTT
#include <PubSubClient.h>
const char *mqtt_broker = "mqtt.eclipseprojects.io";
PubSubClient client(espClient);
const char *mqtt_topic = "sensor/bpm";
const char *mqtt_client = "clientsensor";

// ----- Sensor e Atuador
int PulseSensorPin = A0;
int BuzzerPin = D1;
  
int Signal;
int Threshold = 572;

unsigned long lastBeatTime = 0;
unsigned int bpm = 0;

// ---- SETUP
void setup() {
  pinMode(BuzzerPin, OUTPUT); //Configuração do pino de saída
  Serial.begin(115200); // Inicialização da comunicação serial:
  WiFi.disconnect(true); // Desconecta qualquer conexão WiFi existente
  delay(1000); 
  WiFi.begin(ssid, password); // Tentativa de conexão à rede WiFi:
  client.setServer(mqtt_broker, 1883); //Configuração do servidor MQTT:

  Serial.println("Conectando ao wifi......");
  //Loop de tentativas de conexão WiFi:
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20) {
    delay(500);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Wifi conectado");
  } else {
    Serial.println("Falha ao conectar ao Wifi");
  }
}

// ------ LOOP
void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  Signal = analogRead(PulseSensorPin); //Leitura do sensor de pulso:
  

  //Deteccao dos batimentos
  if (Signal > Threshold) {
    if ((millis() - lastBeatTime) > 200) {
      bpm = 15000 / (millis() - lastBeatTime); //Calcula a frequência cardíaca em batimentos por minuto (BPM)
      lastBeatTime = millis();
    }
  } 

  static unsigned long lastPrintTime = 0;
  //Checagem de tempo para imprimir e publicar BPM:
  if (millis() - lastPrintTime >= 1000) {
    Serial.print("BPM: ");
    Serial.println(bpm);
    lastPrintTime = millis();

    publicarBatimentosNoTopico();
  }


// Controle do buzzer baseado no valor de BPM:
  if (bpm > 60 && bpm < 100) {
    digitalWrite(BuzzerPin, HIGH); // Ativa o Buzzer
    delay(100); // ON duration
    digitalWrite(BuzzerPin, LOW); // Desativa o Buzzer
    delay(900); // OFF duration
  } else {
    digitalWrite(BuzzerPin, LOW); // Desativa o Buzzer
  }

  delay(20);

}

//----- Publicar MQTT
void publicarBatimentosNoTopico() {
  client.publish(mqtt_topic, String(bpm).c_str(), true);
}

//---- Reconnect MQTT
void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    if (client.connect(mqtt_client)) {
      Serial.println("Conectado ao MQTT");
    } else {
      Serial.print("Falha na conexão ao MQTT, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

