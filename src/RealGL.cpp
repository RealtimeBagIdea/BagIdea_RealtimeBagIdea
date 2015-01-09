#include "RealGL.h"
#include <SDL.h>
#include <string>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL_image.h>

RealGL::RealGL()
{
    window = NULL;
    stage3D = NULL;
}

void RealGL::Start(string title,int width, int height)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,1);

    window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_OPENGL);
    stage3D = SDL_GL_CreateContext(window);

    initGL();
}


void RealGL::initGL()
{
    glClearColor( 0.5,0.5,0.5,1 );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45,640/480,1,500);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE,GL_LINEAR);
    glFogf(GL_FOG_START,1);
    glFogf(GL_FOG_END,5);
    float color[] = {0.5,0.5,0.5,0.5};
    glFogfv(GL_FOG_COLOR,color);



    //glLoadIdentity();
}

void RealGL::setLight(unsigned int light,float* pos,float* dif,float* amb)
{
    glLightfv(light,GL_POSITION,pos);
    glLightfv(light,GL_DIFFUSE,dif);
    glLightfv(light,GL_AMBIENT,amb);
}

unsigned int RealGL::loadTexture(const char* filename)
{
    SDL_Surface* image = IMG_Load(filename);
    unsigned int id;
    glGenTextures(1,&id);
    glBindTexture(GL_TEXTURE_2D,id);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->w,image->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,image->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    SDL_FreeSurface(image);
    return id;
}

void RealGL::exit()
{
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_GL_DeleteContext(stage3D);
    stage3D = NULL;

    SDL_Quit();
}

SDL_Window* RealGL::getWindow()
{
    return window;
}

SDL_GLContext RealGL::getContext()
{
    return stage3D;
}

