#pragma once
/*
* Window element containing sub elements implementing BaseElement
*/

#include <vector>
#include <memory>
#include "base_element.h"
#include "checkbox.h"
#include "tab_selector.h"

namespace ui
{
    constexpr int window_width = 650;
    constexpr int window_height = 450;

    class Window
    {
    public:
        Window( const Point &position, int width, int height, const Color<> &background_color, const Color<> &foreground_color )
            : position( position )
            , width( width )
            , height( height )
            , background_color( background_color )
            , foreground_color( foreground_color )
        {
        }

        //  Render( )
        //  To be called inside a rendering loop
        void Render( ) const;

        virtual void MouseClicked( const Point &mouse_position ) { };
        virtual void MouseReleased( const Point &mouse_position ) { };
        virtual void MouseMoved( const Point &mouse_position ) { };

        void AddTabSelector( );

        //  AddCheckbox( text, state )
        //  @param text: The text that should be rendered next to the checkbox
        //  @param state: A reference to a boolean indicating whether the checkbox is checked or not
        void AddCheckbox( const std::string &text, bool &state );

    private:
        Point GetNextElementPosition( ) const;

        Point position;
        int width, height;
        const Color<> &background_color, &foreground_color;

        std::vector<std::unique_ptr<BaseElement>> elements;
    };
}