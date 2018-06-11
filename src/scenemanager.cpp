/* File: scenemanager.cpp
 * Author: Ines Elkaoukabi
 */

#include "Concordia_Game/concrete/scenemanager.hpp"

#include "Concordia_Game/abstract/scene.hpp"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {
  delete scene;
}
//change current scene and start it
void SceneManager::changeScene(Scene *nextScene) {
  scene->onExit();
  scene = nextScene;
  scene->start();
}


void SceneManager::changeToRuntimeScene(Scene *nextScene) {
  this->lastScene = this->scene;
  this->scene = nextScene;
}

void SceneManager::removeLastScene() { delete lastScene; }

void SceneManager::start() {
  scene->start();
}

void SceneManager::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  scene->handleEvent(event, screen);
}

void SceneManager::update() { scene->update(); }

void SceneManager::drawEntities(sf::RenderWindow &window) {
  scene->drawEntities(window);
}

void SceneManager::doInternalTimedActions() { scene->doInternalTimedActions(); }

void SceneManager::resetTimeHandlers(ClockHandler &clockHandler) {
  scene->resetTimeHandlers(clockHandler);
}

void SceneManager::setLastScene() {
  this->scene = lastScene;
  this->scene->resumeScene();
}

Scene *SceneManager::getScene() const { return this->scene; }

void SceneManager::setScene(Scene *scene){
    this->scene = scene;
    this->scene->start();
}
