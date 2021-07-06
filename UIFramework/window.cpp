/*
* Implementation for window.h
*/

#include <memory>
#include "window.h"
#include "renderer.h"

using namespace ui;

constexpr int elem_orig_x = 3;
constexpr int tab_content_offset_y = 5;

void Window::Render( ) const
{
    renderer::DrawOutlinedRect( this->position, window_width, window_height, this->foreground_color );
    renderer::DrawFilledRect( this->position, window_width, window_height, this->background_color );
    
    for( const std::unique_ptr<BaseElement> &elem : this->elements )
    {
        elem->Render( this->position );
    }
}

Point Window::GetNextElementPosition( ) const
{
    int y = 3; //Start with the first element at y = 3
    for( const std::unique_ptr<BaseElement> &elem : this->elements )
    {
        y += elem->GetVerticalPadding( );
    }

    return { elem_orig_x, y };
}

void Window::AddTabSelector( )
{
    Point selector_position = this->GetNextElementPosition( );
    Point tab_position = selector_position;
    tab_position.y += tab_content_offset_y;
    this->elements.push_back( std::make_unique<TabSelector>( TabSelector( selector_position, this->width - elem_orig_x, 50, tab_position, this->width - elem_orig_x, this->height - 5, this->background_color, this->foreground_color ) ) );
}

void Window::AddCheckbox( const std::string &text, bool &state )
{
    this->elements.push_back( std::make_unique<Checkbox>( Checkbox( this->GetNextElementPosition( ), this->background_color, this->foreground_color, text, state ) ) );
}