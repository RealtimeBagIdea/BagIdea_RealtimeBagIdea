#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include <RealGL.h>
#include <RealRate.h>
#include <SDL_image.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>

using namespace std;

RealRate fps;
RealGL RGL;
float angle = 0.0;
unsigned int tex;

/*struct coordinate
{
    float x,y,z;
    coordinate(float a, float b, float c) : x(a),y(b),z(c){};
};
struct face
{
    int facenum;
    bool four;
    int faces[4];
    face(int facen, int f1, int f2, int f3): facenum(facen)
    {
        faces[0] = f1;
        faces[1] = f2;
        faces[2] = f3;
        four = false;
    }
    face(int facen, int f1, int f2, int f3, int f4): facenum(facen)
    {
        faces[0] = f1;
        faces[1] = f2;
        faces[2] = f3;
        faces[2] = f4;
        four = true;
    }
};

int loadObject(const char* filename)
{
    vector<string*> coord;
    vector<coordinate*> vertex;
    vector<face*> faces;
    vector<coordinate*> normals;
    ifstream in (filename);
    if(!in.is_open())
    {
        cout << "Not Open" <<endl;
        return -1;
    }

    char buf[256];
    while(!in.eof())
    {
        in.getline(c,256);
        coord.push_back(new string(c));
    }
    for(int i = 0; i < coord.size();i++)
    {
        if((*coord[i])[0]=='#')
        {
            continue;
        }
        else if((*coord[i])[0] == 'v' && (*coord[i])[1] == ' ')
        {
            float tmpx,tmpy,tmpz;
            sscanf(coord[i]->c_str(),"v %f %f %f",%tmpx,$tmpy,$tmpz);
            normals.push_back(new coordinate(tmpx.tmpy.tmpz));
        }
        else if((*coord[i])[0] == 'v' && (*coord[i])[1] == 'n')
        {
            float tmpx,tmpy,tmpz;
            sscanf(coord[i]->c_str(),"vn %f %f %f",%tmpx,$tmpy,$tmpz);
            normals.push_back(new coordinate(tmpx.tmpy.tmpz));
        }
        else if((*coord[i])[0] == 'f')
        {
            int a,b,c,d,e;
            if(count(coord[i]->begin(),coord[i]->end(),' ') == 4)
            {
                sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", )
            }
        }

    }







    for(int i =0; i < coord.size();i++)
    {
        delete coord[i];
    }
}*/

void drawRect(float size)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-5);
    glRotatef(angle,1,1,1);

        angle += 1;
    if(angle > 360){angle = 0;};

    glBindTexture(GL_TEXTURE_2D,tex);

    glBegin(GL_QUADS);
    glTexCoord2f(0,1);
    glVertex3f(-size/2,size/2,size/2);

    glTexCoord2f(0,0);
    glVertex3f(-size/2,-size/2,size/2);

    glTexCoord2f(1,0);
    glVertex3f(size/2,-size/2,size/2);

    glTexCoord2f(1,1);
    glVertex3f(size/2,size/2,size/2);

    glEnd();

}

void drawCube(float size)
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-5);
    glRotatef(angle,1,2,1);

    angle += 1;
    if(angle > 360){angle = 0;};

    float difamb[] = {1,0.5,0.3,1};

    glBindTexture(GL_TEXTURE_2D,tex);

    glBegin(GL_QUADS);

    //front
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);
    glNormal3f(0,0,1);
    //glColor3f(1,0,0);
    glTexCoord2f(0,1);
    glVertex3f(-size/2,size/2,size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,-size/2,size/2);
    glTexCoord2f(1,0);
    glVertex3f(size/2,-size/2,size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,size/2,size/2);

    //back
    glNormal3f(0,0,-1);

    glTexCoord2f(0,1);
    glVertex3f(size/2,size/2,-size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,size/2,-size/2);
    glTexCoord2f(1,0);
    glVertex3f(-size/2,-size/2,-size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,-size/2,-size/2);

    //top
    glNormal3f(0,1,0);
    glTexCoord2f(0,1);
    glVertex3f(size/2,size/2,size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,size/2,size/2);
    glTexCoord2f(1,0);
    glVertex3f(-size/2,size/2,-size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,size/2,-size/2);

    //buttom
    glNormal3f(0,-1,0);
    glTexCoord2f(0,1);
    glVertex3f(size/2,-size/2,size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,-size/2,size/2);
    glTexCoord2f(1,0);
    glVertex3f(-size/2,-size/2,-size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,-size/2,-size/2);

    //left
    glNormal3f(-1,0,0);
    glTexCoord2f(0,1);
    glVertex3f(-size/2,size/2,-size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,-size/2,-size/2);
    glTexCoord2f(1,0);
    glVertex3f(-size/2,-size/2,size/2);
    glTexCoord2f(1,1);
    glVertex3f(-size/2,size/2,size/2);

    //right
    glNormal3f(1,0,0);
    glTexCoord2f(0,1);
    glVertex3f(size/2,size/2,-size/2);
    glTexCoord2f(0,0);
    glVertex3f(size/2,-size/2,-size/2);
    glTexCoord2f(1,0);
    glVertex3f(size/2,-size/2,size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,size/2,size/2);
    glEnd();
}

void drawTri()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //glTranslatef(0,0,-0.5);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.6,0.0);

    glColor3f(0.0,1.0,0.0);
    glVertex3f(-0.5f,-0.5f,0.0);

    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.5f,-0.5f,0.0);
    glEnd();


}

int main(int argc, char** argv)
{
    float pos[] = {-4,2,-3,1};
    float dif[] = {3,3,3,3};
    float amb[] = {0.2,0.1,0.2,1.0};

    RGL.Start("Simple GL", 640,480);
    RGL.setLight(GL_LIGHT0,pos,dif,amb);

    tex = RGL.loadTexture("image/logo.bmp");

    bool exit = false;
    SDL_Event e;
    while(!exit)
    {
        fps.start();

        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                exit = true;
            }
        }

        drawCube(1);

        SDL_GL_SwapWindow(RGL.getWindow());

        fps.frameRate(60);
    }

    return 0;
}
