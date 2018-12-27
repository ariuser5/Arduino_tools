#ifndef Exception_h
#define Exception_h

#include "Arduino.h"

typedef enum ExceptionType {
	NotImplementedException,
	IndexOutOfRangeException,
	OverflowException,
	ArgumentException,
	ArgumetNullException,
	ArgumentOutOfRangeException,
	TimeoutException,
	NewException
};	

class Exception
{
	public:
		Exception();
		Exception(String);
		Exception(ExceptionType);
		
		void Invoke();
		
		void SetMessage(String);
		String GetMessage();
	
	private:
		bool _writable;
		String _message;
		ExceptionType _type;
};

#endif