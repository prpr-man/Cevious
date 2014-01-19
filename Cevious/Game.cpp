#include "Game.h"
#include "SceneContext.h"

Game::Game(void)
{
}

Game::~Game(void)
{
}

void Game::initialize(void)
{
    cmanager = CharacterManager::getInstance();
    lunavalou = dynamic_cast<Lunavalou*>(cmanager->create(Character::LUNAVALOU));
    
	// 画像を交互にスクロールさせて無限ループっぽくしてます．
    background.load("img/stage.png");
    background_pos1.x = background_pos2.x = 400;
    background_pos1.y = 300;
    background_pos2.y = -300;
    scroll_speed = 2;
    
    prevTime = glfwGetTime();
}

void Game::shutdown(void)
{
    cmanager->shutdown();
}

void Game::update(void)
{
    cmanager->update();
    
    background_pos1.y+scroll_speed >= 900 ? background_pos1.y = -300 : background_pos1.y += scroll_speed;
    background_pos2.y+scroll_speed >= 900 ? background_pos2.y = -300 : background_pos2.y += scroll_speed;
    
    createEnemy();
}

void Game::draw(void)
{
    background.draw(background_pos1, Vector2(800, 600));
    background.draw(background_pos2, Vector2(800, 600));
    cmanager->draw();
}

void Game::keydown(int key)
{
    switch(key){
        case GLFW_KEY_RIGHT:
            direction.x += 1.0;
            break;
        case GLFW_KEY_LEFT:
            direction.x += -1.0;
            break;
        case GLFW_KEY_UP:
            direction.y += -1.0;
            break;
        case GLFW_KEY_DOWN:
            direction.y += 1.0;
            break;
        case GLFW_KEY_SPACE:
        case GLFW_KEY_ENTER:
            lunavalou->shotZapper();
            break;
        case GLFW_KEY_ESCAPE:
            context->requestQuit();
            break;
    }

	lunavalou->move(direction);
}

void Game::keyup(int key)
{
	// 実はバグが残ありますが，めんどくさくなったので放置します．
    switch(key){
        case GLFW_KEY_RIGHT:
            direction.x += -1.0;
            break;
        case GLFW_KEY_LEFT:
            direction.x += 1.0;
            break;
        case GLFW_KEY_UP:
            direction.y += 1.0;
            break;
        case GLFW_KEY_DOWN:
            direction.y += -1.0;
            break;
    }

	lunavalou->move(direction);
}

void Game::createEnemy(void)
{
	// 1秒に一回敵を生成してます．
	// glfwGetTime()を直接使っていますが，時間周りの処理を担うTimerクラスを作って制御するべき所です．
    if(glfwGetTime() - prevTime >= 1.0){
        cmanager->create(Character::TOROID);
        prevTime = glfwGetTime();
    }
}

