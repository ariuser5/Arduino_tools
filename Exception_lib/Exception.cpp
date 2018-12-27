/*
	Exception.cpp - Lirary for managing exceptions.
	Created by Darius C. Emauel, Decemeber 27, 2018.
*/

#include "Arduino.h"
#include "Exception.h"

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
	
	switch (_type){
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
	//throw this onto a universal standard class that receives and manages exceptions
	//This will be called whenever a exception call is being made
	//substitute for "Throw New Exception"
}

void Exception::SetMessage(String message)
{
	if(_writable == true){
		_message = message;
	} else {
		return;
	}
}

String Exception::GetMessage()
{
	return _message;
}
