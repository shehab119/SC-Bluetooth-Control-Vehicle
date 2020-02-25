const int rightBackward = 2; //R
const int rightForward = 3;  //R
const int leftForward = 4; //L
const int leftBackward = 5; //L
const int trig = 7;
const int echo = 6;
const int buzzer = 8; //Buzzer
const int ledP = 9; //Party LED
const int ledBR = 12; //Head Light 2
const int ledH = 11; //Head Light 1
const int ledH2 = 10; //Head Light 2
const int ledR = 13;//Red LED

const int ldrPin = A0; //LDR 


int duration = 0; //Sonar
int distance = 0; //Sonar

char data = 0;//Bluetooth data



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  
 pinMode(buzzer , OUTPUT);
  pinMode(ledR , OUTPUT);
    pinMode(ledP , OUTPUT);
  pinMode(ledH , OUTPUT);
  pinMode(ledH2 , OUTPUT);
  pinMode(ldrPin, INPUT); 
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//LDR START
int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value

  Serial.println(ldrStatus);
  //check if the LDR status is <= 300
  //if it is, the LED is HIGH
if (ldrStatus >=300) {

    digitalWrite(ledH, HIGH);//turn LED on
    digitalWrite(ledH2, HIGH);
     Serial.println("ON");
   }
  else {

    digitalWrite(ledH, LOW);//turn LED off
    digitalWrite(ledH2, LOW);
  
  }//End of LDR.

//Sonar Start
 digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
//  Serial.println(distance);
  
 


  
//Bluethod 
if(Serial.available() > 0) {
    data = Serial.read();

    Serial.print(data);
    Serial.print("\n");
  }
if(data == 'A'){forward();}
else if(data == 'B'){ right();}
else if(data == 'C'){ left();}
else if(data == 'D'){ backward();}
else if(data == 'E'){ Stop();}

else if(data == 'F'){ ai();}
else if(data == 'G'){ party();}
else if(data == 'H'){ horn();}
else if(data == 'I'){ blk();}

//  Serial.println(data);
}

void blk(){
  digitalWrite(ledH, HIGH);
  digitalWrite(ledH2, HIGH);
  delay(700);
    digitalWrite(ledH, LOW);
  digitalWrite(ledH2, LOW);
  delay(700);

    digitalWrite(ledH, HIGH);
  digitalWrite(ledH2, HIGH);
  delay(700);
    digitalWrite(ledH, LOW);
  digitalWrite(ledH2, LOW);
  delay(700);
data = "";
  
}

void party(){
      digitalWrite(ledP, HIGH);
      
}



void horn(){
  
 tone(buzzer , 100);
 delay (500);
 noTone(buzzer);
 delay(500);
 data = "";
}

void ai(){

 if ( distance <= 20 )
  {
    tone(buzzer , 100);
    digitalWrite(ledR, HIGH);
    
    digitalWrite(leftForward ,  HIGH );
    digitalWrite(leftBackward , LOW  );
    digitalWrite(rightForward , LOW );
    digitalWrite(rightBackward , HIGH);

    
  }
  else
 {
  noTone(buzzer);
  digitalWrite(ledR, LOW);
  
   digitalWrite(leftForward , HIGH);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
  }



  
}





void forward()
{

  if ( distance <= 20 )
  {
    tone(buzzer , 100);
    digitalWrite(ledR, HIGH);
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);
    
  }
  else
 {
noTone(buzzer);
  digitalWrite(ledR, LOW);
 digitalWrite(leftForward , HIGH);
digitalWrite(leftBackward , LOW);
digitalWrite(rightForward , HIGH);
digitalWrite(rightBackward , LOW);
  }
}
void backward()
{
   if ( distance <= 20 )
  {
    tone(buzzer , 100);
    digitalWrite(ledR, HIGH);
    
  }
  else
  {noTone(buzzer);
  digitalWrite(ledR, LOW);
}
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , HIGH); 
   
}
void left()
{
  if ( distance <= 20 )
  {
    tone(buzzer , 100);
    digitalWrite(ledR, HIGH);
    
  }
  else
  {noTone(buzzer);
  digitalWrite(ledR, LOW);
  
}
   digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    
}
void right()
{
  if ( distance <= 20 )
  {
    tone(buzzer , 100);
    digitalWrite(ledR, HIGH);
    
  }
  else
  {
    noTone(buzzer);
  digitalWrite(ledR, LOW);
}


    digitalWrite(leftForward ,  HIGH );
    digitalWrite(leftBackward , LOW  );
    digitalWrite(rightForward , LOW );
    digitalWrite(rightBackward , HIGH);

}
void Stop()
{
      noTone(buzzer);
    digitalWrite(ledR, LOW);
    digitalWrite(leftForward ,  LOW);
    digitalWrite(leftBackward , LOW  );
    digitalWrite(rightForward , LOW );
    digitalWrite(rightBackward , LOW);
     
}
