#include "Opening.h"
#include "SceneContext.h"
#include "Button.h"

Opening::Opening(void)
{
}

Opening::~Opening(void)
{
}

void Opening::initialize(void)
{
    background.load("img/bg_op.png"); // This image is created by h22i24 Takao Daiki. Thanks!
    
    Button start = Button(START, "img/start_normal.png", "img/start_select.png", 400, 400, 180, 40);
    Button quit = Button(QUIT, "img/quit_normal.png", "img/quit_select.png", 400, 500, 180, 40);
    menu.registerButton(start);
    menu.registerButton(quit);
}

void Opening::shutdown(void)
{
}

void Opening::update(void)
{
    switch(menu.getResult()){
        case START:
            context->requestChangeScene(SceneContext::GAME);
            break;
        case QUIT:
            context->requestQuit();
            break;
    }
}

void Opening::draw(void)
{
    background.draw(400, 300, 800, 600);
    menu.draw();
}

void Opening::keydown(int key)
{
    switch(key){
        case GLFW_KEY_DOWN:
            menu.next();
            break;
        case GLFW_KEY_UP:
            menu.previous();
            break;
        case GLFW_KEY_ENTER:
        case GLFW_KEY_SPACE:
            menu.decide();
            break;
        case GLFW_KEY_ESCAPE:
            context->requestQuit();
            break;
    }
}

void Opening::keyup(int key)
{
}