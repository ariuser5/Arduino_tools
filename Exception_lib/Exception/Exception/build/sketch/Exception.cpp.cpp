#include <Arduino.h>
#line 1 "e:\\SourceTree_Projects\\Arduino\\Arduino_tools\\Exception_lib\\Exception\\Exception\\Exception.cpp"
#line 1 "e:\\SourceTree_Projects\\Arduino\\Arduino_tools\\Exception_lib\\Exception\\Exception\\Exception.cpp"
/*
 Name:		Exception.cpp
 Created:	12/28/2018 1:17:48 AM
 Author:	Darius Emanuel
 Editor:	http://www.visualmicro.com
*/

#include "Exception.h"

#line 10 "e:\\SourceTree_Projects\\Arduino\\Arduino_tools\\Exception_lib\\Exception\\Exception\\Exception.cpp"
void _defaultBehaviour();
#line 5 "e:\\SourceTree_Projects\\Arduino\\Arduino_tools\\Exception_lib\\Exception\\Exception\\ExceptionTest.ino"
void setup();
#line 11 "e:\\SourceTree_Projects\\Arduino\\Arduino_tools\\Exception_lib\\Exception\\Exception\\ExceptionTest.ino"
void loop();
#line 10 "e:\\SourceTree_Projects\\Arduino\\Arduino_tools\\Exception_lib\\Exception\\Exception\\Exception.cpp"
void _defaultBehaviour()
{
	//Temp
	Serial.println("An exception has occured");
	delay(1000);
}

void Exception::SetBehaviour(void (*f)())
{
	if(_initialized == false){
		_initialized = true;
	}

	_behave = f;
}

Exception::Exception()
{
	_writable = true;
	_message = "";
	_type = NewException;
}

Exception::Exception(String message)
{
	_writable = true;
	_message = message;
	_type = NewException;
}

Exception::Exception(ExceptionType exType)
{
	_writable = false;
	_type = exType;

	switch (_type) {
	case NotImplementedException:
		_message = "The Method or Property is not implemented";
		break;
	case IndexOutOfRangeException:
		_message = "The index is out of range";
		break;
	case OverflowException:
		_message = "Exceeded array capacity";
		break;
	case ArgumentException:
		_message = "Invalid argument ";
		break;
	case ArgumetNullException:
		_message = "One or more function arguments are null";
		break;
	case ArgumentOutOfRangeException:
		_message = "Number of arguments does not match with the one of the intended function";
		break;
	case TimeoutException:
		_message = "Timeout exception occured";
		break;
	case NewException:
		_message = "";
		break;
	}
}

void Exception::Invoke()
{
	if(Exception::_initialized == false){
		Exception::_behave = _defaultBehaviour;
		Exception::_initialized = true;
	}

	_behave();
}

void Exception::SetMessage(String message)
{
	if (_writable == true) {
		_message = message;
	}
	else {
		return;
	}
}

String Exception::GetMessage()
{
	return _message;
}

#line 1 "e:\\SourceTree_Projects\\Arduino\\Arduino_tools\\Exception_lib\\Exception\\Exception\\ExceptionTest.ino"
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

