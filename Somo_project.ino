# define trigPinF 4
# define echoPinF 5
# define trigPinR 2
# define echoPinR 3
# define trigPinL 6
# define echoPinL 7

# define IR1F 8
# define IR2F 9
# define IR3B 10
# define IR4B 11

# define IN1 27
# define IN2 26
# define IN3 25
# define IN4 33

long durationF, distanceF, durationR, distanceR, durationL, distanceL,  state_IR1F, state_IR2F, state_IR3B, state_IR4B;

void setup() {
  Serial.begin(9600); 
  pinMode(trigPinF, OUTPUT); 
  pinMode(echoPinF, INPUT); 
  pinMode(trigPinR, OUTPUT); 
  pinMode(echoPinR, INPUT); 
  pinMode(trigPinL, OUTPUT); 
  pinMode(echoPinL, INPUT); 
  
  pinMode(IR1F, INPUT);
  pinMode(IR2F, INPUT);
  pinMode(IR3B, INPUT);
  pinMode(IR4B, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  
  state_IR1F = digitalRead(IR1F);
  state_IR2F = digitalRead(IR2F);
  state_IR3B = digitalRead(IR3B);
  state_IR4B = digitalRead(IR4B);
		
  if (state_IR1F == 1 || state_IR2F == 1){
    
    backword();
    delay(500);
  }
  else if (state_IR3B == 1 || state_IR4B == 1){
    forward();
    delay(500);
  }
  
  digitalWrite(trigPinF, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinF, LOW);
  
  durationF = pulseIn(echoPinF, HIGH);
  distanceF = durationF * 0.034 / 2;
  
  
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
	  
  durationR = pulseIn(echoPinR, HIGH);
  distanceR = durationR * 0.034 / 2;

  
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = durationL * 0.034 / 2;

  
  


  if (distanceF <= 100){
    Serial.println("forword");
    forward();
  }
  else if (distanceR <= 100){
    Serial.println("right");
    right();
  }
  else if (distanceL <= 100){
    Serial.println("left");
    left();
  }
  else{
    Serial.print("else");
      for ( ; ; ){
      right();

      state_IR1F = digitalRead(IR1F);
      state_IR2F = digitalRead(IR2F);
      state_IR3B = digitalRead(IR3B);
      state_IR4B = digitalRead(IR4B);


      digitalWrite(trigPinF, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPinF, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPinF, LOW);
	    durationF = pulseIn(echoPinF, HIGH);
      distanceF = durationF * 0.034 / 2;
        
      digitalWrite(trigPinR, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPinR, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPinR, LOW);
	    durationR = pulseIn(echoPinR, HIGH);
      distanceR = durationR * 0.034 / 2;
        
      digitalWrite(trigPinL, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPinL, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPinL, LOW);
	    durationL = pulseIn(echoPinL, HIGH);
      distanceL = durationL * 0.034 / 2;
      
      if( distanceF <=100 || distanceR <= 100 || distanceL <= 100 || state_IR1F == 1 || state_IR2F == 1 || state_IR3B == 1 || state_IR4B == 1){
        break;
      }
    }
  }

}

void forward()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, HIGH);
 
}

void backword()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW);

}

void left()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, HIGH); 

}

void right()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW);

}

void stopp()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, LOW);

}

