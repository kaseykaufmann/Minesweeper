#include "Board.h"

Board::Board(int width, int height, int testCase){
    this->boardWidth = width;
    this->boardHeight = height;
    for (int i = 0; i < width; ++i) {
        vector<Tile> tempVector;
        for (int j = 0; j < height; ++j) {
            Tile Add;
            tempVector.push_back(Add);
        }
        tileVector.push_back(tempVector);
        tempVector.clear();
    }

    flagCount = 50;
    if (testCase == 1) {
        tileVector[0][0].SetHasMine(true);
    } else if (testCase == 2) {

        tileVector[2][2].SetHasMine(true);
        tileVector[3][2].SetHasMine(true);
        tileVector[4][2].SetHasMine(true);
        tileVector[5][2].SetHasMine(true);
        tileVector[6][2].SetHasMine(true);
        tileVector[8][2].SetHasMine(true);
        tileVector[9][2].SetHasMine(true);
        tileVector[10][2].SetHasMine(true);
        tileVector[11][2].SetHasMine(true);
        tileVector[14][2].SetHasMine(true);
        tileVector[15][2].SetHasMine(true);
        tileVector[16][2].SetHasMine(true);
        tileVector[18][2].SetHasMine(true);
        tileVector[19][2].SetHasMine(true);
        tileVector[20][2].SetHasMine(true);
        tileVector[21][2].SetHasMine(true);
        tileVector[22][2].SetHasMine(true);

        tileVector[13][2].SetHasMine(true);
        tileVector[20][2].SetHasMine(true);


        tileVector[4][3].SetHasMine(true);
        tileVector[8][3].SetHasMine(true);
        tileVector[13][3].SetHasMine(true);
        tileVector[20][3].SetHasMine(true);

        tileVector[4][4].SetHasMine(true);
        tileVector[8][4].SetHasMine(true);
        tileVector[9][4].SetHasMine(true);
        tileVector[14][4].SetHasMine(true);
        tileVector[15][4].SetHasMine(true);
        tileVector[20][4].SetHasMine(true);

        tileVector[4][5].SetHasMine(true);
        tileVector[8][5].SetHasMine(true);
        tileVector[16][5].SetHasMine(true);
        tileVector[20][5].SetHasMine(true);

        tileVector[4][6].SetHasMine(true);
        tileVector[8][6].SetHasMine(true);
        tileVector[9][6].SetHasMine(true);
        tileVector[10][6].SetHasMine(true);
        tileVector[11][6].SetHasMine(true);
        tileVector[13][6].SetHasMine(true);
        tileVector[14][6].SetHasMine(true);
        tileVector[15][6].SetHasMine(true);
        tileVector[20][6].SetHasMine(true);

        tileVector[5][8].SetHasMine(true);
        tileVector[6][8].SetHasMine(true);
        tileVector[7][8].SetHasMine(true);
        tileVector[9][8].SetHasMine(true);
        tileVector[13][8].SetHasMine(true);
        tileVector[16][8].SetHasMine(true);
        tileVector[17][8].SetHasMine(true);

        tileVector[6][9].SetHasMine(true);
        tileVector[9][9].SetHasMine(true);
        tileVector[11][9].SetHasMine(true);
        tileVector[13][9].SetHasMine(true);
        tileVector[15][9].SetHasMine(true);
        tileVector[18][9].SetHasMine(true);

        tileVector[6][10].SetHasMine(true);
        tileVector[10][10].SetHasMine(true);
        tileVector[12][10].SetHasMine(true);
        tileVector[15][10].SetHasMine(true);
        tileVector[18][10].SetHasMine(true);

        tileVector[6][11].SetHasMine(true);
        tileVector[10][11].SetHasMine(true);
        tileVector[12][11].SetHasMine(true);
        tileVector[16][11].SetHasMine(true);
        tileVector[17][11].SetHasMine(true);

        tileVector[0][13].SetHasMine(true);
        tileVector[1][13].SetHasMine(true);
        tileVector[2][13].SetHasMine(true);
        tileVector[4][13].SetHasMine(true);
        tileVector[5][13].SetHasMine(true);
        tileVector[6][13].SetHasMine(true);
        tileVector[8][13].SetHasMine(true);
        tileVector[10][13].SetHasMine(true);
        tileVector[12][13].SetHasMine(true);
        tileVector[16][13].SetHasMine(true);
        tileVector[17][13].SetHasMine(true);
        tileVector[19][13].SetHasMine(true);
        tileVector[22][13].SetHasMine(true);

        tileVector[0][14].SetHasMine(true);
        tileVector[2][14].SetHasMine(true);
        tileVector[4][14].SetHasMine(true);
        tileVector[8][14].SetHasMine(true);
        tileVector[10][14].SetHasMine(true);
        tileVector[12][14].SetHasMine(true);
        tileVector[16][14].SetHasMine(true);
        tileVector[19][14].SetHasMine(true);
        tileVector[22][14].SetHasMine(true);

        tileVector[0][15].SetHasMine(true);
        tileVector[1][15].SetHasMine(true);
        tileVector[2][15].SetHasMine(true);
        tileVector[4][15].SetHasMine(true);
        tileVector[5][15].SetHasMine(true);
        tileVector[6][15].SetHasMine(true);
        tileVector[8][15].SetHasMine(true);
        tileVector[10][15].SetHasMine(true);
        tileVector[12][15].SetHasMine(true);
        tileVector[13][15].SetHasMine(true);
        tileVector[14][15].SetHasMine(true);
        tileVector[16][15].SetHasMine(true);
        tileVector[19][15].SetHasMine(true);
    }
    SetNeighbors(tileVector);
    DetermineWhichWillHaveNumbers(tileVector);
    gameOver = false;
    gameWon = false;

}

