#include <iostream>
#include <SDL.h>
#include <glad/glad.h>

// glad generator
// https://glad.dav1d.de/
int main(int argc, char** argv) {

    int init_error = SDL_Init(SDL_INIT_VIDEO);
    if (init_error < 0) {
        std::cout << "error SDL_Init()" << std::endl;
        return -1;
    }

    std::cout << "preparing window" << std::endl;

    // before create a window, we specify OpenGL Version and other attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // initiate window
    SDL_Window* window = nullptr;

    int width = 500;
    int height = 450;
    window = SDL_CreateWindow(
        "Happy",
        SDL_WINDOWPOS_UNDEFINED,
        2500,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    // OpenGL graphic context
    SDL_GLContext context;
    // set context to window
    context = SDL_GL_CreateContext(window);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // loop here

    bool isRunning = true;
    while (isRunning) {
        SDL_Event event;
        
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }

            // https://wiki.libsdl.org/SDL_Keycode
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_UP) {
                    std::cout << "UP" << std::endl;
                } else if (event.key.keysym.sym == SDLK_DOWN) {
                    std::cout << "DOWN" << std::endl;
                } else if (event.key.keysym.sym == SDLK_RIGHT) {
                    std::cout << "RIGHT" << std::endl;
                } else if (event.key.keysym.sym == SDLK_LEFT) {
                    std::cout << "LEFT" << std::endl;
                }
            }

            if (event.type == SDL_KEYUP) {
                std::cout << "KEY_RELEASED" << std::endl;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Delay(3000);
    std::cout << "quit window" << std::endl;
    SDL_Quit();

    return 0;
}