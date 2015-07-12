/*+===================================================================
  File:        Vector2f.h

  Summary:     Class required to create a 2-dimensional
               integer vector.

  Author:      Jesse Buhagiar     [Quaker]    31-May-2015

  Rev History:
  31/5/2015: Intial Revision

----------------------------------------------------------------------
  Copyright 2015-2016 Palm Studios, Pty Ltd
===================================================================+*/

#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <API.h>

class Vector2f
{
    public:
        Vector2f();
        Vector2f(float x, float y);

        Vector2f operator+(const Vector2f& vec)
        {
            Vector2f vecr; //Return vector

            vecr.x += this->x;
            vecr.y += this->y;

            return vecr;
        }


    private:
        uint16_t x;
        uint16_t y;
};



#endif
