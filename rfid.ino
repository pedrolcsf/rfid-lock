#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN    21
#define RST_PIN   22

#define SIZE_BUFFER     18
#define MAX_SIZE_BLOCK  16

#define pinVerde     12
#define pinVermelho  32
 
String rfids[] = {"69 64 83 41", "69 64 83 44"};
byte sizeRfids = (sizeof(rfids) / sizeof(rfids[0]));

//esse objeto 'chave' é utilizado para autenticação
MFRC522::MIFARE_Key key;
//código de status de retorno da autenticação
MFRC522::StatusCode status;

// Definicoes pino modulo RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {


  // Inicia a serial
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus

  pinMode(pinVerde, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  
  // Inicia MFRC522
  mfrc522.PCD_Init(); 
  // Mensagens iniciais no serial monitor
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();

}

void loop() {
   // Aguarda a aproximacao do cartao
   if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
   }
    // Seleciona um dos cartoes
    if ( ! mfrc522.PICC_ReadCardSerial()) 
    {
      return;
    }

    readData();
 
  // instrui o PICC quando no estado ACTIVE a ir para um estado de "parada"
  mfrc522.PICC_HaltA(); 
  // "stop" a encriptação do PCD, deve ser chamado após a comunicação com autenticação, caso contrário novas comunicações não poderão ser iniciadas
  mfrc522.PCD_StopCrypto1();  
}

//faz a leitura dos dados do cartão/tag
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
    if (content.substring(1) == rfids[x]) {
      x=sizeRfids;
      Serial.println();
      Serial.println("Authorized access");
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      Serial.println();
    }
 
    else {
      Serial.println();
      Serial.println(" Access denied");
      digitalWrite(32, HIGH);
      delay(10);
      digitalWrite(32, LOW);
      Serial.println();
     }
  }
}
