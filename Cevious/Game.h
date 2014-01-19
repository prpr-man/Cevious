#pragma once

#include "Scene.h"
#include "CharacterManager.h"
#include "Lunavalou.h"
#include "Image.h"
    
class Game : public Scene {
    CharacterManager* cmanager;
    Lunavalou* lunavalou;
        
    Image background;
    Vector2 background_pos1;
    Vector2 background_pos2;
    double scroll_speed;
        
    double prevTime;
	Vector2 direction;
        
public:
    Game(void);
    ~Game(void);
        
    void initialize(void);
    void shutdown(void);
    void update(void);
    void draw(void);
        
    void keyup(int key);
    void keydown(int key);
        
    void createEnemy(void);
};


