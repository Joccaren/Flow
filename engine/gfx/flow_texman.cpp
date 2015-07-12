/*+===================================================================
  File:        flow_texman.cpp

  Summary:     Implementation of flow_texman

  Author:      Jesse Buhagiar     [Quaker]    23-May-2015

  Rev History:
  23/5/2015: Intial Revision
  29/5/2015: Ability to grab texture added

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#include <gfx/flow_texman.h>

/*
 * Function:  map_texture
 * --------------------
 *
 *  Map a Flow_Texture to this texture manager
 */
void FLOW_APICALL Flow_TexMan::map_texture(uint32_t key, Flow_Texture* tex)
{
    //Make sure this texture isn't already mapped!
    if(textures[key] == tex)
    {
        Debug("This texture is already mapped!", FLOW_WARN);
        return;
    }

    //Nope, we can map!
    textures[key] = tex;
}

/*
 * Function:  map_texture
 * --------------------
 *
 *  Unmap a texture from this texture manager
 */
void FLOW_APICALL Flow_TexMan::unmap_texture(uint32_t key)
{
    //Check to make sure the texture hasn't already been removed
    if(textures[key] == nullptr)
    {
        Debug("No texture to unmap!", FLOW_WARN);
        return;
    }

    //Nope, we can unmap!
    textures[key] = nullptr;
}

/*
 * Function:  get_texture
 * --------------------
 *
 *  Get texture at specific key
 */
Flow_Texture* FLOW_APICALL Flow_TexMan::get_texture(uint32_t key)
{
    //Make sure the texture actually exists!
    if(textures[key] == nullptr)
    {
        Debug("No texture at that key!", FLOW_WARN);
        return nullptr;
    }

    //Nope, we can return this texture
    return textures[key];
}
