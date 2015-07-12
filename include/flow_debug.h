/*+===================================================================
  File:        flow_debug.h

  Summary:     Contains definitions for debug functions that can be
               used throughout the program.

  Author:      Jesse Buhagiar     [Quaker]    23-May-2015

  Rev History:
  23/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef FLOW_DEBUG_H
#define FLOW_DEBUG_H

#include <string>
#include <iostream>

//Severity levels
#define FLOW_OK     0
#define FLOW_WARN   1
#define FLOW_FATAL  2

void Debug(std::string message, uint8_t severity);

#endif
