/*+===================================================================
  File:        flow_texman.h

  Summary:     Contains class for texture manager
               The texture manager handles all game textures
               (and backgrounds) in a std::vector

  Author:      Jesse Buhagiar     [Quaker]    23-May-2015

  Rev History:
  23/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef FLOW_TEXTURE_MANAGER_H
#define FLOW_TEXTURE_MANAGER_H

#include <API.h>
#include <map>
#include <gfx/flow_window.h>
#include <gfx/flow_texture.h>

class Flow_TexMan
{
    public:
        void            FLOW_APICALL map_texture(uint32_t key, Flow_Texture* tex);
        void            FLOW_APICALL unmap_texture(uint32_t key);

        Flow_Texture*   FLOW_APICALL get_texture(uint32_t key);

    private:
        std::map<uint32_t, Flow_Texture*> textures;

};


#endif
