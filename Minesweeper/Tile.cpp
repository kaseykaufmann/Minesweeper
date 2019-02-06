#include "Tile.h"

Tile::Tile() {
    this->beenClicked = false;
    this->isMine = false;
    this->flag = false;
    this->revealed = false;
    this->isNumber = false;
    this-> number = -1;
}

bool Tile::hasMine() {
    return isMine;
}

bool Tile::hasFlagPlaced() {
    return flag;
}

bool Tile::GetBeenClicked() {
    return beenClicked;
}

void Tile::SetHasMine(bool mine) {
    this->isMine = mine;
}

void Tile::SetFlag(bool flag) {
    this->flag = flag;
}

void Tile::SetBeenClicked(bool clicked) {
    this->beenClicked = clicked;
}

void Tile::setNeighbors(vector<Tile *> tilesRound) {
    this->neighbors = tilesRound;
}

vector<Tile *> Tile::GetTilesAround() {
    return neighbors;
}

int Tile::GetNumberOfMinesAround() {
    int number = 0;
    for (int i = 0; i < neighbors.size(); ++i) {
        if (neighbors[i]->hasMine()) {
            ++number;
        }
    }
    return number;
}

void Tile::SetHasNumber(bool number) {
    this->isNumber = number;
}

bool Tile::GetHasNumber() {
    return isNumber;
}

bool Tile::SetRevealed(bool rev) {
    this->revealed = rev;
    return rev;
}

bool Tile::isRevealed() {
    return revealed;
}