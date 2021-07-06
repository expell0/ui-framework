/*
* Implementation for checkbox.h
*/

#include "checkbox.h"
#include "renderer.h"

using namespace ui;

void Checkbox::Render( const Point &container_position ) const
{
    const Point &relative_position = this->position;
    Point draw_position = relative_position + container_position;

    const Color<> &draw_color = ( this->state ? this->foreground_color : this->background_color );
    renderer::DrawFilledRect( draw_position, this->width, this->height, draw_color );
    renderer::DrawString( { draw_position.x + checkbox_width + 5, draw_position.y + 1 }, this->text, colors::white );
}

void Checkbox::MouseClicked( const Point &mouse_position )
{
    this->state = !this->state;
}