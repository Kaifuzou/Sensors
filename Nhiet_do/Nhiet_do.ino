//NẾU NHIỆT ĐIỆN TRỞ LÀ 10K THÌ CHỌN ĐIỆN TRỞ LÀ 10K

#define THERMISTORPIN 35        // which analog pin to connect
#define THERMISTORNOMINAL 10000   // resistance at 25 degrees C
#define TEMPERARURENOMINAL 25  // temp. for nominal resistance (almost always 25 C)
#define NUMSAMPLES 5  // how many samples to take and average, more takes longer
#define BCOEFFICIENT 3950  // The beta coefficient of the thermistor (usually 3000-4000)
#define SERIESRESISTOR 11000    // the value of the 'other' resistor

float nhietdo;
unsigned long timer = 0;

//=================================================

float TempMearsure()
{
  int i;
  float z=0;
  float tem;
  // take N samples in a row, with a slight delay
  for(i=0; i<NUMSAMPLES; i++)
  {
    z += analogRead(THERMISTORPIN);
    delay(10);
  }
  z /= NUMSAMPLES;  
  tem = (1/((log((11000 / (4095 / (z - 1))) / 10000) / 3950) + (1.0 / (25 + 273.15))) - 273.25)-10 ;
  return(tem);
}

//======================================================

void setup() 
{
  Serial.begin(9600);

}

//======================================================

void loop() 
{
  if(millis() - timer > 1000)
  {
    timer = millis();
    nhietdo = TempMearsure();
   Serial.println(String(nhietdo) + "C");

  }
}
