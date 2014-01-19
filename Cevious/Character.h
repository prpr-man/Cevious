#pragma once

#include <vector>
#include "Vector2.h"
#include "Image.h"

// include����Əz�Q�Ƃ���̂Ő錾�����D
class CharacterManager;
    
class Character {
public:
    //cf. http://ja.wikipedia.org/wiki/%E3%82%BC%E3%83%93%E3%82%A6%E3%82%B9
    enum ID {
        LUNAVALOU,  // ���@
        ZAPPER,     // �΋�U������
        TOROID,     // �G�@(�g�[���C�h)
        NONE
    };
        
    enum GROUP {
        ENEMY,
        WEPON_LUNAVALOU,    // ���@����̍U��
        WEPON_ENEMY,        // �G�@����̍U��
        NOGROUP
    };
        
protected:
    CharacterManager* cmanager;
        
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    double speed;
        
    std::vector<Image> images;
        
public:
    const ID id;
    const GROUP group;
        
    Character(ID id, GROUP group = NOGROUP);
    virtual ~Character(void);
        
    virtual void initialize(void);
    virtual void shutdown(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void destroy(void);
    virtual void move(double vx, double vy);
	virtual void move(const Vector2& v);
        
    virtual bool checkCollision(const Character* other);
    virtual std::vector<Character*> checkCollision(ID id);
    virtual std::vector<Character*> checkCollision(GROUP group);
        
};


