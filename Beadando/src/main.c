#include "app.h"

#include <stdio.h>
#include <winuser.h>
/**
 * Main function
 */
int main(int argc, char* argv[])
{
    App app;

    int dwWidth = GetSystemMetrics(SM_CXSCREEN);
    int dwHeight = GetSystemMetrics(SM_CYSCREEN);
    printf("%d   %d \n", dwWidth,dwHeight);

    init_app(&app, dwWidth, dwHeight);
    while (app.is_running) {
        handle_app_events(&app);
        update_app(&app);
        render_app(&app);
    }
    destroy_app(&app);

    return 0;
}
