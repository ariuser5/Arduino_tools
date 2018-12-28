/*
 Name:		Exception.h
 Created:	12/28/2018 1:17:48 AM
 Author:	Darius Emanuel
 Editor:	http://www.visualmicro.com
*/

#ifndef _Exception_h
#define _Exception_h

#include "Arduino.h"

// #if defined(ARDUINO) && ARDUINO >= 100
// 	#include "Arduino.h"
// #else
// 	#include "WProgram.h"
// #endif

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
        static void SetBehaviour(void(*f)());

        Exception();
        Exception(String);
        Exception(ExceptionType);

        void Invoke();

        void SetMessage(String);
        String GetMessage();

    private:
        static void (*_behave)();
        static void _defaultBehaviour();

        bool _writable;
        String _message;
        ExceptionType _type;
};

#endif

