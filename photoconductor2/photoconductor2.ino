#define Output 3
#define Input A0
#define readDelay 7

// MH - Feb 14 2022,  update the values to match the VGA monitor from Huiazen
// - Previous values were according to the MacBook pro
// - Values previously programmed were
// int Max = 163;   // ==> 800mV
// int Min = 86;    // ==> 420mV

int Max = 40; //1023 total bits resolution. Max value for red
int Min = 25; //1023 total bits resolution. Max value for red
int in[10];   //Variable for the A0 value
int s = 0;    //Variable to store the sum of the array
int ave = 0;  //Variable to store ave
int j = 0;    //Variable to iterate readings
int nsum = 10; //Number of samples for average



int sumofarray(int a[],int n){
   int i,sum=0;

    for(i=0; i<n; i++){
         sum+=a[i];
    }

  return sum;
 }

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(200);

pinMode(Output, OUTPUT);
pinMode(Output, OUTPUT);
digitalWrite(readDelay,LOW);
pinMode(Input, INPUT);

Serial.println("Begin");
}

void loop(){
  digitalWrite(readDelay, HIGH);  //Pin HIGH before making Reads
  for(j=0; j<nsum; j++){
    in[j] = analogRead(Input);
  }

  digitalWrite(readDelay, LOW);   //Pin LOW after making analogReads

  s = sumofarray(in,nsum);
  ave = s/nsum;

  Serial.print("Ave is: ");
  Serial.println(ave);

  if((ave <= Max) && (ave >= Min)){
    digitalWrite(Output, HIGH);
    Serial.println("Entered High");
  }
  else{
    digitalWrite(Output,LOW);
    Serial.println("Entered Low");
  }
delay(100);
}
