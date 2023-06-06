const int pinInputThrottle = A0;
const int pinOutputThrottole = 2;

int ConvertRange(int val, int a, int b, int tarA, int tarB);
void setup()
{
  Serial.begin(115200);
  pinMode(pinInputThrottle, INPUT);
  pinMode(pinOutputThrottole, OUTPUT);
}

void loop()
{
  String debugString = "";
  const int rawThrottleValue = analogRead(pinInputThrottle);
  const int outputThrottleValue = ConvertRange(rawThrottleValue, 167, 530, 0, 255);
  analogWrite(pinOutputThrottole, outputThrottleValue);

  debugString += rawThrottleValue;
  debugString += "\t";
  debugString += outputThrottleValue;
  
  Serial.println(debugString);
}

int ConvertRange(int val, int a, int b, int tarA, int tarB)
{
  int res = tarA + (val - a) * (((float)tarB - tarA) / (b - a));
  if (res > tarB) res = tarB;
  else if (res < tarA) res = tarA;
  return res;
}
