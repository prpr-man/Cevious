#pragma once

#include "Image.h"
    
class Button {
private:
    int id;
    Image normalImage;
    Image selectImage;
        
    bool selected;
    double x, y, width, height;
        
public:
    Button(void);
    Button(int id, std::string normal_filename, std::string select_filename, double x, double y, double width, double height);
        
    void set(int id, std::string normal_filename, std::string select_filename, double x, double y, double width, double height);
    void draw(void);
        
    void select(void);
    void unselect(void);
        
    int getID(void);
        
};
