//**************************************************
//********************** LIBS **********************
//**************************************************
  #include <MFRC522.h>
  #include <SPI.h>
  #include "WiFi.h"
  #include "SPIFFS.h"
  #include "ESPAsyncWebServer.h"
  #include <EEPROM.h>
//**************************************************

//**************************************************
//****************** DEFINE GPIOS ******************
//**************************************************
  #define SS_PIN 21
  #define RST_PIN 22

  #define confPin 5
  
  #define greenLed 12
  #define redLed 32
  
  #define RESET_EEPROM 26
  #define EEPROM_SIZE 254
//**************************************************

//**************************************************
//******************* CONFIG AP ********************
//**************************************************
  const char* ssid = "RFID-LOOK";
  const char* password =  "$3nh@_d0rfid";
//**************************************************

  AsyncWebServer server(80);

//**************************************************
//*************** VARIAVEIS INPUT ******************
//**************************************************
  const char* id0_input = "idInput0";
  const char* id1_input = "idInput1";
  const char* id2_input = "idInput2";
  const char* id3_input = "idInput3";
  const char* id4_input = "idInput4";
  const char* id5_input = "idInput5";
  const char* id6_input = "idInput6";
  const char* id7_input = "idInput7";
  const char* id8_input = "idInput8";
  const char* id9_input = "idInput9";
  const char* id10_input = "idInput10";
  const char* id11_input = "idInput11";
  const char* id12_input = "idInput12";
  const char* id13_input = "idInput13";
  const char* id14_input = "idInput14";
  const char* id15_input = "idInput15";
  const char* id16_input = "idInput16";
  const char* id17_input = "idInput17";
  const char* id18_input = "idInput18";
  const char* id19_input = "idInput19";

  const char* name0_input = "name0";
  const char* name1_input = "name1";
  const char* name2_input = "name2";
  const char* name3_input = "name3";
  const char* name4_input = "name4";
  const char* name5_input = "name5";
  const char* name6_input = "name6";
  const char* name7_input = "name7";
  const char* name8_input = "name8";
  const char* name9_input = "name9";
  const char* name10_input = "name10";
  const char* name11_input = "name11";
  const char* name12_input = "name12";
  const char* name13_input = "name13";
  const char* name14_input = "name14";
  const char* name15_input = "name15";
  const char* name16_input = "name16";
  const char* name17_input = "name17";
  const char* name18_input = "name18";
  const char* name19_input = "name19";
  
//**************************************************



//**************************************************
//**************** GLOBAL VARIABLES ****************
//**************************************************

  bool ap = 1;
  
  String rfids[20] = {"69 64 83 41", "09 C4 7A 41", "8A 54 70 7F", "01 15 A1 59",  "CA 19 7B 7F", "9A C4 7C 80", "59 CB 2D 41", "D9 83 2C 41", "09 DD 77 41","39 00 2D 41", "79 7E 38 41","F9 1A B8 B2", "63 AB 09 0B","D9 5C B9 B2", "89 46 7A 41", "9A F0 77 7F", "00 00 00 00", "00 00 00 00", "00 00 00 00", "00 00 00 00"};
  String peoples[20] = {"Pedro", "Igor", "Yuri", "Jonny", "Lu B", "Lu P", "Letic", "Cida", "Tio C", "Celsi", "Rose", "Lore", "Barre", "Regin", "Filip", "", "", "", "", ""};
  byte sizeRfids = (sizeof(rfids) / sizeof(rfids[0]));
  byte sizePeoples = (sizeof(peoples) / sizeof(peoples[0]));
  String readedR = "";

  String coiso[5];

//**************************************************

