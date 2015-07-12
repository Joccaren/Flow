/*+===================================================================
  File:        API.h

  Summary:     Header that all other headers MUST include to be API specific

  Author:      Jesse Buhagiar     [Quaker]    16-May-2015

  Rev History:
  16/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef API_H
#define API_H

//Things that SHOULD be included
#include <iostream>
#include <cstdint>
#include <SDL2/SDL.h>

#ifdef FLOW_DEBUG
    #include <flow_debug.h>
#endif


//Check if we're running Windows or not.
//***Actually, this should probably be included by the game, not engine.***//
#ifdef __WIN32__
    //Include the Windows header file if we are compiling for Windows!
    #include <windows.h>
#endif

//
//  Define function exports!
//
//  Notes:
//      Any function that is to be used OUTSIDE of the engine
//      in a game MUST have a FLOW_APICALL prefix
//
#ifdef BUILD_DLL
    #define FLOW_APICALL __declspec(dllexport)
#else
    #define FLOW_APICALL __declspec(dllimport)
#endif


#endif
