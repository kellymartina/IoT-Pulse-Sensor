## Para conectar a um servidor HiveMQ usando MQTT, você pode seguir este passo a passo:

1. **Configure o MQTT:**

- Configure o cliente MQTT com as credenciais de acesso ao servidor HiveMQ, incluindo o endereço do servidor, a porta MQTT, o nome de usuário e a senha, se necessário. Certifique-se de configurar corretamente os parâmetros de segurança, como criptografia TLS, se estiverem sendo usados.
 <img src="/img/hivemq1.png" alt="Passo 1" style="width:80%">

2. **Estabeleça a Conexão:**
- Aperte em connect.

3. **Publique e/ou Subscreva Tópicos MQTT:**
- Depois de estabelecer a conexão MQTT, você pode começar a publicar mensagens em tópicos MQTT relevantes e/ou se inscrever em tópicos para receber mensagens do servidor HiveMQ. Use os métodos apropriados fornecidos pelo cliente MQTT para publicar e subscrever tópicos MQTT.

<div style="display:flex">
  <img src="/img/hivemq2.png" alt="Passo 2" style="width:40%">
  <img src="/img/hivemq3.png" alt="Passo 3" style="width:50%">
</div>

4. **Gerencie a Conexão MQTT:**

- Certifique-se de gerenciar adequadamente a conexão MQTT, lidando com eventos de desconexão e reconexão, se necessário. Você pode configurar callbacks ou listeners no cliente MQTT para lidar com eventos de conexão, desconexão e recebimento de mensagens.

5. **Encerre a Conexão MQTT (Opcional):**

- Quando você terminar de usar a conexão MQTT, certifique-se de encerrá-la corretamente chamando o método de desconexão do cliente MQTT. Isso ajuda a liberar recursos e encerrar a sessão com o servidor HiveMQ de forma limpa.
