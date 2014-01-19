#pragma once

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(ID id);
    virtual ~Enemy(void);
        
    virtual void initialize(void);
    virtual void shutdown(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void destroy(void);
    virtual void move(double vx, double vy);
};

