#include "CharacterManager.h"
#include "Lunavalou.h"
#include "Zapper.h"
#include "Toroid.h"

CharacterManager::CharacterManager(void)
{
}

CharacterManager::~CharacterManager(void)
{
    shutdown();
}

CharacterManager* CharacterManager::getInstance(void)
{
    static CharacterManager instance;
    return &instance;
}

Character* CharacterManager::create(Character::ID id)
{
    Character* character = NULL;
    switch(id){
        case Character::LUNAVALOU:
            character = new Lunavalou;
            break;
        case Character::ZAPPER:
            character = new Zapper;
            break;
        case Character::TOROID:
            character = new Toroid;
            break;
        default:
            character = new Character(id);
            break;
    }
    
    if(character)
        character->initialize();
    
    request_register.push_back(character);
    return character;
}

void CharacterManager::requestRemove(Character* character)
{
    request_remove.push_back(character);
}

std::vector<Character*> CharacterManager::search(Character::ID id)
{
    std::vector<Character*> result;
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++)
        if((*it)->id == id)result.push_back((*it));
    
    return result;
}

std::vector<Character*> CharacterManager::search(Character::GROUP group)
{
    std::vector<Character*> result;
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++)
        if((*it)->group == group)result.push_back((*it));
    
    return result;
}

void CharacterManager::initialize(void)
{
}

void CharacterManager::shutdown(void)
{
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++){
        (*it)->shutdown();
        delete (*it);
    }
    characters.clear();
    request_register.clear();
    request_remove.clear();
}

void CharacterManager::update(void)
{
    std::vector<Character*>::iterator rit;
    std::vector<Character*>::iterator cit;
    
    // íœ—v‹ˆ—
    for(rit=request_remove.begin(); rit!=request_remove.end(); rit++){
        for(cit=characters.begin(); cit!=characters.end(); cit++){
            if((*cit) == (*rit)){
                (*cit)->shutdown();
                delete (*cit);
                characters.erase(cit);
                break;
            }
        }
    }
    request_remove.clear();
    
    // ’Ç‰Á—v‹ˆ—
    for(rit=request_register.begin(); rit!=request_register.end(); rit++){
        characters.push_back((*rit));
    }
    request_register.clear();
    
    // updateˆ—
    for(cit=characters.begin(); cit!=characters.end(); cit++)
        (*cit)->update();
}

void CharacterManager::draw(void)
{
    std::vector<Character*>::iterator it;
    for(it=characters.begin(); it!=characters.end(); it++)
        (*it)->draw();
}

