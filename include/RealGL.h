#ifndef REALGL_H
#define REALGL_H

#include <SDL.h>
#include <string>

using namespace std;

class RealGL
{
    public:
        RealGL();
        void Start(string title,int width, int height);
        void exit();
        void setLight(unsigned int light,float* pos,float* dif,float* amb);
        unsigned int loadTexture(const char* filename);
        SDL_Window* getWindow();
        SDL_GLContext getContext();

    private:
        void initGL();
        SDL_Window* window;
        SDL_GLContext stage3D;
};

#endif // REALGL_H