Board::Board(int width, int height) {
    // Set width and height
    this->boardWidth = width;
    this->boardHeight = height;

    // Initialize an empty tile board
    for (int i = 0; i < width; ++i) {
        vector<Tile> vector1;
        for (int j = 0; j < height; ++j) {
            Tile tile;
            vector1.push_back(tile);
        }
        tileVector.push_back(vector1);
    }

    // fill in the board
    SetRandomMines(tileVector);
    SetNeighbors(tileVector);
    DetermineWhichWillHaveNumbers(tileVector);

    // initialize game parameters
    gameOver = false;
    gameWon = false;
    flagCount = 50;
}

void Board::gameWinCheck() {
    for (int i = 0; i < boardWidth; ++i) {
        for (int j = 0; j < boardHeight; ++j) {
            Tile &tile = tileVector[i][j];
            if (tile.hasMine() || tile.hasFlagPlaced()) {
                continue;
            } else {
                if (tile.number == -1) {
                    return;
                }
            }
        }
    }
    gameOver = true;
    gameWon = true;
    for (int i = 0; i < boardWidth; ++i) {
        for (int j = 0; j < boardHeight; ++j) {
            Tile &tile = tileVector[i][j];
            if (tile.hasMine()) { // if the tile does not have a flag
                tile.SetFlag(true);
                flagCount--;
            }
        }
    }
}


void Board::HandleLeftClick(int x, int y) {
    Tile &tile = tileVector[x][y];
    if (!tile.hasFlagPlaced()) {
        if (tile.hasMine()) {
            tile.SetRevealed(true);
            gameOver = true;
        } else {
            Board::search(tile);
        }
    }
    if (!tile.hasFlagPlaced()) {
        if (tile.hasMine()) {
            tile.SetRevealed(true);
            gameOver = true;
        } else {
            tile.SetBeenClicked(true);
            tile.SetRevealed(true);
        }
    }
    gameWinCheck();
}

void Board::SetRandomMines(vector<vector<Tile>> &tiles) {
    int numOfMines = 0;
    int totalMinesToAdd = 50;
    while (numOfMines < totalMinesToAdd) { // place 50 mines
        int randXCoord = (rand() % boardWidth);
        int randYCoord = (rand() % boardHeight);
        Tile &tile = tiles[randXCoord][randYCoord];
        if (tile.hasMine()) { // search for a tile that does not have a mine already.
            continue;
        } else {
            tile.SetHasMine(true);
            numOfMines++;
        }
    }
}

bool Board::CheckBounds(int x, int y) {
    if (x >= 0 && x <= 24 && y >= 0 && y <= 15) {
        return true;
    } else {
        return false;
    }
}

/**
 * Sets the neighboring tiles to each tile.
 */
