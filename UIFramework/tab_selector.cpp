/*
* Implementation for tab_selector.h
*/

#include "tab_selector.h"
#include "renderer.h"

using namespace ui;

void TabSelector::Render( const Point &container_position ) const
{
    renderer::DrawFilledRect( this->position, this->width, this->height, this->background_color );
    for( const std::unique_ptr<Tab> &tab : this->tabs )
    {
        Point tab_position = this->position;
        tab_position.x += ( tab->GetIndex( ) ) * this->width / this->tabs.size( );

        if( tab->IsSelected( ) )
        {
            tab->Render( this->position );
        }
    }
}

void TabSelector::AddTab( const std::string &name, int index )
{
    Point tab_position = this->position;
    tab_position.y += tab_selector_padding;

    this->tabs.push_back( std::make_unique<Tab>( this->tab_content_position, this->tab_content_width, this->tab_content_height, name, 
        this->background_color, this->foreground_color, this->next_tab_index ) );

    this->next_tab_index++;
}

void TabSelector::MouseClicked( const Point &mouse_position )
{
}