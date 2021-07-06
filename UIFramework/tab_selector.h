#pragma once
/*
* UI Element used for selecting tabs
*/

#include <vector>
#include "base_element.h"
#include "tab.h"

namespace ui
{
    constexpr int tab_selector_padding = 10;

    class TabSelector : public BaseElement
    {
    public:
        TabSelector( const Point &position, int width, int height, const Point &tab_position, int tab_width, int tab_height,
            const Color<> &background_color, const Color<> &foreground_color )
            : BaseElement( position, 200, 50, background_color, foreground_color, ElementType::TAB_SELECTOR )
            , tab_content_position( tab_position )
            , tab_content_width( tab_width )
            , tab_content_height( tab_height )
        {
        }

        void Render( const Point &container_position ) const override;
        void MouseClicked( const Point &mouse_position ) override;

        void AddTab( const std::string &name, int index );

    private:
        int next_tab_index = 0;
        Point tab_content_position;
        int tab_content_width, tab_content_height;
        std::vector<std::unique_ptr<Tab>> tabs;
    };
}