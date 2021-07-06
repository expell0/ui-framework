#include <Windows.h>
#include "window.h"

int main( )
{
    ui::Window window{ { 0, 0 }, ui::window_width, ui::window_height, ui::colors::dark_gary, ui::colors::white };
    bool bool1 = false, bool2 = false;
    window.AddTabSelector( );
    while( true )
    {
        window.Render( );
        Sleep( 100 );
    }
}