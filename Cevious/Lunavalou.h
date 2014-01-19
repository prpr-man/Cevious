#pragma once

#include "Character.h"
    
class Lunavalou : public Character {
public:
    Lunavalou(void);
    ~Lunavalou(void);
        
    void initialize(void);
    void shutdown(void);
    void update(void);
    void draw(void);
    void destroy(void);

    void shotZapper(void);
};


