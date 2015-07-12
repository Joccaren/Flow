/*+===================================================================
  File:        flow_kb.h

  Summary:     Data required to allow keyboard input

  Author:      Jesse Buhagiar     [Quaker]    7-June-2015

  Rev History:
  7/6/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef FLOW_KB_H
#define FLOW_KB_H

#include <API.h>
#include <map>

class Flow_Keyboard
{
    public:
        Flow_Keyboard(SDL_Event* event);

        bool FLOW_APICALL kb_iskeydown(SDL_Keycode key);
        bool FLOW_APICALL kb_iskeyup(SDL_Keycode);

        void FLOW_APICALL kb_update();

    private:
        SDL_Event* event = nullptr;
        std::map<uint8_t, bool> keys;

};



#endif
