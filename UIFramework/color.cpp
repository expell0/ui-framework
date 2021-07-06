/*
* Implementation for color.h
*/

#include "color.h"

using namespace ui;

Color<uint8_t>::Color( const Color<float> &other )
    : r( static_cast<uint8_t>( other.r * 255 ) )
    , g( static_cast<uint8_t>( other.g * 255 ) )
    , b( static_cast<uint8_t>( other.b * 255 ) )
    , a( static_cast<uint8_t>( other.a * 255 ) )
{
}

Color<float>::Color( const Color<uint8_t> &other )
    : r( static_cast<float>( other.r ) / 255.0f )
    , g( static_cast<float>( other.g ) / 255.0f )
    , b( static_cast<float>( other.b ) / 255.0f )
    , a( static_cast<float>( other.a ) / 255.0f )
{
}