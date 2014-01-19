#include "Enemy.h"
#include "CharacterManager.h"

Enemy::Enemy(ID id) : Character(id, ENEMY)
{
}

Enemy::~Enemy(void)
{
}

void Enemy::initialize(void)
{
}

void Enemy::shutdown(void)
{
}

void Enemy::update(void)
{   
    Character::update();
}

void Enemy::draw(void)
{
}

void Enemy::destroy(void)
{
    Character::destroy();
}

void Enemy::move(double vx, double vy)
{
    Character::move(vx, vy);
}