//**************************************************
//************* INITIAL VALUES PAGE HTML ***********
//**************************************************

  String getId0() {
    return String(rfids[0]);
  }

  String getId1() {
    return String(rfids[1]);
  }
  
  String getId2() {
    return String(rfids[2]);
  }

  String getId3() {
    return String(rfids[3]);
  }
 
  String getId4() {
    return String(rfids[4]);
  }
  
  String getId5() {
    return String(rfids[5]);
  }
  
  String getId6() {
    return String(rfids[6]);
  }

  String getId7() {
    return String(rfids[7]);
  }

  String getId8() {
    return String(rfids[8]);
  }
  
  String getId9() {
    return String(rfids[9]);
  }

  String getId10() {
    return String(rfids[10]);
  }
 
  String getId11() {
    return String(rfids[11]);
  }
  
  String getId12() {
    return String(rfids[12]);
  }
  
  String getId13() {
    return String(rfids[13]);
  }
  
  String getId14() {
    return String(rfids[14]);
  }
  
  String getId15() {
    return String(rfids[15]);
  }

  String getId16() {
    return String(rfids[16]);
  }
 
  String getId17() {
    return String(rfids[17]);
  }
  
  String getId18() {
    return String(rfids[18]);
  }
  
  String getId19() {
    return String(rfids[19]);
  }

    String getName0() {
    return String(peoples[0]);
  }

  String getName1() {
    return String(peoples[1]);
  }
  
  String getName2() {
    return String(peoples[2]);
  }

  String getName3() {
    return String(peoples[3]);
  }
 
  String getName4() {
    return String(peoples[4]);
  }
  
  String getName5() {
    return String(peoples[5]);
  }
  
  String getName6() {
    return String(peoples[6]);
  }

  String getName7() {
    return String(peoples[7]);
  }

  String getName8() {
    return String(peoples[8]);
  }
  
  String getName9() {
    return String(peoples[9]);
  }

  String getName10() {
    return String(peoples[10]);
  }
 
  String getName11() {
    return String(peoples[11]);
  }
  
  String getName12() {
    return String(peoples[12]);
  }
  
  String getName13() {
    return String(peoples[13]);
  }
  
  String getName14() {
    return String(peoples[14]);
  }
  
  String getName15() {
    return String(peoples[15]);
  }

  String getName16() {
    return String(peoples[16]);
  }
 
  String getName17() {
    return String(peoples[17]);
  }
  
  String getName18() {
    return String(peoples[18]);
  }
  
  String getName19() {
    return String(peoples[19]);
  }
//**************************************************



// RFID CONF
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;
MFRC522 mfrc522(SS_PIN, RST_PIN);

