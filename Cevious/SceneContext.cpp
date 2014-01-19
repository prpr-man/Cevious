#include "SceneContext.h"
#include "Opening.h"
#include "Game.h"

SceneContext::SceneContext(void) : requested(false), requestedScene(OPENING), quit(false)
{
}

SceneContext::~SceneContext(void)
{
    cleanup();
}

SceneContext* SceneContext::getInstance(void)
{
    static SceneContext instance;
    return &instance;
}

Scene* SceneContext::getCurrentScene(void)
{
    return currentScene;
}

void SceneContext::cleanup(void)
{
    if(currentScene){
        currentScene->shutdown();
        delete currentScene;
        currentScene = NULL;
    }
}

void SceneContext::requestChangeScene(SCENE scene)
{
    requested = true;
    requestedScene = scene;
}

void SceneContext::grantRequest(void)
{
    if(!requested)return;
    
    cleanup();
    
    switch(requestedScene){
        case OPENING:
            currentScene = new Opening;
            break;
        case GAME:
            currentScene = new Game;
            break;
        default:
            currentScene = new Scene;
            break;
    }
    
    if(currentScene)
        currentScene->initialize();
    
    requested = false;
}

void SceneContext::requestQuit(void)
{
    quit = true;
}

bool SceneContext::isQuit(void)
{
    return quit;
}

void SceneContext::initialize(void)
{
    if(currentScene)currentScene->initialize();
}

void SceneContext::shutdown(void)
{
    if(currentScene)currentScene->shutdown();
}

void SceneContext::update(void)
{
    if(currentScene)currentScene->update();
}

void SceneContext::draw(void)
{
    if(currentScene)currentScene->draw();
}

void SceneContext::keyup(int key)
{
    if(currentScene)currentScene->keyup(key);
}

void SceneContext::keydown(int key)
{
    if(currentScene)currentScene->keydown(key);
}

Scene* SceneContext::currentScene = NULL;

