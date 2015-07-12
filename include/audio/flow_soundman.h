/*+===================================================================
  File:        flow_soundman.h

  Summary:     Engine sound manager

  Author:      Jesse Buhagiar     [Quaker]    31-May-2015

  Rev History:
  31/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef FLOW_SOUNDMAN_H
#define FLOW_SOUNDMAN_H

#include <map>
#include <API.h>
#include <audio/flow_sound.h>

class Flow_SoundMan
{
    public:
        void FLOW_APICALL audio_init();
        void FLOW_APICALL audio_mapsound(uint32_t key, Flow_Sound* sound);
        void FLOW_APICALL audio_unmapsound(uint32_t key);

        void FLOW_APICALL audio_play(uint32_t key);

    private:
        std::map<uint32_t, Flow_Sound*> sounds; //TODO: Create Flow sound class

};


#endif
