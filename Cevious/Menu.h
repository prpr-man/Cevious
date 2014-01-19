#pragma once

#include <vector>
#include "Button.h"
    
class Menu {
private :
    std::vector<Button> buttons;
    bool decision;
    int selectedID;
        
public:
    Menu(void);
    ~Menu(void);
        
    void registerButton(const Button& button);
    void draw(void);
        
    void next(void);
    void previous(void);
    void decide(void);
        
    int getResult(void);
};

