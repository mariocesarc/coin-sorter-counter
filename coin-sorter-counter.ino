#include <LiquidCrystal.h>
 
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
 
 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
 
bool debug = false;
int displayTimeMilis = 3000;
bool starting = true;
 
 
int lightUmbral0 = 365;
int lightUmbral1 = 855;
int lightUmbral2 = 465;
int lightUmbral3 = 840;
int lightUmbral4 = 365;
 
int coinNumber0 = 0;          // moneda 10
bool coinPassing0= false;
int coinNumber1 = 0;          // moneda 100N
bool coinPassing1= false;
int coinNumber2 = 0;          // moneda 50
bool coinPassing2= false;    
int coinNumber3 = 0;          // moneda 500
bool coinPassing3= false;
int coinNumber4 = 0;          // moneda 100
bool coinPassing4= false;
 
int tempNumber100 = 0;
int tempTotalMoney = 0;
bool showingCount = false;
 
int photocellPin0 = 0;     // 10
int photocellReading0;     // 10
int photocellPin1 = 1;     // 100N
int photocellReading1;     // 100N
int photocellPin2 = 2;     // 50
int photocellReading2;     // 50
int photocellPin3 = 3;     // 500
int photocellReading3;     // 500
int photocellPin4 = 4;     // 100
int photocellReading4;     // 100
 
void setup() {
  analogWrite(6, 128);  // display
  analogWrite(9, 128);  // display
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(3, 0); // columna, fila
  lcd.print("Iniciando...");
 
 
  digitalWrite(1, HIGH);  // luz
  //Serial.begin(9600);
 
 
 
 
  delay(1000);        // TIEMPO DE ESPERA INICIAL
 
}
 
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 
 
   if (starting){
 
    photocellReading0 = analogRead(photocellPin0);
    photocellReading1 = analogRead(photocellPin1);
    photocellReading2 = analogRead(photocellPin2);
    photocellReading3 = analogRead(photocellPin3);
    photocellReading4 = analogRead(photocellPin4);
 
    delay(2000);        // TIEMPO DE ESPERA INICIAL

    photocellReading0 = analogRead(photocellPin0);
    photocellReading1 = analogRead(photocellPin1);
    photocellReading2 = analogRead(photocellPin2);
    photocellReading3 = analogRead(photocellPin3);
    photocellReading4 = analogRead(photocellPin4);
 
    delay(2000);        // TIEMPO DE ESPERA INICIAL
    
    coinNumber0 = 0;          // moneda 10
    coinPassing0= false;
    coinNumber1 = 0;          // moneda 50
    coinPassing1= false;
    coinNumber2 = 0;          // moneda 100N
    coinPassing2= false;    
    coinNumber3 = 0;          // moneda 500
    coinPassing3= false;
    coinNumber4 = 0;          // moneda 100
    coinPassing4= false;
 
    starting = false;
 
 
 
  }
 
 
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
 
  photocellReading0 = analogRead(photocellPin0);
  photocellReading1 = analogRead(photocellPin1);
  photocellReading2 = analogRead(photocellPin2);
  photocellReading3 = analogRead(photocellPin3);
  photocellReading4 = analogRead(photocellPin4);
 
 
 
 
  if(photocellReading0 >= lightUmbral0){
   
      coinPassing0 = false;
   
  }
 
 
  if(photocellReading0 < lightUmbral0 && !coinPassing0){
 
    coinPassing0 = true;
    coinNumber0++;
 
  }
 
 
  if(photocellReading1 >= lightUmbral1){
   
      coinPassing1 = false;
   
   }
 
 
  if(photocellReading1 < lightUmbral1 && !coinPassing1){
 
    coinPassing1 = true;
    coinNumber1++;
 
  }
 
  if(photocellReading2 >= lightUmbral2){
   
      coinPassing2 = false;
   
   }
 
 
  if(photocellReading2 < lightUmbral2 && !coinPassing2){
 
    coinPassing2 = true;
    coinNumber2++;
 
  }
 
  if(photocellReading3 >= lightUmbral3){
   
      coinPassing3 = false;
   
   }
 
 
  if(photocellReading3 < lightUmbral3 && !coinPassing3){
 
    coinPassing3 = true;
    coinNumber3++;
 
  }
 
 
  if(photocellReading4 >= lightUmbral4){
   
      coinPassing4 = false;
   
   }
 
 
  if(photocellReading4 < lightUmbral4 && !coinPassing4){
 
    coinPassing4 = true;
    coinNumber4++;
 
  }
 
 
 
 
 
 
 
 
  if(debug){
   
   
        // LIMPIAR LCD
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    // end LIMPIAR LCD
 
 
    lcd.setCursor(0, 0); // columna, fila
    lcd.print(photocellReading0);
   
    lcd.setCursor(5, 0); // columna, fila
    lcd.print(photocellReading1);
 
    lcd.setCursor(10, 0); // columna, fila
    lcd.print(photocellReading2);
 
    lcd.setCursor(0, 1); // columna, fila
    lcd.print(photocellReading3);
 
    lcd.setCursor(5, 1); // columna, fila
    lcd.print(photocellReading4);
 
    delay(500);
   
   
  }
 
  else if(!showingCount && millis()%displayTimeMilis<displayTimeMilis/2){
 
    showingCount = true;
     
      // LIMPIAR LCD
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    // end LIMPIAR LCD
 
    lcd.setCursor(0, 0); // columna, fila
    lcd.print("10=");
    lcd.setCursor(3, 0);
    lcd.print(coinNumber0);
   
    lcd.setCursor(8, 0); // columna, fila
    lcd.print("50=");
    lcd.setCursor(11, 0);
    lcd.print(coinNumber2);
 
    lcd.setCursor(0, 1); // columna, fila
    lcd.print("100=");
    lcd.setCursor(4, 1);
    tempNumber100 = coinNumber1+coinNumber4;
    lcd.print(tempNumber100);
 
    lcd.setCursor(8, 1); // columna, fila
    lcd.print("500=");
    lcd.setCursor(12, 1);
    lcd.print(coinNumber3);
     
  } else if(showingCount && millis()%displayTimeMilis>=displayTimeMilis/2){
 
 
 
    showingCount = false;
   
      // LIMPIAR LCD
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    // end LIMPIAR LCD
   
 
    lcd.setCursor(2, 0); // columna, fila
    lcd.print("DINERO TOTAL:");
 
 
 
    tempTotalMoney = (coinNumber0*10)+(coinNumber2*50)+(coinNumber1*100)+(coinNumber3*500)+(coinNumber4*100);
 
    lcd.setCursor(4, 1);
    lcd.print("$");
    lcd.setCursor(5, 1); // columna, fila
    lcd.print(tempTotalMoney);
   
    }
 
 
  //Serial.print("Analog reading = ");
  //Serial.println(photocellReading);
 
    //Serial.print("pin0=");
    //Serial.println(photocellReading0);
    //Serial.print("pin1=");
    //Serial.println(photocellReading1);
    //Serial.print("pin2=");
    //Serial.println(photocellReading2);
    //Serial.print("pin3=");
    //Serial.println(photocellReading3);
    //Serial.print("pin4=");
    //Serial.println(photocellReading4);
   
 // delay(1);
}
