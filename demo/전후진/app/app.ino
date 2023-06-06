const int  pinInputDrive = 7;
const int  pinInputReverse = 8;

const int  pinDrive = 9;
const int  pinReverse = 10;

int bMotorDic = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pinInputDrive, INPUT_PULLUP);
  pinMode(pinInputReverse, INPUT_PULLUP);
  pinMode(pinDrive, OUTPUT);
  pinMode(pinReverse, OUTPUT);
}

void loop() {
  String debugString = "";
  if (digitalRead(pinInputDrive) == LOW) bMotorDic = 1;
  else if (digitalRead(pinInputReverse) == LOW) bMotorDic = -1;
  else bMotorDic = 0;
  
  debugString += digitalRead(pinInputDrive);
  debugString += "\t";
  debugString += digitalRead(pinInputReverse);
  debugString += "\t";
  debugString += bMotorDic;
  
  if (bMotorDic == 0) {
    digitalWrite(pinDrive, LOW);
    digitalWrite(pinReverse, LOW);
  }
  if (bMotorDic == 1) {
    digitalWrite(pinDrive, HIGH);
    digitalWrite(pinReverse, LOW);
  }
  if (bMotorDic == -1) {
    digitalWrite(pinDrive, LOW);
    digitalWrite(pinReverse, HIGH);
  }

  Serial.println(debugString);
}
