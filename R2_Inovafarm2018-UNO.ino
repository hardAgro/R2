
#include <SoftwareSerial.h> // Biblioteca SoftwareSerial
#include "DHT.h"

#define DHTPIN A0 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

//------------------------difinir pinos de dos SENSORES-------------------
//int sen_temp = A0;
int sen_umi = A1;
int sen_condut = A2;
float t = 0;

const int BUFFER_SIZE = 1000;


//----------------------VARIÁVEIS QUE RECEBEM OS VALORES MEDIDOS PELOS SENSORES---------------------------------
float temperatura, entrada, umidade, condut, cond, cond1 = 0;
int umed = 0;

//----------------------IDENTIFICAÇÃO DA ÁREA (A = ÁREA 1, B = ÁREA 2 E ASSIM SUCESSIVAMENTE)----------
String ID = "1";

//--------------------------------------------------------------------------------------------------------------
//defines gerais
#define TEMPO_LEITURA_SENSOR  1  //tempo entre leituras


SoftwareSerial comunicacaoESP(2, 3); // objeto para comunicação serial com o ESP8266 nas Portas 2(RX) e 3(TX)

int cont = 0;
String env,  A, B, C, D = "";


//Função setup (inicializações do programa)
void setup()
{
  Serial.begin(9600);
  Serial.println("ARDUINO + ENVIO DADOS POR SERIAL >> ESP");
  comunicacaoESP.begin(9600); // inicia a comunicação serial com o ESP8266
  
}

//loop (programa principal)
void loop()
{

  cont++; //VARIÁVEL QUE GERENCIA A LEITURA
  
  t = dht.readTemperature();
  umed = analogRead(sen_umi);
  umidade = map(umed,0,1023,-100,-1);
  umidade = umidade/100;
  
  delay(1);
  
  cond = analogRead(sen_condut);
  cond1 = map(cond,190,300,250,-100);
  condut = cond1/100;
  if (cont == 50){ //QUANDO IGUAL A 5(RESULTANDO EM 100ms), DISPARA A LEITURA
////////////////////////////////////////////////  
    
    temperatura = readTemperatureWithBuffer();

    
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print("*C - ");
    Serial.print("Pressão solo: ");
    Serial.print(umidade);
    Serial.print("bar - ");
    Serial.print("Nível sais: ");
    Serial.print(condut);
    Serial.print(" mho/cm - ");
    Serial.println(cond);
  }
  delay(1);

//////////////////////////////////    
  
//----------APÓS 120ms ENVIA A RESPOSTA DOS SENSORES---------------
if (cont == 55){

      A=ID+","+String(temperatura)+","+String(umidade)+","+String(condut);
      comunicacaoESP.println(A);  //ENVIA AO ESP PELA PORTA SERIAL SECUNDÁRIA A STRING
      comunicacaoESP.flush(); 
      Serial.println(A);          //PRINTA NA SERIAL PARA MONITORAMENTO
      cont=0;                      //ZERA A VARIÁVEL DE DISPARO
      
}
  delay(TEMPO_LEITURA_SENSOR);      //DELAY(1ms)

}

float readTemperatureWithBuffer(){

  float buffer = 0;
  for (int i = 0; i < BUFFER_SIZE; i++){
      buffer += t;
  }
  return (buffer/BUFFER_SIZE);
}



