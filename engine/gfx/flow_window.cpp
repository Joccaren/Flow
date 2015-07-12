/*+===================================================================
  File:        flow_window.cpp

  Summary:     Implementation of flow_window.h

  Author:      Jesse Buhagiar     [Quaker]    18-May-2015

  Rev History:
  18/5/2015: Intial Revision
  23/5/2015: Added a few more functions
  23/5/2015: Created a GL context in flow_init_window();
  24/5/2015: Initialised SDL_image in flow_window_init();

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#include <iostream>
#include <gfx/flow_window.h>
#include <SDL2/SDL_image.h>


/*
 * Function:  flow_window_init
 * --------------------
 *
 *  Initialise a new SDL window.
 *  If this fails, then we return a false return value.
 *  It is here we initialise the SDL_Window and SDL_Surface.
 */
bool FLOW_APICALL Flow_Display::flow_window_init(std::string title, uint16_t width, uint16_t height)
{
    //Check for Video Init fail
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        //TODO: We should create a more verbose debug output function here!
        Debug("Could not initialise video!", FLOW_FATAL);
        std::cout << SDL_GetError() << std::endl;
        return FLOW_SDLVIDINIT_FAIL;
    }

    hwind = SDL_CreateWindow(title.c_str(), 50, 50, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

    //Check for window init failure
    if(hwind == nullptr)
    {
        Debug("Could not initialise window!", FLOW_FATAL);
        std::cout << SDL_GetError() << std::endl;
        return FLOW_SDLVIDINIT_FAIL;
    }

    //Initialise our renderer
    hrend = SDL_CreateRenderer(hwind, -1, SDL_RENDERER_ACCELERATED);

    //If renderer initialisation failed
    if(hrend == nullptr)
    {
        Debug("Could not initialise renderer!", FLOW_FATAL);
        std::cout << SDL_GetError() << std::endl;
        return FLOW_SDLVIDINIT_FAIL;
    }

    //Initialise SDL_image for .png images
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        Debug("Could not initialise image loader!", FLOW_FATAL);
        std::cout << SDL_GetError() << std::endl;
        return FLOW_SDLVIDINIT_FAIL;
    }
    Debug("Window Initialised successfuly!", FLOW_OK);

    return FLOW_SDLVIDINIT_SUCCESS;
}

/*
 * Function:  flow_window_isfscreen
 * --------------------
 *
 *  Returns whether this screen is fulscreen or not
 */
bool FLOW_APICALL Flow_Display::flow_window_isfscreen()
{
    return fullscreen;
}


/*
 * Function:  flow_window_rename
 * --------------------
 *
 *  Rename this window.
 */
void FLOW_APICALL Flow_Display::flow_window_rename(std::string title)
{
    SDL_SetWindowTitle(hwind, title.c_str());
}

/*
 * Function:  flow_window_resize
 * --------------------
 *
 *  Resize this window.
 */
void FLOW_APICALL Flow_Display::flow_window_resize(uint16_t width, uint16_t height)
{
    //Set the window size
    SDL_SetWindowSize(hwind, width, height);
}

/*
 * Function:  flow_window_togglefullscreen
 * --------------------
 *
 *  Toggles this between fullscreen and windowed mode
 */
void FLOW_APICALL Flow_Display::flow_window_toggle_fscreen()
{
    //Check whether the screen is actually in fullscreen mode first
    if(!fullscreen)
        SDL_SetWindowFullscreen(hwind, SDL_WINDOW_FULLSCREEN); //Set to real fullscreen mode
    else
        SDL_SetWindowFullscreen(hwind, 0);
}

/*
 * Function:  flow_window_height
 * --------------------
 *
 *  Get the current height of the window.
 */
uint16_t FLOW_APICALL Flow_Display::flow_window_height()
{
    SDL_GetWindowSize(hwind, NULL, (int*)&height);
    return height;
}

/*
 * Function:  flow_window_width
 * --------------------
 *
 *  Get the current width of the window.
 */
uint16_t FLOW_APICALL Flow_Display::flow_window_width()
{
    SDL_GetWindowSize(hwind, (int*)&width, NULL);
    return width;
}


/*
 * Function:  flow_get_hrend
 * --------------------
 *
 *  Return handle to the renderer
 */
SDL_Renderer* Flow_Display::flow_get_hrend()
{
    return hrend;
}
