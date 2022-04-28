//**************************************************
//********************** LIBS **********************
//**************************************************
  #include <MFRC522.h>
  #include <SPI.h>
//**************************************************

//**************************************************
//****************** DEFINE GPIOS ******************
//**************************************************
  #define SS_PIN 21
  #define RST_PIN 22

  #define confPin 34
  
  #define greenLed 12
  #define redLed 32
//**************************************************

//**************************************************
//**************** GLOBAL VARIABLES ****************
//**************************************************
String rfids[] = {"69 64 83 41", "8A 54 70 7F"};
byte sizeRfids = (sizeof(rfids) / sizeof(rfids[0]));
String readedR = "";
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
  mfrc522.PCD_Init(); 

  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
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
      x=sizeRfids;
      Serial.println();
      Serial.println("Authorized access");
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      Serial.println();
    }
 
    else {
      Serial.println("Access denied");
      digitalWrite(32, HIGH);
      delay(10);
      digitalWrite(32, LOW);
      Serial.println();
     }
  }
}
//**************************************************
