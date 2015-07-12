/*+===================================================================
  File:        flow_window.h

  Summary:     Contains Window Related stuff

  Author:      Jesse Buhagiar     [Quaker]    18-May-2015

  Rev History:
  18/5/2015: Intial Revision
  23/5/2015: Added a few more functions

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef FLOW_WINDOW_H
#define FLOW_WINDOW_H


#include <API.h>

#define FLOW_SDLVIDINIT_FAIL 0
#define FLOW_SDLVIDINIT_SUCCESS 1

//Fallback values for the window
#define SCREEN_WIDTH_FALLBACL 640
#define SCREEN_WIDTH_FALLBACK 480

//
//   Display Class
//
//   Notes:
//       Contains all data required to initialise a Flow Window and draw to it!
//

class Flow_Display
{
    public:
        Flow_Display(); //How the fuck do we export these?
        ~Flow_Display();

        bool            FLOW_APICALL flow_window_init(std::string title, uint16_t width, uint16_t height);
        bool            FLOW_APICALL flow_window_isfscreen();

        void            FLOW_APICALL flow_window_rename(std::string title);
        void            FLOW_APICALL flow_window_resize(uint16_t width, uint16_t height);
        void            FLOW_APICALL flow_window_toggle_fscreen();
        void            FLOW_APICALL flow_window_setdrawcol(uint8_t r, uint8_t g, uint8_t b);

        uint16_t        FLOW_APICALL flow_window_height();
        uint16_t        FLOW_APICALL flow_window_width();

        SDL_Renderer*                flow_get_hrend(); //Shouldn't be used outside of the program

    private:
        bool fullscreen = false;

        uint16_t        width;
        uint16_t        height;


        SDL_Window*     hwind = nullptr; //Initialise this window to a nullptr
        SDL_Surface*    hsurf = nullptr;
        SDL_Renderer*   hrend = nullptr;
        SDL_GLContext*  glcon = nullptr;


};

#endif
