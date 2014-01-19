#include "Zapper.h"
#include "CharacterManager.h"

Zapper::Zapper(void) : Character(ZAPPER, WEPON_LUNAVALOU)
{
}

Zapper::~Zapper(void)
{
}

void Zapper::initialize(void)
{
    size.x = 10;
    size.y = 10;
    speed = 5;
    velocity.y = -speed;
    images.push_back(Image("img/zapper.png"));
}

void Zapper::shutdown(void)
{
}

void Zapper::update(void)
{
	// sin波にそって動きます，敵の動きのアルゴリズムは各自の仕様に任せます．
    std::vector<Character*> enemies = checkCollision(ENEMY);
    if(!enemies.empty()){
		enemies[0]->destroy();
		destroy();
	}
	else if(position.y < 0)
		destroy();
    
    Character::update();
}

void Zapper::draw(void)
{
    images[0].draw(position, size);
}

void Zapper::setPosition(Vector2 position)
{
    this->position = position;
}

