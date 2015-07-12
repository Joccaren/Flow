/*+===================================================================
  File:        flow_soundman.cpp

  Summary:     Implmentation of flow_soundman.h

  Author:      Jesse Buhagiar     [Quaker]    31-May-2015

  Rev History:
  31/5/2015: Intial Revision
  5/6/2015:  Made sure slot it nullptr before mapping in audio_mapsound

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#include <audio/flow_soundman.h>
#include <SDL2/SDL_mixer.h>

/*
 * Function:  audio_init
 * --------------------
 *
 *  Initialise the instance of the sound manager.
 *  This does NOT initialise SDL sound, only the mixer!
 */
void FLOW_APICALL Flow_SoundMan::audio_init()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        Debug("Unable to initialise Audio Manager!", FLOW_FATAL);
        std::cout << SDL_GetError() << std::endl;
    }
}

/*
 * Function:  audio_mapsound
 * --------------------
 *
 *  Map a sound to the audio manager
 */
void FLOW_APICALL Flow_SoundMan::audio_mapsound(uint32_t key, Flow_Sound* sound)
{
    //Make sure this slot is actually free first
    if(sounds[key] != nullptr)
    {
        Debug("Attempting to map to slot that is not null. Returning...", FLOW_WARN);
        return;
    }
    sounds[key] = sound;
}

/*
 * Function:  audio_unmapsound
 * --------------------
 *
 *  Attempt to unmap a sound from the audio manager
 */
void FLOW_APICALL Flow_SoundMan::audio_unmapsound(uint32_t key)
{
    sounds[key] = nullptr;
}

/*
 * Function:  audio_play
 * --------------------
 *
 *  Play a sound in this audio manager
 */
void FLOW_APICALL Flow_SoundMan::audio_play(uint32_t key)
{
    Flow_Sound* sound = sounds[key];

    //Make sure this sound actually exists
    if(sound == nullptr)
    {
        Debug("This sound does not exist!", FLOW_WARN);
        return;
    }

    //Check if the sound we're dealing with is music or sfx
    if(sound->isMusic())
    {
        if(!Mix_PlayingMusic())
        {
            Mix_PlayMusic(sound->getMusChunk(), 0);
        }
    }
    else //It's not music! It must be a sound effect!
    {
        Mix_PlayChannel(-1, sound->getSndChunk(), 0);
    }
}
