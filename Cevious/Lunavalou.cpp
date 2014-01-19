#include "Lunavalou.h"
#include "CharacterManager.h"
#include "SceneContext.h"
#include "Zapper.h"

Lunavalou::Lunavalou(void) : Character(Character::LUNAVALOU)
{
}

Lunavalou::~Lunavalou(void)
{
}

void Lunavalou::initialize(void)
{
    speed = 3.0;
    position.x = 400;
    position.y = 500;
    size.x = size.y =32;
    images.push_back(Image("img/lunavalou.png"));
}

void Lunavalou::shutdown(void)
{
}

void Lunavalou::update(void)
{
    std::vector<Character*> characters;
    std::vector<Character*> enemies = checkCollision(ENEMY);
    std::vector<Character*> wepons_enemy = checkCollision(WEPON_ENEMY);
    characters.insert(characters.end(), enemies.begin(), enemies.end());
    characters.insert(characters.end(), wepons_enemy.begin(), wepons_enemy.end());
    
    if(!characters.empty())destroy();
    
    Character::update();
}

void Lunavalou::draw(void)
{
    images[0].draw(position, size);
}

void Lunavalou::destroy(void)
{
    SceneContext::getInstance()->requestChangeScene(SceneContext::OPENING);
}

void Lunavalou::shotZapper(void)
{
    Zapper* zapper = dynamic_cast<Zapper*>(cmanager->create(ZAPPER));
    zapper->setPosition(position);
}

