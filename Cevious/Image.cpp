#include "Image.h"
#include <SOIL/SOIL.h>

Image::Image(void)
{
}

Image::Image(std::string filename)
{
    load(filename);
}

Image::~Image(void)
{
}

void Image::import(std::string filename)
{
    if(!pool[filename]){
		// Simple OpenGL Image Librayというライブラリを使用しています．
        GLuint tex = SOIL_load_OGL_texture(filename.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS |SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
        pool[filename] = tex;
    }
}

void Image::release(std::string filename)
{
    if(pool[filename]){
        glDeleteTextures(1, &pool[filename]);
        pool.erase(filename);
    }
}

void Image::releaseAll(void)
{
    std::map<std::string, GLuint>::iterator it;
    for(it=pool.begin(); it!=pool.end(); it++)
        if(it->second)glDeleteTextures(1, &it->second);
    pool.clear();
}

void Image::load(std::string filename)
{
    this->filename = filename;
    import(filename);
    texture = pool[filename];
}


void Image::draw(double x, double y, double width, double height)
{
    if(!pool[filename])return;
    
    glPushMatrix();
    glTranslated(x-width/2.0, y-height/2.0, 0);
    glScaled(width, height, 1);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glBegin( GL_QUADS );
    glTexCoord2d(0.0, 0.0); glVertex2d(0, 1);
    glTexCoord2d(1.0, 0.0); glVertex2d(1, 1);
    glTexCoord2d(1.0, 1.0); glVertex2d(1, 0);
    glTexCoord2d(0.0, 1.0); glVertex2d(0, 0);
    glEnd();
    
    glBindTexture( GL_TEXTURE_2D, 0 );
    glDisable( GL_TEXTURE_2D );
    
    glPopMatrix();
}

void Image::draw(Vector2 position, Vector2 size)
{
    draw(position.x, position.y, size.x, size.y);
}

std::map<std::string, GLuint> Image::pool;


