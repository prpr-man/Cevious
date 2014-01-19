#include "Scene.h"
#include "SceneContext.h"

Scene::Scene(void)
{
    context = SceneContext::getInstance();
}

Scene::~Scene(void)
{
}

void Scene::initialize(void)
{
}

void Scene::shutdown(void)
{
}

void Scene::update(void)
{
}

void Scene::draw(void)
{
}

void Scene::keyup(int key)
{
}

void Scene::keydown(int key)
{
}