#pragma once

// include‚·‚é‚ÆzŠÂQÆ‚·‚é‚Ì‚ÅéŒ¾‚¾‚¯D
class SceneContext;
    
class Scene {
protected:
    SceneContext* context;
        
public:
    Scene(void);
    virtual ~Scene(void);
        
    virtual void initialize(void);
    virtual void shutdown(void);
    virtual void update(void);
    virtual void draw(void);
        
    virtual void keyup(int key);
    virtual void keydown(int key);
};

