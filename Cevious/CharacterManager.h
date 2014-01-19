#pragma once

#include <vector>
#include "Character.h"
    
class CharacterManager {
private:
	// シングルトン
    CharacterManager(void);
    CharacterManager(CharacterManager& ac){}
    CharacterManager& operator=(const CharacterManager& ac){}
        
    std::vector<Character*> characters;
    std::vector<Character*> request_register;
    std::vector<Character*> request_remove;
        
public:
    ~CharacterManager(void);
    static CharacterManager* getInstance(void);
    
	// ファクトリーメソッド
    Character* create(Character::ID id);
    void requestRemove(Character* character);
        
    std::vector<Character*> search(Character::ID id);
    std::vector<Character*> search(Character::GROUP group);
        
    void initialize(void);
    void shutdown(void);
    void update(void);
    void draw(void);
};
