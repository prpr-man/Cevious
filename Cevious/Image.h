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
    
	// importはメモリ上に画像を読み込みます．
	// releaseはメモリ上の画像を解放します．
    static void import(std::string filename);
    static void release(std::string filename);
    static void releaseAll(void);
        
    void draw(double x, double y, double width, double height);
    void draw(Vector2 position, Vector2 size);
};


