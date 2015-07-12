/*+===================================================================
  File:        flow_sound.h

  Summary:     Data required to create a sound chunk/file

  Author:      Jesse Buhagiar     [Quaker]    2-June-2015

  Rev History:
  2/6/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef FLOW_SOUND_H
#define FLOW_SOUND_H

#define FLOW_LOOP 1

#include <API.h>
#include <SDL2/SDL_mixer.h>

class Flow_Sound
{
    public:
        Flow_Sound();

        void FLOW_APICALL load_sound(std::string fname, bool music);

        bool              isMusic();

        Mix_Music*        getMusChunk();
        Mix_Chunk*        getSndChunk();

    private:
        bool music;
        Mix_Music* mus   = nullptr;
        Mix_Chunk* sound = nullptr; //Local sound
};



#endif
