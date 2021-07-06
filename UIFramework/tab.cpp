#include "tab.h"
#include "renderer.h"

using namespace ui;

void Tab::Render( const Point &container_position ) const
{
    for( const std::unique_ptr<BaseElement> &elem : this->elements )
    {
        elem->Render( container_position + this->position );
    }
}

Point Tab::GetNextElementPosition( ) const
{
    int y = 3; //Start with the first element at y = 3
    for( const std::unique_ptr<BaseElement> &elem : this->elements )
    {
        y += elem->GetVerticalPadding( );
    }

    return { 3, y };
}

void Tab::AddCheckbox( const std::string &text, bool &state )
{
    this->elements.push_back( std::make_unique<Checkbox>( Checkbox( this->GetNextElementPosition( ), this->background_color, this->foreground_color, text, state ) ) );
}