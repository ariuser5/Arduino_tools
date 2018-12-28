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

class Exception
{
    public:
        static enum _exceptionType {
            NotImplementedException,
            IndexOutOfRangeException,
            OverflowException,
            ArgumentException,
            ArgumetNullException,
            ArgumentOutOfRangeException,
            TimeoutException,
            NewException
        };

        typedef _exceptionType ExceptionType;
        
        //Those should be hidden(private)
        static void (*_behave)();
        static void _defaultBehaviour();
        static bool _initialized;

        //This is public static
        static void SetBehaviour(void(*)());

        Exception();
        Exception(String);
        Exception(_exceptionType);

        void Invoke();

        void SetMessage(String);
        String GetMessage();

    private:
        bool _writable;
        String _message;
        _exceptionType _type;
};

//using Exception::ExceptionType
//typedef Exception::ExceptionType ExceptionType;

#endif

