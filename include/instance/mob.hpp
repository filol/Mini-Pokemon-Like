/* File: mob.hpp
 * Author: François Dexemple
 */

#ifndef MOB_HPP
#define MOB_HPP

#include <SFML/Graphics.hpp>

#include "Concordia_Game/components/animatedentity.hpp"
#include "Concordia_Game/components/controlableentity.hpp"
#include "Concordia_Game/components/spritedentity.hpp"
#include "Concordia_Game/concrete/timehandler.hpp"
#include "instance/facingposition.hpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
/*
 * Herited Object from AnimatedEntity(herited from SpritedEntity) and ControlableEntity
 *
 */
class Mob : public AnimatedEntity,public ControlableEntity  {
private:
  sf::Vector2f movement;
  sf::Vector2f control;
  TimeHandler animationTimeHandler;
  FacingPosition lastFacingPosition;

  float x ;
  float y ;
  float goalX;
  float goalY;


  bool goLeft;

  bool facingUp ;
  bool facingDown;
  bool facingLeft ;
  bool facingRight ;

public:
  //Constructor
  Mob(sf::Texture const &texture, int spriteX, int spriteY, int spriteW,
            int spriteH, int animationInitialXPosition, int animationFinalXPosition, int animationInitialYPosition,
            int animationFinalYPosition, int animationFramesPerSeconds);
  Mob();
  //
  void controlEntity(sf::Keyboard::Key key, bool release);
  //
  void moveCharacter();
  void animate();
  void AI();
  int myrandom(int a, int b);
};



#endif
