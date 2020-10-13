#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 88, 177 };
char server[] = "digigroup.tk";

EthernetClient client;

boolean ping()
{
  if (client.connect(server, 80))
  {
    digitalWrite(2, 1);
    Serial.println("1");
  }
  else
  {
    digitalWrite(2, 0);
    Serial.println("0");
  }
  delay(1000);
}

boolean request()
{
  if (client.connect(server, 80))
  { 
    client.print( "GET /index.php?");
    client.print("alarm=1");   
    client.println( " HTTP/1.1");
    client.print( "Host:" );
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.println();
    
    Serial.println("Connecting ended...");
  } else {
    Serial.println("No connection");
  }

  if (client.connect(server, 80))
  { 
    client.print( "GET /index.php?");
    client.print("alarm=2");   
    client.println( " HTTP/1.1");
    client.print( "Host:" );
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.println();
    
    Serial.println("Connecting ended...");
  } else {
    Serial.println("No connection");
  }

  if (client.connect(server, 80))
  { 
    client.print( "GET /index.php?");
    client.print("alarm=3");   
    client.println( " HTTP/1.1");
    client.print( "Host:" );
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.println();
    
    Serial.println("Connecting ended...");
  } else {
    Serial.println("No connection");
  }
}

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}

void loop()
{
  ping();
  client.stop();
  

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (digitalRead(7) == 0)
  {
    digitalWrite(4, 1);
    digitalWrite(2, 0);
    request();
    delay(3000);
  } else {
    digitalWrite(4, 0);
  }

  while(client.connected()){
    if(client.available()){
      char c = client.read();
      Serial.print(c);
    }
  }
}
