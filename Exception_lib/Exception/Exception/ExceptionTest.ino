#include <Exception.h>

Exception myException(Exception::ExceptionType::NotImplementedException);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(myException.GetMessage());
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
