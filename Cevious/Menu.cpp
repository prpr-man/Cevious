#include "Menu.h"

Menu::Menu(void) : selectedID(0), decision(false)
{
}

Menu::~Menu(void)
{
}

void Menu::registerButton(const Button& button)
{
    buttons.push_back(button);
    buttons.size() > 1 ? buttons[0].select() : buttons[buttons.size()-1].unselect();
}

void Menu::draw(void)
{
    std::vector<Button>::iterator it;
    for(it=buttons.begin(); it!=buttons.end(); it++)
        it->draw();
}

void Menu::next(void)
{
    if(selectedID+1 >= buttons.size())return;
    
    buttons[selectedID].unselect();
    selectedID++;
    buttons[selectedID].select();
}

void Menu::previous(void)
{
    if(selectedID-1 < 0)return;
    
    buttons[selectedID].unselect();
    selectedID--;
    buttons[selectedID].select();
}

void Menu::decide(void)
{
    decision = true;
}

int Menu::getResult(void)
{
    if(!decision)return -1;
    
    return buttons[selectedID].getID();
}