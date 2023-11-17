// Be creative, my friend
// By: [Professor C] (https://www.youtube.com/@professoor)
// By: [Professor C] (https://github.com/professoorc)
// Developer: [Professor Codenic]

// 1. Labeling the pins of L298
// Explanation: This section is dedicated to labeling the pins of the L298 motor driver.
#define enR 9
#define in1 4
#define in2 5
#define enL 10
#define in3 6
#define in4 7

// 2. Positioning of Infrared Sensors
// Explanation: Describes the proper placement or positioning of infrared sensors.
//*******************************************************
//************************(SM)***************************
//***************(SL1)************(SR1)******************
//*******************************************************
//*******(SL2)****************************(SR2)**********
//*******************************************************

// 3. Labeling Infrared Sensors
// Explanation: This part involves providing labels or identifiers for the infrared sensors.
#define SL2 digitalRead(A1)
#define SL1 digitalRead(A2)
#define SM  digitalRead(A3)
#define SR1 digitalRead(A4)
#define SR2 digitalRead(A5)

void setup() {

// 4. Configuring L298 Pins
// Explanation: In this section, the configuration of pins for the L298 motor driver is set.
  pinMode(enR, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

// 5. Configuring Infrared Sensor Pins
// Explanation: Describes the configuration process for the pins connected to the infrared sensors.
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

    // Set Motor Right forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    // Set Motor Left forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void loop() {

// 6. Conditional Statements for Motor Movement Based on Infrared Sensor Inputs
// Explanation: In this part, conditional statements are used to determine motor movement based on inputs from the infrared sensors.
if(SL2==1 & SL1==1 & SM==0 & SR1==1 & SR2==1)
{
  analogWrite(enR, 96); // Send PWM signal to motor Right
  analogWrite(enL, 96); // Send PWM signal to motor Left
}

if(SL2==1 & SL1==1 & SM==1 & SR1==0 & SR2==1)
{
  analogWrite(enR, 0); // Send PWM signal to motor Right
  analogWrite(enL, 85); // Send PWM signal to motor Left
}

if(SL2==1 & SL1==1 & SM==1 & SR1==1 & SR2==0)
{
  analogWrite(enR, 0); // Send PWM signal to motor Right
  analogWrite(enL, 96); // Send PWM signal to motor Left
}

if(SL2==1 & SL1==0 & SM==1 & SR1==1 & SR2==1)
{
  analogWrite(enR, 85); // Send PWM signal to motor Right
  analogWrite(enL, 0); // Send PWM signal to motor Left
}

if(SL2==0 & SL1==1 & SM==1 & SR1==1 & SR2==1)
{
  analogWrite(enR, 96); // Send PWM signal to motor Right
  analogWrite(enL, 0); // Send PWM signal to motor Left
}

}
