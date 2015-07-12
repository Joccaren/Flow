/*+===================================================================
  File:        flow_sound.cpp

  Summary:     Implementation of flow_sound.h

  Author:      Jesse Buhagiar     [Quaker]    2-June-2015

  Rev History:
  2/6/2015: Initial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#include <audio/flow_sound.h>

/*
 * Function:  load_sound
 * --------------------
 *
 *  Load a sound file for the instance of this sound class
 */
void FLOW_APICALL Flow_Sound::load_sound(std::string fname, bool music)
{
    //Is the clip to be loaded music?
    if(music)
    {
        mus = Mix_LoadMUS(fname.c_str());
        music = true;
    }
    else //No, it's a sound effect.
    {
        sound = Mix_LoadWAV(fname.c_str());
    }

    //Check to see whether the sound file has loaded correctly.
    if(sound == nullptr)
    {
        Debug("This sound could not be loaded!", FLOW_WARN);
        return;
    }
}

/*
 * Function:  isMusic
 * --------------------
 *
 *  Returns whether this sound clip is music or not
 */
bool Flow_Sound::isMusic()
{
    return mus;
}

/*
 * Function:  getMusChunk
 * --------------------
 *
 *  Get the music chunk of this sound
 */
Mix_Music* Flow_Sound::getMusChunk()
{
    return mus;
}

/*
 * Function:  getSndChunk
 * --------------------
 *
 *  Get the sound chunk of this sound
 */
Mix_Chunk* Flow_Sound::getSndChunk()
{
    return sound;
}
