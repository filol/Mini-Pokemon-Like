/* File: character.hpp
 * Author:François Dexemple
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>

#include "Concordia_Game/components/animatedentity.hpp"
#include "Concordia_Game/components/controlableentity.hpp"
#include "Concordia_Game/components/spritedentity.hpp"
#include "Concordia_Game/concrete/timehandler.hpp"
#include "instance/facingposition.hpp"
/*
 * Herited Object from AnimatedEntity(herited from SpritedEntity) and ControlableEntity
 *
 */
class Character : public AnimatedEntity, public ControlableEntity {
private:
  sf::Vector2f movement;
  sf::Vector2f control;
  TimeHandler animationTimeHandler;
  FacingPosition lastFacingPosition;

  float x ;
  float y ;
  //NEED TO ADD IT IN THE CONSCTUCTOR
  int const static limiteUp = 0;
  int const static limiteLeft = 0;
  int const static limiteDown = 200;
  int const static limiteRight = 455;

  bool facingUp;
  bool facingDown;
  bool facingLeft;
  bool facingRight;
  bool facingFight;
public:
  //Constructor
  Character(sf::Texture const &texture, int spriteX, int spriteY, int spriteW,
            int spriteH, int animationInitialXPosition, int animationFinalXPosition, int animationInitialYPosition,
            int animationFinalYPosition, int animationFramesPerSeconds);
  Character();
  //
  void controlEntity(sf::Keyboard::Key key, bool release);
  //
  void moveCharacter();
  void animate();
};

#endif
