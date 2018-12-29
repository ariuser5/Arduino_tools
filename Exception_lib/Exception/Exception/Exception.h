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

namespace ExceptionScope {

    namespace Shared {

        struct ExceptionTypeStruct {

            enum exceptionType {
                NotImplementedException,
                IndexOutOfRangeException,
                OverflowException,
                ArgumentException,
                ArgumetNullException,
                ArgumentOutOfRangeException,
                TimeoutException,
                NewException
            };
        };

        typedef ExceptionTypeStruct::exceptionType ExceptionType;
    }
    
    typedef Shared::ExceptionTypeStruct::exceptionType ExceptionType;
    typedef Shared::ExceptionTypeStruct ExceptionEnum;

    class Exception
    {
        public:
            //Those should be hidden(private)
            static void (*_callback)();
            static void _defaultBehaviour();
            static bool _initialized;

            //This is public static
            static void SetBehaviour(void (*)());

            Exception();
            Exception(String);
            Exception(ExceptionType);

            void Invoke();

            void SetMessage(String);
            String GetMessage();

            //SharedMembers* sharedMembers;

            typedef Shared::ExceptionTypeStruct ExceptionEnum; 

        private:
            bool _writable;
            String _message;
            ExceptionType _type;
    };
}

typedef ExceptionScope::Exception Exception;

#endif

