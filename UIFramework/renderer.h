#pragma once
/*
* Methods used by the framework for rendering, implementation is not provided.
*/

#include <string>
#include "types.h"
#include "color.h"

namespace ui
{
    namespace renderer
    {
        void DrawLine( const Point &pos0, const Point &pos2, const Color<> &color );
        void DrawOutlinedRect( const Point &position, int width, int height, const Color<> &color );
        void DrawFilledRect( const Point &position, int width, int height, const Color<> &color );
        void DrawString( const Point &position, const std::string &text, const Color<> &color );
    }
}