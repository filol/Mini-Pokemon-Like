/* File: spritedentity.cpp
 * Author: Klotz Tom
 */

#include "Concordia_Game/components/spritedentity.hpp"

SpritedEntity::SpritedEntity(sf::Texture const &texture, int spriteX,
                             int spriteY, int spriteW, int spriteH)
    : spriteDimensions(spriteW, spriteH) {
  this->sprite.setTexture(texture);
  configureSpriteRect(spriteX, spriteY, spriteW, spriteH);
}

SpritedEntity::SpritedEntity() {}

void SpritedEntity::configureSpriteRect(int x, int y, int w, int h) {
  this->sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

void SpritedEntity::configureSpriteRect(int x, int y) {
  int w = spriteDimensions.x;
  int h = spriteDimensions.y;
  this->sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

void SpritedEntity::setSpritePosition(sf::Vector2f position) {
  this->sprite.setPosition(position);
}

void SpritedEntity::setSpritePosition(float x, float y) {
  this->sprite.setPosition(x, y);
}

void SpritedEntity::setSpriteScale(float x, float y) {
  this->sprite.setScale(x, y);
}

void SpritedEntity::moveSprite(sf::Vector2f movement) {
  this->sprite.move(movement);
}

void SpritedEntity::setSpriteColor(sf::Color color) {
  this->sprite.setColor(color);
}

sf::Sprite SpritedEntity::getSprite() const { return this->sprite; }

sf::Vector2f SpritedEntity::getSpritePosition() const {
  return this->sprite.getPosition();
}

sf::Vector2i SpritedEntity::getSpriteDimensions() const{
    return this->spriteDimensions;
}

sf::FloatRect SpritedEntity::getSpriteGlobalBounds() const {
  return this->sprite.getGlobalBounds();
}

sf::FloatRect SpritedEntity::getSpriteLocalBounds() const {
  return this->sprite.getLocalBounds();
}
