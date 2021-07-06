#pragma once
/*
* Abstract class for tabs to be added to a tab selector
*/

#include <string>
#include <vector>
#include <memory>
#include "base_element.h"
#include "checkbox.h"

namespace ui
{
    class Tab
    {
    public:
        //  Base class constructor for a tab
        //  @param position: The position where the tab's sub elements should be drawn
        //  @param width: The width of the space where the tab's sub elements should be drawn
        //  @param height: The height of the space where the tab's sub elements should be drawn
        //  @param name: The text that will be displayed in the tab selector
        //  @param index: The index of the tab inside a tab selector
        Tab( const Point &position, int width, int height, const std::string &name, const Color<> &background_color, const Color<> &foreground_color, int index )
            : position( position )
            , width( width )
            , height( height )
            , name( name )
            , selected( false )
            , background_color( background_color )
            , foreground_color( foreground_color )
            , index( index )
        {
        }

        virtual ~Tab( )
        {
        }

        inline void Select( ){ this->selected = true; }
        inline void Deselect( ){ this->selected = false; }

        inline const bool &IsSelected( ) const { return this->selected; }
        inline const int &GetIndex( ) const { return this->index; }

        void Render( const Point &container_position ) const;

        void AddCheckbox( const std::string &text, bool &state );

    private:
        Point GetNextElementPosition( ) const;

        Point position;
        int width, height;
        std::string name;
        bool selected;
        const Color<> &background_color;
        const Color<> &foreground_color;
        int index;
        std::vector<std::unique_ptr<BaseElement>> elements;
    };
}