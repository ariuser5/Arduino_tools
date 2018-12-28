/*
 Name:		Exception.cpp
 Created:	12/28/2018 1:17:48 AM
 Author:	Darius Emanuel
 Editor:	http://www.visualmicro.com
*/

#include "Exception.h"
#include <Arduino.h>

void Exception::_defaultBehaviour()
{
	//Temp
	Serial.println("An exception has occured");
	delay(1000);
}

void Exception::SetBehaviour(void (*f)())
{
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
