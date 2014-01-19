#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <map>
#include "Vector2.h"

class Image {
private:
    GLuint texture;
    std::string filename;
    
    static std::map<std::string, GLuint> pool;
        
public:
    Image(void);
    Image(std::string filename);
    ~Image(void);
        
    void load(std::string filename);
    
	// import�̓�������ɉ摜��ǂݍ��݂܂��D
	// release�̓�������̉摜��������܂��D
    static void import(std::string filename);
    static void release(std::string filename);
    static void releaseAll(void);
        
    void draw(double x, double y, double width, double height);
    void draw(Vector2 position, Vector2 size);
};


