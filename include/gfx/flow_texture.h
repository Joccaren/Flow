/*+===================================================================
  File:        flow_texture.h

  Summary:     SDL texture wrapper class

  Author:      Jesse Buhagiar     [Quaker]    23-May-2015

  Rev History:
  23/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef FLOW_TEXTURE_H
#define FLOW_TEXTURE_H

#include <API.h>
#include <gfx/flow_window.h>
#include <flow_debug.h>

class Flow_Texture
{
    public:
        Flow_Texture();

        void         FLOW_APICALL           tex_load(const std::string &path, Flow_Display* disp);
        void         FLOW_APICALL           tex_render(Flow_Display* disp);
        void         FLOW_APICALL           tex_lock();
        void         FLOW_APICALL           tex_unlock();

        uint16_t     FLOW_APICALL           tex_height();
        uint16_t     FLOW_APICALL           tex_width();

        SDL_Texture* FLOW_APICALL           get_sdl_tex();

    private:
        bool            locked;

        uint16_t        width;
        uint16_t        height;

        SDL_Texture*    tex;
        SDL_Rect*       tex_rect;

};


#endif
