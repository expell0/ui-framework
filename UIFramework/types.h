#pragma once
/*
* Structs that are not complex enough to require their own file
*/

namespace ui
{
    struct Point
    {
    public:
        Point( int x = 0, int y = 0 )
            : x( x )
            , y( y )
        {
        }

        Point &operator+= ( const Point &other )
        {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        const Point &operator+ ( const Point &other ) const
        {
            Point result = *this;
            result += other;
            return result;
        }

        int x, y;
    };
}