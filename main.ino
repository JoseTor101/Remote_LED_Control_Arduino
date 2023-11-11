/*
INTEGRANTES
  - CEYNI BELTRAN
  - JULIO POSADA
  - JOSE TORDECILLA
*/

#include <WiFi101.h>
#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 7
#define LED7 6

char ssid[] = "Pipe"; //nombre de red wifi
char pass[] = "1027740136"; //password

int status = 0;

//Dirección a conectividad IP (servidor)
WiFiServer server(80);

//Conectividad a IP (cliente)
WiFiClient client = server.available();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //definimos los pines de led como salida 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);

  //Activar el wifi
  enable_WiFi();
  //nos conectamos
  connect_WiFi();

  //iniciamos el server
  server.begin();

  //imprimir por serial la info
  printWifiStatus();
}

void loop() {
  // put your main code here, to run repeatedly:
  client = server.available();

  if (client) {
    printWEB();
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");

  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}

void enable_WiFi() {
  String fv = WiFi.firmwareVersion();
  if (fv < "1.0.0") {
    Serial.println("Please upgrade the firmware");
  }
}

//se queda en el ciclo hasta que conecte
void connect_WiFi() {
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // Wait 10 seconds for connection:
    delay(10000);
  }
}

//envia el archivo de la pag-web al cliente.
void printWEB() {
  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<!doctype html>");
            client.println("<html lang=\"en\">"); // Escape the inner quotation marks
            client.println("<head>");
            client.println("<meta charset=\"utf-8\">"); // Escape the inner quotation marks
            client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"); // Escape the inner quotation marks
            client.println("<title>LED central</title>");
            client.println("<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ\" crossorigin=\"anonymous\">"); // Escape the inner quotation marks
            client.println("</head>");
            client.println("<style>");
            client.println("body {");
            client.println("zoom: 1.5;");
            client.println("<!--    background-image: url('https://w0.peakpx.com/wallpaper/578/837/HD-wallpaper-spongebob-black-emo-white-blue.jpg');");
            client.println("    background-size: cover;");
            client.println("    background-position: center;");
            client.println("    background-color: rgba(0, 0, 0, 0.2);-->");
            client.println("}");
            client.println("</style>");
            client.println("<body>");
            client.println("<h1>Control de LEDs</h1>");
            client.println("<p>Seleccione el LED que desea controlar:</p>");
            client.println("<div class=\"btn-group-vertical\" role=\"group\">"); // Escape the inner quotation marks
            client.println("<button type=\"button\" class=\"btn btn-primary dropdown-toggle\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">Habitacion 1</button>"); // Escape the inner quotation marks
            client.println("<ul class=\"dropdown-menu\">"); // Escape the inner quotation marks
            client.println("<li><a class=\"dropdown-item\" href=\"/LED1ON\">Encender</a></li>"); // Escape the inner quotation marks
            client.println("<li><a class=\"dropdown-item\" href=\"/LED1OFF\">Apagar</a></li>"); // Escape the inner quotation marks
            client.println("</ul>");
            client.println("<button type=\"button\" class=\"btn btn-primary dropdown-toggle\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">Pasillo</button>");
            client.println("<ul class=\"dropdown-menu\">");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED2ON\">Encender</a></li>");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED2OFF\">Apagar</a></li>");
            client.println("</ul>");
            client.println("<button type=\"button\" class=\"btn btn-primary dropdown-toggle\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">Cocina</button>");
            client.println("<ul class=\"dropdown-menu\">");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED3ON\">Encender</a></li>");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED3OFF\">Apagar</a></li>");
            client.println("</ul>");
            client.println("<button type=\"button\" class=\"btn btn-primary dropdown-toggle\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">Baño</button>");
            client.println("<ul class=\"dropdown-menu\">");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED4ON\">Encender</a></li>");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED4OFF\">Apagar</a></li>");
            client.println("</ul>");
            client.println("<button type=\"button\" class=\"btn btn-primary dropdown-toggle\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">Habitación 2</button>");
            client.println("<ul class=\"dropdown-menu\">");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED5ON\">Encender</a></li>");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED5OFF\">Apagar</a></li>");
            client.println("</ul>");
            client.println("<button type=\"button\" class=\"btn btn-primary dropdown-toggle\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">Estudio</button>");
            client.println("<ul class=\"dropdown-menu\">");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED6ON\">Encender</a></li>");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED6OFF\">Apagar</a></li>");
            client.println("</ul>");
            client.println("<button type=\"button\" class=\"btn btn-primary dropdown-toggle\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">Sala</button>");
            client.println("<ul class=\"dropdown-menu\">");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED7ON\">Encender</a></li>");
            client.println("<li><a class=\"dropdown-item\" href=\"/LED7OFF\">Apagar</a></li>");
            client.println("</ul>");
            client.println("</div>");
            client.println("<script src=\"https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js\" integrity=\"sha384-ENjdO4Dr2bkBIFxQpeoTz1HIcje39Wm4jDKdf19U8gI4ddQ3GYNS7NTKfAdVQSZe\" crossorigin=\"anonymous\"></script>");
            client.println("</body>");
client.println("</html>");

            client.println();
            break;
          } else {
            currentLine = "";       
          }
        } else if (c != '\r') {     // if you got anything else but a carriage return character,
          currentLine += c;         // add it to the end of the currentLine
        }
        
        
        //espacio rutas
        if (currentLine.endsWith("GET /LED1ON")) {
          digitalWrite(LED1, HIGH);
        }
        if (currentLine.endsWith("GET /LED1OFF")) {
          digitalWrite(LED1, LOW);
        }
        if (currentLine.endsWith("GET /LED2ON")) {
          digitalWrite(LED2, HIGH);
        }
        if (currentLine.endsWith("GET /LED2OFF")) {
          digitalWrite(LED2, LOW);
        }
        if (currentLine.endsWith("GET /LED3ON")) {
          digitalWrite(LED3, HIGH);
        }
        if (currentLine.endsWith("GET /LED3OFF")) {
          digitalWrite(LED3, LOW);
        }
        if (currentLine.endsWith("GET /LED4ON")) {
          digitalWrite(LED4, HIGH);
        }
        if (currentLine.endsWith("GET /LED4OFF")) {
          digitalWrite(LED4, LOW);
        }
        if (currentLine.endsWith("GET /LED5ON")) {
          digitalWrite(LED5, HIGH);
        }
        if (currentLine.endsWith("GET /LED5OFF")) {
          digitalWrite(LED5, LOW);
        }
        if (currentLine.endsWith("GET /LED6ON")) {
          digitalWrite(LED6, HIGH);
        }
        if (currentLine.endsWith("GET /LED6OFF")) {
          digitalWrite(LED6, LOW);
        }
        if (currentLine.endsWith("GET /LED7ON")) {
          digitalWrite(LED7, HIGH);
        }
        if (currentLine.endsWith("GET /LED7OFF")) {
          digitalWrite(LED7, LOW);
        }
        
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}