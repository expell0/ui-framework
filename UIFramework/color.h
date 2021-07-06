#pragma once
/*
* Class used for storing colors used in drawing
* Provides templates and conversions for use with "normalized" RGB values (ranging from 0.0 - 1.0) and with bytes (ranging from 0 to 255)
* If not otherwise specified, colors are assumed to use bytes for RGB values
*/

#include <stdint.h>

namespace ui
{
    template<typename T = uint8_t>
    class Color;

    template<>
    class Color<uint8_t>
    {
    public:
        Color( uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255 )
            : r( r )
            , g( g )
            , b( b )
            , a( a )
        {
        }

        Color( const Color<float> &other );

        uint8_t r, g, b, a;
    };

    template<>
    class Color<float>
    {
    public:
        Color( float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f )
            : r( r )
            , g( g )
            , b( b )
            , a( a )
        {
        }

        Color( const Color<uint8_t> &other );

        float r, g, b, a;
    };

    namespace colors
    {
        const Color<> white{ 255, 255, 255 };
        const Color<> black{ 0, 0, 0 };
        const Color<> dark_gray{ 43, 43, 43 };
    }
}