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
	_type = ExceptionType.NewEception;
}

Exception::Exception(char* message)
{
	_writable = true;
	_message = message;
	_type = ExceptionType.NewEception;
}

Exception::Exception(ExceptionType exType)
{
	_writable = false;
	_type = ExceptionType.exType;
	
	switch (_type){
		case ExceptionType.NotImplementedException:
			_message = "The Method or Property is not implemented";
		break;
		case ExceptionType.IndexOutOfRangeException:
			_message = "The index is out of range";
		break;
		case ExceptionType.OverflowException:
			_message = "Exceeded array capacity";
		break;
		case ExceptionType.ArgumentException:
			_message = "Invalid argument ";
		break;
		case ExceptionType.ArgumetNullException:
			_message = "One or more function arguments are null";
		break;
		case ExceptionType.ArgumentOutOfRangeException:
			_message = "Number of arguments does not match with the one of the intended function";
		break;
		case ExceptionType.TimeoutException:
			_message = "Timeout exception occured";
		break;
		case ExceptionType.NewException:
			_message = "";
		break;
	}
}

void Invoke()
{
	//throw this onto a universal standard class that receives and manages exceptions
	//This will be called whenever a exception call is being made
	//substitute for "Throw New Exception"
}

void SetMessage(char* message)
{
	if(_writable == true){
		_message = message;
	} else {
		return;
	}
}

char* GetMessage()
{
	return _message;
}
