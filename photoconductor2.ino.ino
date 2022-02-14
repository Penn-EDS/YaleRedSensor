#define Output 3
#define Input A0

//
// MH - Feb 14 2022,  update the values to match the VGA monitor from Huiazen
// - Previous values were according to the MacBook pro
// - Values previously programmed were 
// int Max = 163;   // ==> 800mV
// int Min = 86;    // ==> 420mV

int Max = 40; //1023 total bits resolution. Max value for red 
int Min = 25;  //1023 total bits resolution. Max value for red



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(Output, OUTPUT);
digitalWrite(Output,LOW);
pinMode(Input, INPUT);
}

void loop() {
 
digitalWrite(Output,LOW);
Serial.println(analogRead(Input));
//delay(1000);

  while ((analogRead(Input)>=Min) && (analogRead(Input)<=Max)){
    digitalWrite(Output, HIGH);
 //   Serial.println("=31=");
    Serial.println(analogRead(Input));
  }

}
