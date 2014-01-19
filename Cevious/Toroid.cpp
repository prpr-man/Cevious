#include "Toroid.h"
#include <cstdlib>
#include <cmath>

Toroid::Toroid(void) : Enemy(TOROID)
{
}

Toroid::~Toroid(void)
{
}

void Toroid::initialize(void)
{
	// アニメーションのため画像を複数登録してますが，
	// Animationクラスを作成ほうがいいかもしれません．
    images.push_back(Image("img/toroid/1.png"));
    images.push_back(Image("img/toroid/2.png"));
    images.push_back(Image("img/toroid/3.png"));
    images.push_back(Image("img/toroid/4.png"));
    images.push_back(Image("img/toroid/5.png"));
    images.push_back(Image("img/toroid/6.png"));
    images.push_back(Image("img/toroid/7.png"));
    images.push_back(Image("img/toroid/8.png"));
    
    position.y = -10;
    position.x = rand()%800;
    size.x = size.y = 32;
    speed = 4;
    velocity.y = speed;
    
    imageIndex = 0;
    prevTime = glfwGetTime();
}

void Toroid::shutdown(void)
{
}

void Toroid::update(void)
{
    velocity.x = sin(glfwGetTime())*speed;
    Enemy::update();
    
    if(glfwGetTime() - prevTime >= 0.1){
        imageIndex = (++imageIndex%8);
        prevTime = glfwGetTime();
    }
}

void Toroid::draw(void)
{
    images[imageIndex].draw(position, size);
}