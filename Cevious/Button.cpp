#include "Button.h"

Button::Button(void) : selected(false)
{
}

Button::Button(int id, std::string normal_filename, std::string select_filename, double x, double y, double width, double height) : selected(false)
{
    set(id, normal_filename, select_filename, x, y, width, height);
}

void Button::set(int id, std::string normal_filename, std::string select_filename, double x, double y, double width, double height)
{
    this->id = id;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    normalImage.load(normal_filename);
    selectImage.load(select_filename);
}

void Button::draw(void)
{
    selected ? selectImage.draw(x, y, width, height) : normalImage.draw(x, y, width, height);
}

void Button::select(void)
{
    selected = true;
}

void Button::unselect(void)
{
    selected = false;
}

int Button::getID(void)
{
    return id;
}