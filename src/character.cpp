/* File: character.cpp
 * Author: François Dexemple
 */
#include <iostream>
#include "instance/character.hpp"


Character::Character(sf::Texture const &texture, int spriteX, int spriteY,
                     int spriteW, int spriteH, int animationInitialXPosition, int animationFinalXPosition,
                     int animationInitialYPosition, int animationFinalYPosition,
                     int animationFramesPerSeconds)
    : AnimatedEntity::AnimatedEntity(
          texture, spriteX, spriteY, spriteW, spriteH, animationInitialXPosition, animationFinalXPosition,
          animationInitialYPosition, animationFinalYPosition, animationFramesPerSeconds) {

  this->movement = sf::Vector2f(0, 0);
  this->control = this->getSpritePosition();
  this->x = control.x;
  this->y = control.y;

  std::cout << x << y << std::endl;
  facingUp = false;
  facingDown = false;
  facingLeft = false;
  facingRight = false;
  facingFight = false;
  lastFacingPosition = DOWN;

}

Character::Character() : AnimatedEntity::AnimatedEntity() {}

void Character::controlEntity(sf::Keyboard::Key key, bool release) {

    switch (key) {
    case sf::Keyboard::Z:
      if (!facingLeft && !facingRight)
        facingUp = !release;

      if (release) {
        lastFacingPosition = UP;
        this->movement.y = 0;
      } else{
        this->control = this->getSpritePosition();
        this->y = control.y;
        this->x = control.x;
        if(this->y<= limiteUp){
            this->setSpritePosition(this->x,limiteUp);
        }
        else
          this->movement.y = -2;

        this->control = this->getSpritePosition();


        std::cout <<"X :"<< this->x  << ",Y:"<< this->y << std::endl;
      }
      break;
    case sf::Keyboard::Q:
      if (!facingUp && !facingDown)
        facingLeft = !release;
      if (release) {
        lastFacingPosition = LEFT;
        this->movement.x = 0;
      } else{
        this->control = this->getSpritePosition();
        this->x = control.x;
        this->y = control.y;
        if(this->x<= limiteLeft){
            this->setSpritePosition(limiteLeft,this->y);
        }
        else
          this->movement.x = -2;

        this->control = this->getSpritePosition();


        std::cout <<"X :"<< this->x  << ",Y:"<< this->y << std::endl;
      }
      break;
    case sf::Keyboard::S:
      if (!facingLeft && !facingRight)
        facingDown = !release;
      if (release) {
        lastFacingPosition = DOWN;
        this->movement.y = 0;
      } else{
        this->control = this->getSpritePosition();
        this->x = control.x;
        this->y = control.y;
        if(this->y >= limiteDown){
             this->setSpritePosition(this->x,limiteDown);
        }
        else
          this->movement.y = 2;

        this->control = this->getSpritePosition();


        std::cout <<"X :"<< this->x  << ",Y:"<< this->y << std::endl;
      }
      break;
    case sf::Keyboard::D:
      if (!facingUp && !facingDown)
        facingRight = !release;
      if (release) {
        lastFacingPosition = RIGHT;
        this->movement.x = 0;
      } else{
        this->control = this->getSpritePosition();
        this->x = control.x;
        this->y = control.y;
        if(this->x >= limiteRight){
             this->setSpritePosition(limiteRight,this->y);
        }
        else
          this->movement.x = 2;

        this->control = this->getSpritePosition();


        std::cout <<"X :"<< this->x  << ",Y:"<< this->y << std::endl;
      }
      break;
      case sf::Keyboard::A:
      lastFacingPosition = FIGHT;
      break;
    }
}

void Character::moveCharacter() { moveSprite(movement); }

void Character::animate() {
  if (this->movement.x == 0.f && this->movement.y == 0.f) {
    switch (lastFacingPosition) {
    case UP:
      configureSpriteRect(0, 260);
      break;
    case DOWN:
      configureSpriteRect(0, 0);
      break;
    case LEFT:
      configureSpriteRect(0, 130);
      break;
    case RIGHT:
      configureSpriteRect(0, 390);
      break;
    case FIGHT:
      configureSpriteRect(0,520);
      break;
    }
  }

  if (facingLeft)
    applyAnimation(1);
  if (facingRight)
    applyAnimation(3);
  if (facingDown)
    applyAnimation(0);
  if (facingUp)
    applyAnimation(2);
  if (facingFight)
    applyAnimation(0);
}
