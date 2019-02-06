#include "Tile.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <string>
#include <fstream>
#include <cstring>

using namespace std;
using namespace sf;

class Board {
public:
    Board(int width, int height);
    Board(int width, int height, int testCase);
    bool ClickedOnDebug(int x, int y);
    bool ClickedOnTestOne(int x, int y);
    bool ClickedOnTestTwo(int x, int y);
    bool ClickedOnATile(int x, int y);
    bool ClickedOnFace(int x, int y);
    void HandleLeftClick(int x, int y);
    void HandleRightClick(int x, int y);
    vector<vector<Tile>> GetBoard();
    void SetRandomMines(vector<vector<Tile>> &tiles);
    void SetNeighbors(vector<vector<Tile>> &tiles);
    void DetermineWhichWillHaveNumbers(vector<vector<Tile>> &tiles);
    bool CheckBounds(int x, int y);
    bool gameIsOver();
    bool gameIsWon();
    int GetFlagCount();
    void gameWinCheck();

private:
    vector<vector<Tile>> tileVector;
    int boardWidth;
    int boardHeight;
    bool gameWon;
    bool gameOver;
    int flagCount;

    void search(Tile &tile);
};
