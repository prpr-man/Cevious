#pragma once

#include "Character.h"
    
class Zapper : public Character {
public:
    Zapper(void);
    ~Zapper(void);
        
    void initialize(void);
    void shutdown(void);
    void update(void);
    void draw(void);
        
    void setPosition(Vector2 position);
};

