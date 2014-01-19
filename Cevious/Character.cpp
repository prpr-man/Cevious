#include "Character.h"
#include "CharacterManager.h"

Character::Character(ID id, GROUP group) : id(id), group(group)
{
    cmanager = CharacterManager::getInstance();
}

Character::~Character(void)
{
}

void Character::initialize(void)
{
}

void Character::shutdown(void)
{
}

void Character::update(void)
{
    position += velocity;
}

void Character::draw(void)
{
}

void Character::destroy(void)
{
    cmanager->requestRemove(this);
}

void Character::move(double vx, double vy)
{
    velocity.x = vx;
    velocity.y = vy;
    velocity.normalize();
    velocity *= speed;
}

void Character::move(const Vector2& v)
{
	move(v.x, v.y);
}

bool Character::checkCollision(const Character* other)
{
	// あたり判定はAABBで行うことにしました．
	// 使用に合わせて適宜変更してください．
    Vector2 other_aabb_min = other->position - other->size/2.0;
    Vector2 other_aabb_max = other->position + other->size/2.0;
    Vector2 this_aabb_min = this->position - this->size/2.0;
    Vector2 this_aabb_max = this->position + this->size/2.0;
    
    return  (other_aabb_min.x < this_aabb_max.x && other_aabb_max.x > this_aabb_min.x &&
             other_aabb_min.y < this_aabb_max.y && other_aabb_max.y > this_aabb_min.y);
}

std::vector<Character*> Character::checkCollision(ID id)
{
    std::vector<Character*> characters = cmanager->search(id);
    std::vector<Character*> result;
    
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++)
        if(checkCollision((*it)))result.push_back((*it));
        
    return result;
}

std::vector<Character*> Character::checkCollision(GROUP group)
{
    std::vector<Character*> characters = cmanager->search(group);
    std::vector<Character*> result;
    
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++)
        if(checkCollision((*it)))result.push_back((*it));
    
    return result;
}

