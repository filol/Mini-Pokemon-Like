/* File: mob.cpp
* Author:  François Dexemple
*/
#include <iostream>
#include "instance/mob.hpp"


Mob::Mob(sf::Texture const &texture, int spriteX, int spriteY,
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

            goLeft=true;
            lastFacingPosition = DOWN;

        }

        Mob::Mob() : AnimatedEntity::AnimatedEntity() {}

        void Mob::AI(){
          this->control = this->getSpritePosition();
          this->x = control.x;

          if(goLeft==true) {
            facingUp = false;
            facingDown = false;
            facingLeft=true;
            facingRight=false;

            this->movement.x = -2;
            if(this->x<=250)
              goLeft=false;
          }
          if(goLeft==false) {
            facingUp = false;
            facingDown = false;
            facingLeft=false;
            facingRight=true;

            this->movement.x = 2;
            if(this->x>=450)
              goLeft=true;
          }


        }

    void Mob::controlEntity(sf::Keyboard::Key key, bool release) {}

    void Mob::moveCharacter() { moveSprite(movement); }

    void Mob::animate() {
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
    }

    int Mob::myrandom(int a, int b){
        return rand()%(b-a) +a;
    }
