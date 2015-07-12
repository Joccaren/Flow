/*+===================================================================
  File:        flow_camera.h

  Summary:     Contains all data required for the game camera
               when the engine is in "RPG" mode (non-VN)

  Author:      Jesse Buhagiar     [Quaker]    24-May-2015

  Rev History:
  24/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef FLOW_CAMERA_H
#define FLOW_CAMERA_H

#include <API.h>
#include <math/Vector2f.h>


class Flow_Camera
{
    public:
        void FLOW_APICALL move_camera(Vector2f vec);

    private:
        uint32_t x;
        uint32_t y;

        int8_t   vel; //Camera velocity VECTOR!!!

};



#endif
