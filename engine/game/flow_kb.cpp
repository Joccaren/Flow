/*+===================================================================
  File:        flow_kb.cpp

  Summary:     Implementation of flow_kb.h

  Author:      Jesse Buhagiar     [Quaker]    7-June-2015

  Rev History:
  7/6/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#include <game/flow_kb.h>

//Class constructor
Flow_Keyboard::Flow_Keyboard(SDL_Event* event)
{
    this->event = event;
}

