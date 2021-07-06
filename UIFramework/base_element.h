#pragma once
/*
* Abstract class containing required member functions and variables for ui components (checkboxes, buttons, sliders, etc.)
*/

#include "types.h"
#include "color.h"

namespace ui
{
    enum class ElementType : int
    {
        TAB_SELECTOR,
        CHECKBOX
    };

    class BaseElement
    {
    public:
        BaseElement( const Point &position, int width, int height, const Color<> &background_color, const Color<> &foreground_color, ElementType type )
            : position( position )
            , width( width )
            , height( height )
            , background_color( background_color )
            , foreground_color( foreground_color )
            , type( type )
        {
        }

        virtual ~BaseElement( )
        {
        }

        virtual void Render( const Point &container_position ) const { };
        virtual void MouseClicked( const Point &mouse_position ) { };
        virtual void MouseReleased( ) { };
        virtual void MouseMoved( const Point &mouse_position ) { };
        virtual const int &GetVerticalPadding( ) const { return this->height + 5; };

    protected:
        Point position;
        int width, height;
        const Color<> &background_color, &foreground_color;
        const ElementType type;
    };
}