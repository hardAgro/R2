#include <ESP8266WiFi.h>
#include <WiFiClient.h> 

//-------------------VARIABLES GLOBALES--------------------------
int contconexion = 0;

int cont = 0;
String str = "";
String a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p = "";

int tamanho, I = 0;

const char *ssid = "R2 Sistemas";
const char *password = "R2SISTEMAS";

unsigned long previousMillis = 0;

char host[48];
String strhost = "10.10.10.120";
String strurl = "dae/insert_weather.php";
String chipid = "A";

//-------FUNÇÃO PARA ENVIAR DADOS PARA O MYSQL--------

String enviardados(String datos) {


  String linea = "error";
  WiFiClient client;
  strhost.toCharArray(host, 49);
  if (!client.connect(host, 80)) {
    Serial.println("Fallo de conexion");
    return linea;
  }

  client.print(String("POST ") + strurl + " HTTP/1.1" + "\r\n" + 
               "Host: " + strhost + "\r\n" +
               "Accept: */*" + "*\r\n" +
               "Content-Length: " + datos.length() + "\r\n" +
               "Content-Type: application/x-www-form-urlencoded" + "\r\n" +
               "\r\n" + datos);           
  delay(1);             
  
  Serial.print("Enviando dados a MySQL...");
  Serial.print(datos);




}

//-------------------------------------------------------------------------

void setup() {

  // Inicia Serial
  Serial.begin(9600);
  Serial.println("");

  Serial.print("chipId: "); 
  Serial.println(chipid); 

  // Conexión WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and contconexion <50) { //Cuenta hasta 50 si no se puede conectar lo cancela
    ++contconexion;
    delay(500);
    Serial.print(".");
  }
  if (contconexion <50) {
      //para usar con ip fija
      IPAddress ip(10,10,10,156); 
      IPAddress gateway(10,10,10,1); 
      IPAddress subnet(255,255,255,0); 
      WiFi.config(ip, gateway, subnet); 
      
      Serial.println("");
      Serial.println("WiFi conectado");
      Serial.println(WiFi.localIP());
  }
  else { 
      Serial.println("");
      Serial.println("Error de conexão");
  }
}

//----------------------------LOOP--------------------------------
void loop() {
  cont++;



    String newStr = Serial.readStringUntil('\n');

      if (newStr != "") {
        str = newStr;
        if (cont == 100){
          enviardados("status="+str);
          Serial.println(str);
          cont=0;
            }
          }
        
  
        
      
    

    delay(10);
    str="";



}
