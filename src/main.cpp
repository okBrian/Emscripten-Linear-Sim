#include <iostream>
#include <glad/glad.h>
#include <SDL2/SDL.h>
#ifdef __EMSCRIPTEN__
	#include <emscripten/emscripten.h>
#endif

#define WIN_HEIGHT 1280
#define WIN_WIDTH 720

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);
    return 0;
}

// static void mainloop(void)   /* this will run often, possibly at the monitor's refresh rate */
// {
//     if (!game_is_still_running) {
//         deinitialize_the_game();
//         #ifdef __EMSCRIPTEN__
//         emscripten_cancel_main_loop();  /* this should "kill" the app. */
//         #else
//         exit(0);
//         #endif
//     }

//     check_for_new_input();
//     think_about_stuff();
//     draw_the_next_frame();
// }

// void main(void)
// {
//     initialize_the_game();
//     #ifdef __EMSCRIPTEN__
//     emscripten_set_main_loop(mainloop, 0, 1);
//     #else
//     while (1) { mainloop(); }
//     #endif
// }