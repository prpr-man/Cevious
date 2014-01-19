#pragma once

#include "Scene.h"
#include "Image.h"
#include "Menu.h"
    
class Opening : public Scene {
private:
    Image background;
    Menu menu;
        
    enum {
        START,
        QUIT
    };
        
public:
    Opening(void);
    ~Opening(void);
        
    void initialize(void);
    void shutdown(void);
    void update(void);
    void draw(void);
    void keydown(int key);
    void keyup(int key);
        
};

