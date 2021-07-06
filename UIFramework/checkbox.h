#pragma once
/*
* Checkbox ui component
*/

#include <string>
#include "base_element.h"

namespace ui
{
    constexpr int checkbox_width = 20;
    constexpr int checkbox_height = 20;

    class Checkbox : public BaseElement
    {
    public:
        Checkbox( Point position, const Color<> &background_color, const Color<> &foreground_color, const std::string &text, bool &state )
            : BaseElement( position, checkbox_width, checkbox_height, background_color, foreground_color, ElementType::CHECKBOX )
            , text( text )
            , state( state )
        {
        }

        void Render( const Point &window_position ) const override;
        void MouseClicked( const Point &mouse_position ) override;
        
    private:
        std::string text;
        bool &state;
    };
}