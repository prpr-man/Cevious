#pragma once

#include "Scene.h"

class SceneContext {
public:
        
    enum SCENE {
        OPENING,
        GAME
    };
        
private:
    bool requested;
    SCENE requestedScene;
    static Scene* currentScene;
        
    bool quit;
    
	// ƒVƒ“ƒOƒ‹ƒgƒ“
    SceneContext(void);
    SceneContext(const SceneContext& rhs){}
    SceneContext& operator=(const SceneContext& rhs){}
        
        
public:
    ~SceneContext(void);
    static SceneContext* getInstance(void);
    static Scene* getCurrentScene(void);
        
    void cleanup(void);
        
    void requestChangeScene(SCENE scene);
    void grantRequest(void);
    void requestQuit(void);
    bool isQuit(void);
        
    void initialize(void);
    void shutdown(void);
    void update(void);
    void draw(void);
        
    void keyup(int key);
    void keydown(int key);
};