void Board::SetNeighbors(vector<vector<Tile>> &tiles) {
    vector<Tile *> neighborTiles;
    for (int i = 0; i <= 24; i++) {
        for (int j = 0; j <= 15; j++) {
            if (CheckBounds(i - 1, j)) {
                neighborTiles.push_back(&tiles[i - 1][j]);
            }
            if (CheckBounds(i - 1, j - 1)) {
                neighborTiles.push_back(&tiles[i - 1][j - 1]);
            }
            if (CheckBounds(i + 1, j)) {
                neighborTiles.push_back(&tiles[i + 1][j]);
            }
            if (CheckBounds(i, j + 1)) {
                neighborTiles.push_back(&tiles[i][j + 1]);
            }
            if (CheckBounds(i + 1, j - 1)) {
                neighborTiles.push_back(&tiles[i + 1][j - 1]);
            }
            if (CheckBounds(i, j - 1)) {
                neighborTiles.push_back(&tiles[i][j - 1]);
            }
            if (CheckBounds(i - 1, j + 1)) {
                neighborTiles.push_back(&tiles[i - 1][j + 1]);
            }
            if (CheckBounds(i + 1, j + 1)) {
                neighborTiles.push_back(&tiles[i + 1][j + 1]);
            }
            tiles[i][j].setNeighbors(neighborTiles);
            neighborTiles.clear();
        }
    }
}

/**
 * Goes through the whole board and checks if a tile has any mines around it AND it is not a mine. If so it sets it as a number.
 * @param tiles game board of tiles.
 */
void Board::DetermineWhichWillHaveNumbers(vector<vector<Tile>> &tiles) {
    for (int i = 0; i < boardWidth; i++) {
        for (int j = 0; j < boardHeight; j++) {
            Tile &tile = tiles[i][j];
            if ((tile.GetNumberOfMinesAround() > 0) && !(tile.hasMine())) {
                tiles[i][j].SetHasNumber(true);
            }
        }
    }
}

void Board::HandleRightClick(int x, int y) {
    Tile &tile = tileVector[x][y];
    if (tile.number != -1) {
        return;
    }
    if (!tile.hasFlagPlaced()) { // if the tile does not have a flag
        if (flagCount == 0) {
            return;
        }
        tile.SetFlag(true);
        flagCount--;
    } else { // if the tile does have a flag
        // remove the flag
        tile.SetFlag(false);
        flagCount++;
    }
    gameWinCheck();
}

void Board::search(Tile &tile) {
    if (tile.number != -1 || tile.hasFlagPlaced() || tile.hasMine()) {
        return;
    }
    tile.SetBeenClicked(true);
    tile.SetRevealed(true);
    tile.number = tile.GetNumberOfMinesAround();
    if (tile.number == 0) {
        vector<Tile *> neighbors = tile.GetTilesAround();
        for (int i = 0; i < neighbors.size(); ++i) {
            Tile *tile = neighbors[i];
            if (tile == nullptr) {
                continue;
            }
            search(*tile);
        }
    }
}

bool Board::ClickedOnATile(int x, int y) {
    if (x >= 0 && x <= 800) {
        if (y >= 0 && y <= 512) {
            return true;
        }
    }
    return false;
}

bool Board::ClickedOnFace(int x, int y) {
    if (x >= 320 && x <= 384) {
        if (y >= 512 && y <= 576) {
            return true;
        }
    }
    return false;
}

bool Board::ClickedOnDebug(int x, int y) {
    if (x >= 512 && x <= 576) {
        if (y >= 512 && y <= 576) {
            return true;
        }
    }
    return false;
}


bool Board::ClickedOnTestOne(int x, int y) {
    if (x >= (18 * 32) && x <= (18 * 32 + 64)) {
        if (y >= 512 && y <= 576) {
            return true;
        }
    }
    return false;
}

bool Board::ClickedOnTestTwo(int x, int y) {
    if (x >= (20 * 32) && x <= (20 * 32 + 64)) {
        if (y >= 512 && y <= 576) {
            return true;
        }
    }
    return false;
}

bool Board::gameIsOver() {
    return gameOver;
}

bool Board::gameIsWon() {
    return gameWon;
}

int Board::GetFlagCount() {
    return flagCount;
}

vector<vector<Tile>> Board::GetBoard() {
    return this->tileVector;
}