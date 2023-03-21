#include <Arduino.h>
#include <Wire.h>
#include <INA219_WE.h>

#define I2C_ADDRESS_1 0x40
#define I2C_ADDRESS_2 0x41
INA219_WE ina219_1 = INA219_WE(I2C_ADDRESS_1);
INA219_WE ina219_2 = INA219_WE(I2C_ADDRESS_2);

float current_mA_MCU = 0.0;
float current_mA_BUS = 0.0;
unsigned long myTime;
char buffer[100]={};
const int meascondPin = 32; 


void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(meascondPin, INPUT);

  
  if (!ina219_1.init()) {              //Init INA219 Sensor 1 and 2
    Serial.println("INA219 Sensors not connected!");
  }
  if (!ina219_2.init()) {              //Init INA219 Sensor 1 and 2
    Serial.println("INA219 Sensors not connected!");
  }
  
  ina219_1.setMeasureMode(CONTINUOUS);  //Set INA219 to continous measurment
  ina219_2.setMeasureMode(CONTINUOUS);
  
  Serial.println("INA219 connected and set to continious measurement!");
  Serial.println("Start Measurment!");
}

void loop() {
  // put your main code here, to run repeatedly:
      
      current_mA_MCU = ina219_1.getCurrent_mA();
      current_mA_BUS = ina219_2.getCurrent_mA();
      if(-current_mA_BUS>35.00f){
        
        myTime = millis();
        
        
        sprintf(buffer,"Time:%d MCU:%.2f BUS:%.2f \r\n",myTime,-current_mA_MCU,-current_mA_BUS);
        Serial.print(buffer);
         //Serial.print("Current[mA] BUS: "); Serial.println(-current_mA_BUS);
  
      //Serial.print("Time: ");
      
      //Serial.println(myTime); // prints time since program started

      }
     

     
  

}
