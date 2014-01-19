#pragma once

#include "Enemy.h"
 
class Toroid : public Enemy {
    double prevTime;
    int imageIndex;
        
public:
    Toroid(void);
    ~Toroid(void);
        
    void initialize(void);
    void shutdown(void);
    void update(void);
    void draw(void);
};

