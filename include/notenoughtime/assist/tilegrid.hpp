/* File: tilegrid.hpp
 * Author: Klotz Tom
 */
 //Write commentary ! task
#ifndef TILEGRID_HPP
#define TILEGRID_HPP

// # External
#include <vector>
#include <cmath>

// # Internal
#include "Concordia_Game/assist/tile.hpp"
#include "Concordia_Game/assist/genericgrid.hpp"

struct Unity {
public:
  std::vector<Tile> tiles;
};

class TileGrid : public GenericGrid {
private:
  std::vector<Unity> unities;
  sf::Vector2i checkBoundaries(sf::Vector2i before) const;

public:
  TileGrid();
  TileGrid(int w, int h, int unitySize);
  Unity* getUnity(int x, int y);
  void addTile(Tile tile);
  std::vector<Unity> getUnitiesOnPosition(sf::Vector2f spriteUpperLeft) const;
};

#endif
