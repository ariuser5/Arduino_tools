#include <Exception.h>

Exception myException(Exception::ExceptionEnum::NotImplementedException);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(myException.GetMessage());
  myException.Invoke();
}

void loop() {
  // put your main code here, to run repeatedly:
  //myException.Invoke();
}
