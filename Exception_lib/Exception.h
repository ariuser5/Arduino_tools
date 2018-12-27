#ifndef Exception_h
#define Exception_h

#include "Arduino.h"

class Exception_h
{
	typedef enum ExceptionType{
		NotImplementedException,
		IndexOutOfRangeException,
		OverflowException,
		ArgumentException,
		ArgumetNullException,
		ArgumentOutOfRangeException,
		TimeoutException,
		NewException
	};	
	
	public:
		Exception();
		Exception(char*);
		Exception(ExceptionType);
		
		void Invoke();
		
		void SetMessage(char*);
		char* GetMessage();
	
	private:
		bool _writable;
		char _message[32];
		ExceptionType _type;
}

#endif