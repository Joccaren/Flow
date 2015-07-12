/*+===================================================================
  File:        flow_texture.cpp

  Summary:     Implementation of flow_texture.h

  Author:      Jesse Buhagiar     [Quaker]    23-May-2015

  Rev History:
  23/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#include <SDL2/SDL_image.h>
#include <gfx/flow_texture.h>

/*
 * Function:  tex_load
 * --------------------
 *
 *  Load a texture into the SDL texture of the instance of
 *  this class
 */
void FLOW_APICALL Flow_Texture::tex_load(const std::string &path, Flow_Display* disp)
{
    //Check to make sure the texture is actually free first.
    if(tex != nullptr)
    {
        Debug("Texture already loaded for this instance!", FLOW_WARN);
        return; //Get me outta here!
    }

    tex = IMG_LoadTexture(disp->flow_get_hrend(), path.c_str()); //Load the image into our local texture

    //The texture has been loaded! So let's bind it to a rectangle!
    //Should this be in the game object class???
    tex_rect->h = tex_width();
    tex_rect->w = tex_width();
}

/*
 * Function:  tex_render
 * --------------------
 *
 *  Render the texture contained in the instance of this class
 */
void FLOW_APICALL Flow_Texture::tex_render(Flow_Display* disp)
{
    SDL_RenderCopy(disp->flow_get_hrend(), tex, NULL, NULL);
}

/*
 * Function:  tex_width
 * --------------------
 *
 *  Return the width of this texture
 */
uint16_t FLOW_APICALL Flow_Texture::tex_width()
{
    SDL_QueryTexture(tex, NULL, NULL, (int*)&width, NULL);
    return width;
}

/*
 * Function:  tex_height
 * --------------------
 *
 *  Return the height of this texture
 */
uint16_t FLOW_APICALL Flow_Texture::tex_height()
{
    SDL_QueryTexture(tex, NULL, NULL, NULL, (int*)&height);
    return height;
}


/*
 * Function:  get_sdl_tex
 * --------------------
 *
 *  Get the SDL Texture for the instance of this class
 */
SDL_Texture* FLOW_APICALL Flow_Texture::get_sdl_tex()
{
    return tex;
}

/*
 * Function:  tex_lock
 * --------------------
 *
 *  Lock this texture so it can't be modified
 */
void FLOW_APICALL Flow_Texture::tex_lock()
{
    locked = true;
}

/*
 * Function:  tex_unlock
 * --------------------
 *
 *  Unlock this texture
 */
void FLOW_APICALL Flow_Texture::tex_unlock()
{
    locked = false;
}

