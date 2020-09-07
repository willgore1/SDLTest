#include <stdio.h>
#include <SDL2/SDL.h>

const int SCR_W = 640;
const int SCR_H = 480;

int main(int argc, char* args[]) {
    SDL_Window *wind = NULL;
    SDL_Surface *surface = NULL;
    
    //initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO ) < 0) {
        printf("Error initializing SDL2: %s\n", SDL_GetError());
    }
    else
    {
        wind = SDL_CreateWindow("SDLTest",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCR_W,SCR_H,SDL_WINDOW_SHOWN);
        if(wind == NULL) {
            printf("Error initializing SDL2 Window: %s\n",SDL_GetError());
        }
        else
        {
            surface = SDL_GetWindowSurface(wind);
            SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0xFF,0xFF,0xFF));
            SDL_UpdateWindowSurface(wind);
            SDL_Delay(2000);
        }
    }

    SDL_DestroyWindow(wind);
    SDL_Quit();
    return 0;
}