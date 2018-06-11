/* File: secondscene.hpp
 * Author: François Dexemple
 */

#ifndef SECONDSCENE_HPP
#define SECONDSCENE_HPP

#include <iostream>

#include "Concordia_Game/abstract/scene.hpp"
#include "Concordia_Game/components/spritedentity.hpp"

class SecondScene : public Scene {
private:
    //sf::CircleShape shape;
    sf::Texture bgTexture;

    SpritedEntity bg;
public:

    SecondScene(SceneManager *sceneManager);
    SecondScene();

    void start();
    void update();

    void handleEvent(sf::Event event, sf::RenderWindow &screen);
    void drawEntities(sf::RenderWindow &window);

    void doInternalTimedActions();
    void resetTimeHandlers(ClockHandler &clockHandler);

    void onExit();
    void resumeScene();
};

#endif