//**************************************************
//********************* SETUP **********************
//**************************************************
void setup() {
  Serial.begin(9600);

  SPI.begin();

  EEPROM.begin(EEPROM_SIZE);

    
  
  pinMode(confPin, INPUT_PULLUP);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  ap = digitalRead(confPin);

  if(!ap) {
    if(!SPIFFS.begin()){
      Serial.println("An Error has occurred while mounting SPIFFS");
      return;
    }

    WiFi.softAP(ssid, password);

    server.on("/idInput0", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId0().c_str());
    });

    server.on("/idInput1", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId1().c_str());
    });

    server.on("/idInput2", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId2().c_str());
    });

    server.on("/idInput3", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId3().c_str());
    });

    server.on("/idInput4", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId4().c_str());
    });

    server.on("/idInput5", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId5().c_str());
    });

    server.on("/idInput6", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId6().c_str());
    });

    server.on("/idInput7", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId7().c_str());
    });

    server.on("/idInput8", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId8().c_str());
    });

    server.on("/idInput9", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId9().c_str());
    });

    server.on("/idInput10", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId10().c_str());
    });

    server.on("/idInput11", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId11().c_str());
    });

    server.on("/idInput12", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId12().c_str());
    });

    server.on("/idInput13", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId13().c_str());
    });

    server.on("/idInput14", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId14().c_str());
    });

    server.on("/idInput15", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId15().c_str());
    });

    server.on("/idInput16", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId16().c_str());
    });

    server.on("/idInput17", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId17().c_str());
    });

    server.on("/idInput18", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId18().c_str());
    });

    server.on("/idInput19", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getId19().c_str());
    });

        server.on("/name0", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName0().c_str());
    });

    server.on("/name1", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName1().c_str());
    });

    server.on("/name2", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName2().c_str());
    });

    server.on("/name3", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName3().c_str());
    });

    server.on("/name4", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName4().c_str());
    });

    server.on("/name5", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName5().c_str());
    });

    server.on("/name6", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName6().c_str());
    });

    server.on("/name7", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName7().c_str());
    });

    server.on("/name8", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName8().c_str());
    });

    server.on("/name9", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName9().c_str());
    });

    server.on("/name10", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName10().c_str());
    });

    server.on("/name11", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName11().c_str());
    });

    server.on("/name12", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName12().c_str());
    });

    server.on("/name13", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName13().c_str());
    });

    server.on("/name14", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName14().c_str());
    });

    server.on("/name15", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName15().c_str());
    });

    server.on("/name16", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName16().c_str());
    });

    server.on("/name17", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName17().c_str());
    });

    server.on("/name18", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName18().c_str());
    });

    server.on("/name19", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", getName19().c_str());
    });

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/index.html", String(), false);
    });

    server.on("/post", HTTP_GET, [] (AsyncWebServerRequest *request) {
      String id0;
      String id1;
      String id2;
      String id3;
      String id4;
      String id5;
      String id6;
      String id7;
      String id8;
      String id9;
      String id10;
      String id11;
      String id12;
      String id13;
      String id14;
      String id15;
      String id16;
      String id17;
      String id18;
      String id19;
      
      String name0;
      String name1;
      String name2;
      String name3;
      String name4;
      String name5;
      String name6;
      String name7;
      String name8;
      String name9;
      String name10;
      String name11;
      String name12;
      String name13;
      String name14;
      String name15;
      String name16;
      String name17;
      String name18;
      String name19;

      if (request->hasParam(name0_input)) {
        id0 = request->getParam(id0_input)->value();
        id1 = request->getParam(id1_input)->value();
        id2 = request->getParam(id2_input)->value();
        id3 = request->getParam(id3_input)->value();
        id4 = request->getParam(id4_input)->value();
        id5 = request->getParam(id5_input)->value();
        id6 = request->getParam(id6_input)->value();
        id7 = request->getParam(id7_input)->value();
        id8 = request->getParam(id8_input)->value();
        id9 = request->getParam(id9_input)->value();
        id10 = request->getParam(id10_input)->value();
        id11 = request->getParam(id11_input)->value();
        id12 = request->getParam(id12_input)->value();
        id13 = request->getParam(id13_input)->value();
        id14 = request->getParam(id14_input)->value();
        id15 = request->getParam(id15_input)->value();
        id16 = request->getParam(id16_input)->value();
        id17 = request->getParam(id17_input)->value();
        id18 = request->getParam(id18_input)->value();
        id19 = request->getParam(id19_input)->value();

        name0 = request->getParam(name0_input)->value();
        name1 = request->getParam(name1_input)->value();
        name2 = request->getParam(name2_input)->value();
        name3 = request->getParam(name3_input)->value();
        name4 = request->getParam(name4_input)->value();
        name5 = request->getParam(name5_input)->value();
        name6 = request->getParam(name6_input)->value();
        name7 = request->getParam(name7_input)->value();
        name8 = request->getParam(name8_input)->value();
        name9 = request->getParam(name9_input)->value();
        name10 = request->getParam(name10_input)->value();
        name11 = request->getParam(name11_input)->value();
        name12 = request->getParam(name12_input)->value();
        name13 = request->getParam(name13_input)->value();
        name14 = request->getParam(name14_input)->value();
        name15 = request->getParam(name15_input)->value();
        name16 = request->getParam(name16_input)->value();
        name17 = request->getParam(name17_input)->value();
        name18 = request->getParam(name18_input)->value();
        name19 = request->getParam(name19_input)->value();

        rfids[0] = id0;
        rfids[1] = id1;
        rfids[2] = id2;
        rfids[3] = id3;
        rfids[4] = id4;
        rfids[5] = id5;
        rfids[6] = id6;
        rfids[7] = id7;
        rfids[8] = id8;
        rfids[9] = id9;
        rfids[10] = id10;
        rfids[11] = id11;
        rfids[12] = id12;
        rfids[13] = id13;
        rfids[14] = id14;
        rfids[15] = id15;
        rfids[16] = id16;
        rfids[17] = id17;
        rfids[18] = id18;
        rfids[19] = id19;

        peoples[0] = name0;
        peoples[1] = name1;
        peoples[2] = name2;
        peoples[3] = name3;
        peoples[4] = name4;
        peoples[5] = name5;
        peoples[6] = name6;
        peoples[7] = name7;
        peoples[8] = name8;
        peoples[9] = name9;
        peoples[10] = name10;
        peoples[11] = name11;
        peoples[12] = name12;
        peoples[13] = name13;
        peoples[14] = name14;
        peoples[15] = name15;
        peoples[16] = name16;
        peoples[17] = name17;
        peoples[18] = name18;
        peoples[19] = name19;

        for(int i = 0; i < sizeRfids; i++) {
          writeStringToEEPROM(i * 12, rfids[i]);
          rfids[i] = readStringFromEEPROM(i * 12);
          rfids[i].remove(11, 12);
        }

        for(int p = 0; p < sizePeoples; p++) {
          writeStringToEEPROM(p * 5, peoples[p]);
          peoples[p] = readStringFromEEPROM(p * 5);
          peoples[p].remove(4, 5);
          Serial.println(peoples[p]);
        }


      // Pica o Led para indicar que gravou
              digitalWrite(greenLed, HIGH);
              delay(500);
              digitalWrite(greenLed, LOW);
      // ***********************************
      }
      
      request->send(SPIFFS, "/index.html", String(), false);
    });


    server.begin(); 
  } else {
    mfrc522.PCD_Init();
    Serial.println("Aproxime o seu cartao do leitor...");
    Serial.println();
    
    
    coiso[0] = readStringFromEEPROM(0);

    Serial.println(coiso[0]);

//     for(int i = 0; i < sizeRfids; i++) {
//          writeStringToEEPROM(i * 12, rfids[i]);
//          rfids[i] = readStringFromEEPROM(i * 12);
//          rfids[i].remove(11, 12);
//
//          Serial.println(rfids[i]);
//        }

//        for(int p = 0; p < sizePeoples; p++) {
//          writeStringToEEPROM(p * 5, peoples[p]);
//          peoples[p] = readStringFromEEPROM(p * 5);
//          Serial.println(peoples[p]);
//        }

  }
  

}
//**************************************************

//**************************************************
//********************** LOOP **********************
//**************************************************
void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  
  readData();

  // one rfid at a time
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();  
}
//**************************************************

//**************************************************
//******************* READ RFID ********************
//**************************************************
void readData() {
  String content= "";
  byte letter;
  
  Serial.print("ID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++)  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  for (int x = 0;x<sizeRfids;x++){
    readedR = String(content.substring(1));
    readedR.toUpperCase();
    if (readedR == rfids[x]) {
      Serial.println(peoples[x]);
      x=sizeRfids;
      Serial.println();
      Serial.println("Authorized access");
      
      digitalWrite(12, HIGH);
      delay(1000);
      digitalWrite(12, LOW);
      Serial.println();
    }

    if(readedR != rfids[x] && x + 1 == sizeRfids) {
        Serial.println();
        Serial.println(peoples[x]);
        Serial.println("Access denied");
        digitalWrite(32, HIGH);
        delay(1000);
        digitalWrite(32, LOW);
        Serial.println(); 
    }
  }
}
//**************************************************


void writeStringToEEPROM(int addrOffset, const String &strToWrite)
{
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
}

String readStringFromEEPROM(int addrOffset)
{
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)
  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  return String(data);
}
