# TravaEletronicaArduino

Projeto criado para o componente de Objetos inteligentes conectados com intuito de desenvolver um programa usando arduino junto do protocolo firmata e Broker MQTT.

Funcionamento: assim que ligado, o circuito conta o numero de vezes em que o usuario interage com o sensor, após as interações o usuario possui opções no dashboard, 
essas opções são: abrir (onde sera comparado o numero de vezes que o usuario interagem com o sensor, com uma senha pré estabelecida), abrir sem senha (onde o arduino mandará um sinal para que a trava elétrica seja acionada sem precisar de senha) e alterar senha (onde o sistema pega o numero de vezes que o usuario interagiu com o sensor e define esse número como senha).

O projeto funciona em conjunto com um dashboard, criado no Node-Red, e protocolo firmata. Os códigos para arduino foram desenvolvidos e testados na IDE arduino.

**lista de materiais:**
  <li>Arduino Uno; </li>
  <li>Mini trava elétrica;</li>
  <li>Módulo Relé 5V;</li>
  <li>Fonte de alimentação 12V;</li>
  <li>Led's;</li>
  <li>Buzzer ativo;</li>
  <li>ProtoBoard 400 furos;</li>
  <li>Mósulo sensor de vibração sw420;</li>
  <li>Resistores 330 ohms.</li>
  <br/>
  
  **Documentação de referência:**
    <li>Arduino IDE: https://www.arduino.cc/reference/pt/; </li>
    <li>Biblioteca Firmata no arduino: https://www.arduino.cc/en/reference/firmata;</li>
    <li>Node-Red: https://nodered.org/docs/;</li>
    
