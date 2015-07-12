/*+===================================================================
  File:        flow_debug.cpp

  Summary:     Implementation of flow_debug.h

  Author:      Jesse Buhagiar     [Quaker]    23-May-2015

  Rev History:
  23/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#include <flow_debug.h>

//Are we running windows??
#ifdef _WIN32
    #include <windows.h>
    void setcol(uint16_t col);
#endif // _WIN32

/*
 * Function:  Debug
 * --------------------
 *
 *  Print a formatted debug message to the system console.
 */
void Debug(std::string message, uint8_t severity)
{
    //Print out what severity the message is
    switch(severity)
    {
        case FLOW_OK:
        {
            setcol(0x0A);
            std::cout << "OK: ";
            break;
        }
        case FLOW_WARN:
        {
            setcol(0x0E);
            std::cout << "WARNING: ";
            break;
        }
        case FLOW_FATAL:
        {
            setcol(0x0C);
            std::cout << "FATAL: ";
            break;
        }
    }

    //Change the colour back to normal
    setcol(0x07);
    std::cout << message << std::endl;
}

/*
 * Function:  setcol
 * --------------------
 *
 *  Print a formatted debug message to the system console.
 */
void setcol(uint16_t col)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

