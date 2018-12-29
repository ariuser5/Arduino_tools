/*
 Name:		Exception.cpp
 Created:	12/28/2018 1:17:48 AM
 Author:	Darius Emanuel
 Editor:	http://www.visualmicro.com
*/

#include "Exception.h"

namespace ExceptionScope {
	typedef Exception base;

	bool base::_initialized = false;
    void (*base::_callback)() = base::_defaultBehaviour;

	void base::_defaultBehaviour()
	{
		//Temp
		Serial.println("An exception has occured");
		delay(1000);
	}

	void base::SetBehaviour(void (*f)())
	{
		if(_initialized == false){
			_initialized = true;
		}

		_callback = f;
	}

	base::Exception()
	{
		_writable = true;
		_message = "";
		_type = ExceptionEnum::NewException;
	}

	base::Exception(String message)
	{
		_writable = true;
		_message = message;
		_type = ExceptionEnum::NewException;
	}

	base::Exception(ExceptionType exType)
	{
		_writable = false;
		_type = exType;

		switch (_type) {
		case ExceptionEnum::NotImplementedException:
			_message = "The Method or Property is not implemented";
			break;
		case ExceptionEnum::IndexOutOfRangeException:
			_message = "The index is out of range";
			break;
		case ExceptionEnum::OverflowException:
			_message = "Exceeded array capacity";
			break;
		case ExceptionEnum::ArgumentException:
			_message = "Invalid argument ";
			break;
		case ExceptionEnum::ArgumetNullException:
			_message = "One or more function arguments are null";
			break;
		case ExceptionEnum::ArgumentOutOfRangeException:
			_message = "Number of arguments does not match with the one of the intended function";
			break;
		case ExceptionEnum::TimeoutException:
			_message = "Timeout exception occurred";
			break;
		case ExceptionEnum::NewException:
			_message = "";
			break;
		}
	}

	void base::Invoke()
	{
		if(_initialized == false){
			_callback = _defaultBehaviour;
			_initialized = true;
		}

		_callback();
	}

	void base::SetMessage(String message)
	{
		if (_writable == true) {
			_message = message;
		}
		else {
			return;
		}
	}

	String base::GetMessage()
	{
		return _message;
	}
}